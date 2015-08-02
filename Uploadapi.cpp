/*
 * Copyright © 2015 Losywee@gmailcom.
 *
     This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * Authored by: Losywee <Losywee@gmail.com>
 * 
 */
#include "Uploadapi.h"
#include "Ctietuku.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

Uploadapi::Uploadapi(QObject *parent) :
    QObject(parent)
{
    accesser=new QNetworkAccessManager();
    connect(accesser,SIGNAL(finished(QNetworkReply*)),SLOT(readdata(QNetworkReply*)));
    Ctietuku *tietuku=new Ctietuku();
    apimap=tietuku->initMap();
    delete tietuku;
}
UpParams
Uploadapi::getParms(qint64 &stamptime /*Unix timestamp*/,int &aid /*Album ID*/,QString &from){

    UpParams upparm;
    upparm.stamptime=stamptime;
    upparm.aid=aid;
    upparm.from=from;
    return upparm;

}
//Upload
QString
Uploadapi::jsonLize(uploadParams &uploadParms){

    qint64 stamptime=uploadParms.stamptime;
    int aid=uploadParms.aid;
    QString jsoncode = QString("{\"deadline\":%1,\"aid\":%2,\"from\":\"%3\"}").arg(QString::number(stamptime),QString::number(aid),uploadParms.from);
    return jsoncode;

}
//Picture
QString
Uploadapi::jsonLize(PicParams &picParms){

    qint64 stamptime=picParms.stamptime;
    qint8 id=picParms.id;
    QString findurl=picParms.findurl;
    QString action=picParms.action;
    QString jsoncode = QString("{\"deadline\":%1,\"action\":\"%2\",\"id\":%3,\"findurl\":\"%4\"}").arg(QString::number(stamptime),action,QString::number(id),findurl);
    return jsoncode;
}
//List
QString
Uploadapi::jsonLize(ListParams &listParms){

    qint64 stamptime=listParms.stamptime;
    qint8 cid=listParms.cid;
    QString action=listParms.action;
    QString jsoncode = QString("{\"deadline\":%1,\"action\":\"%2\",\"cid\":%3}").arg(QString::number(stamptime),action,QString::number(cid));
    return jsoncode;

}

//Album
QString
Uploadapi::jsonLize(AlbumParams &albumParms){

    qint64 stamptime=albumParms.stamptime;
    qint8 uid=albumParms.uid;
    QString action=albumParms.action;
    qint8 page_no=albumParms.page_no;
    QString jsoncode = QString("{\"deadline\":%1,\"action\":\"%2\",\"uid\":%3,\"page_no\":%4}").arg(QString::number(stamptime),action,QString::number(uid),QString::number(page_no));
    return jsoncode;

}


//Collect
QString
Uploadapi::jsonLize(CollectParams &collectParms){

    qint64 stamptime=collectParms.stamptime;
    QString action=collectParms.action;
    qint8 page_no=collectParms.page_no;
    QString jsoncode = QString("{\"deadline\":%1,\"action\":\"%2\",\"page_no\":%4}").arg(QString::number(stamptime),action,QString::number(page_no));
    return jsoncode;

}


//Catalog
QString
Uploadapi::jsonLize(CatalogParams &catalogParms){

    qint64 stamptime=catalogParms.stamptime;
    QString action=catalogParms.action;
    QString jsoncode = QString("{\"deadline\":%1,\"action\":\"%2\"}").arg(QString::number(stamptime),action);
    return jsoncode;

}


QByteArray
Uploadapi::urlsafeBase64Encode(QString &jsoncode){
    QByteArray ba;
    ba.append(jsoncode);
    ba=ba.toBase64();
    ba.replace('+', '-').replace('/', '_');
    return ba;
}

QString
Uploadapi::hmacSha1Sign(QByteArray &secretKey, QByteArray &encodedParam){
    Commonfunc func;
    QString hmcsha1=func.hmacSha1(secretKey,encodedParam);
    return hmcsha1;
}

QString
Uploadapi::concatParns(QString &AccessKey,QString &encodedSign,QString &encodedParam){

    QString token =QString("%0:%1:%2").arg(AccessKey,encodedSign,encodedParam);
    return token;
}

QString
Uploadapi::initUpProcess(UpParams &params, Personal_auth &auth){


    QByteArray secretkey;
    secretkey.append(auth.screctKey);
    QString accesskey=auth.accessKey;
    qDebug()<<"\n secretkey="<<auth.screctKey;
    qDebug()<<"\n accesskey="<<auth.accessKey;
    UpParams gettheparm=getParms(params.stamptime,params.aid,params.from);
    QString jsonlize=jsonLize(gettheparm);
    qDebug()<<"\n jsonlize="<<jsonlize;
    QByteArray urlencode64=urlsafeBase64Encode(jsonlize); //encodedParam
    qDebug()<<"\n encodedParam="<<urlencode64;
    QString hmasign=hmacSha256(secretkey,urlencode64);
    qDebug()<<"\n sign"<<hmasign;
    QString encodedsign=hmasign; //encodedSign urlsafeBase64Encode(hmasign)
    qDebug()<<"\n encodedSign="<<encodedsign;
    QString urlcode64=urlencode64;
    QString concatparns=concatParns(accesskey,urlcode64,encodedsign);
    qDebug()<<"\n Token="<<concatparns;
    return concatparns;

}

void
Uploadapi::postQuery(QString &token)
{

    QByteArray postData;
    QString tokens="Token=";
    tokens.append(token);
    tokens.append("&fileurl=""");
    qDebug()<<"\n tokens="<<tokens;
    QString url=apimap["uplaod"];
    QUrl Upurl(url);
    QNetworkRequest request(Upurl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "some/type" );
    request.setRawHeader("Last-Modified", "Sun, 06 Nov 1994 08:49:37 GMT");
    postData.append(tokens);
    accesser->post(request,postData);

}
void
Uploadapi::readdata(QNetworkReply *reply){

    QString data=reply->readAll();
    deleteLater();
    qDebug()<<data;

}
Uploadapi::~Uploadapi()
{
    delete accesser;
}
