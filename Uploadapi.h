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
#ifndef UPLOADAPI_H
#define UPLOADAPI_H

#include <Common.h>
#include <QUrl>

//Upload
typedef struct uploadParams{
    qint64 stamptime /*Unix timestamp*/;
    int aid /*Album ID*/;
    QString from;
} UpParams;
//Album
typedef struct albumParams{
    qint64 stamptime /*Unix timestamp*/;
    QString action;
    qint8 uid;//can null
    qint8 page_no;//can null
} AlbumParams;
//List
typedef struct listParams{
    qint64 stamptime /*Unix timestamp*/;
    QString action; // Must be getrandrec
    qint8 cid /*relate catelog*/;
} ListParams;
//Picture
typedef struct picParams{
    qint64 stamptime /*Unix timestamp*/;
    QString action; // Must be getonepic
    qint8 id /*Picture ID*/;
    QString findurl; //Pic find addr
} PicParams;

//Collect
typedef struct collectParams{
    qint64 stamptime /*Unix timestamp*/;
    QString action; // Must be getlovepic
    qint8 page_no /*Page pic 30*/;
} CollectParams;

//Catalog
typedef struct catalogParams{
    qint64 stamptime /*Unix timestamp*/;
    QString action; // Must be getall
} CatalogParams;



class Uploadapi : public QObject,public AbstractApi
{
    Q_OBJECT
public:
    explicit Uploadapi(QObject *parent = 0);
    ~Uploadapi();
    UpParams getParms(qint64 &stamptime /*Unix timestamp*/, int &aid /*Album ID*/, QString &from);
    QString jsonLize(uploadParams &uploadParms); //Upload
    QString jsonLize(AlbumParams &albumParms); //Album
    QString jsonLize(ListParams &listParms); //List
    QString jsonLize(PicParams &picParms); //Picture
    QString jsonLize(CollectParams &collectParms); //Collect
    QString jsonLize(CatalogParams &catalogParms); //Catalog
    QByteArray urlsafeBase64Encode(QString &jsoncode);
    QString hmacSha1Sign(QByteArray &secretKey, QByteArray &encodedParam);
    QString concatParns(QString &AccessKey,QString &encodedSign,QString &encodedParam);
    QString initUpProcess(UpParams &params,Personal_auth &auth);
    void postQuery(QString &token);

protected:
    apiMaps apimap;



signals:

public slots:
    void readdata(QNetworkReply *reply);


};

#endif // UPLOADAPI_H
