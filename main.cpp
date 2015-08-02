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
#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include "Common.h"
#include "Uploadapi.h"
#include "Ctietuku.h"
#include "time.h"

void testupapi();
QByteArray hmacSha256(QByteArray key, const QByteArray baseString);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testupapi();
   // QByteArray key;
   // key.append("635d266c31983833e65bc9d3e943c5aafaa8a132");
    //QByteArray message;
   // message.append("eyJkZWFkbGluZSI6MTQzMjY5OTQzMiwiYWlkIjoxLCJmcm9tIjoiZmlsZSJ9");
   // QByteArray bytearry=hmacSha256(key,message);
   // qDebug()<<"Sample hmac:"<<bytearry;

    return a.exec();
}



void testupapi(){
    UpParams params;
    Personal_auth auth;
    Commonfunc func;
    params.stamptime=func.get_timeStamp();
    qDebug()<<"stamptime="<<params.stamptime;
   // params.aid=22470;
    params.aid=1054017;
    params.from="file";

    //Here is your access information.
    auth.accessKey="";
    auth.screctKey="";
    Uploadapi *api=new Uploadapi();
    QString encoded=api->initUpProcess(params,auth);
    api->postQuery(encoded);

}

