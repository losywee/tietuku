/*
 * Copyright © 2015 Losywee@gmail.com.
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

#ifndef COMMON_H
#define COMMON_H
#include <QString>
#include <QMap>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QCryptographicHash>

typedef struct Personal_auth {
QString accessKey;
QString screctKey;
} authInfo;

typedef QMap<QString,QString> apiMaps;

class AbstractApi{
protected:
    AbstractApi(){}
    QNetworkAccessManager *accesser;
    QByteArray hmacSha256(QByteArray key, const QByteArray baseString){
        int blockSize = 64; // HMAC-SHA-1 block size, defined in SHA-1 standard
            if (key.length() > blockSize) { // if key is longer than block size (64), reduce key length with SHA-1 compression
                key = QCryptographicHash::hash(key, QCryptographicHash::Sha1);
            }

            QByteArray innerPadding(blockSize, char(0x36)); // initialize inner padding with char "6"
            QByteArray outerPadding(blockSize, char(0x5c)); // initialize outer padding with char "\"
            // ascii characters 0x36 ("6") and 0x5c ("\") are selected because they have large
            // Hamming distance (http://en.wikipedia.org/wiki/Hamming_distance)

            for (int i = 0; i < key.length(); i++) {
                innerPadding[i] = innerPadding[i] ^ key.at(i); // XOR operation between every byte in key and innerpadding, of key length
                outerPadding[i] = outerPadding[i] ^ key.at(i); // XOR operation between every byte in key and outerpadding, of key length
            }

            // result = hash ( outerPadding CONCAT hash ( innerPadding CONCAT baseString ) ).toBase64
            QByteArray total = outerPadding;
            QByteArray part = innerPadding;
            part.append(baseString);
            total.append(QCryptographicHash::hash(part, QCryptographicHash::Sha1));
            QByteArray hashed = QCryptographicHash::hash(total, QCryptographicHash::Sha1);
            return hashed.toBase64().replace('+', '-').replace('/', '_');
    }

public:
    virtual QString concatParns(QString &AccessKey,QString &encodedSign,QString &encodedParam)=0;
};



#endif // COMMON_H
