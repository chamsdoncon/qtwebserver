//
// Copyright 2010-2015 Jacob Dawid <jacob@omg-it.works>
//
// This file is part of QtWebServer.
//
// QtWebServer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// QtWebServer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with QtWebServer.  If not, see <http://www.gnu.org/licenses/>.
//

#pragma once

// Own includes
#include "http/httpresource.h"

// Qt includes
#include <QMap>
#include <QMimeDatabase>

namespace QtWebServer {

namespace Util {

class AssetsResource :
    public Http::Resource {
    Q_OBJECT
public:
    AssetsResource(QObject *parent = 0);
    ~AssetsResource();

    void addAsset(QString id, QString assetPath);

    void respond(const Http::Request& request,
                 Http::Response& response);
private:
    QMap<QString, QString> _assetsPathMap;
    QMimeDatabase _mimeDatabase;
};

} // namespace Util

} // namespace QtWebServer