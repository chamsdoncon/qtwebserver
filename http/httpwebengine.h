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
#include "httpresponder.h"
#include "httpresource.h"
#include "misc/threadsafety.h"

// Qt includes
#include <QObject>
#include <QSet>

namespace QtWebServer {

namespace Http {

class WebEngine :
    public QObject,
    public Http::Responder {
    Q_OBJECT
public:
    WebEngine(QObject *parent = 0);

    void respond(const Http::Request& request, Response& response);

    void addResource(Resource *resource);

private:
    Resource *matchResource(QString uniqueResourceIdentifier);

    QMutex _resourcesMutex;
    QSet<Resource*> _resources;
};

}

} // namespace QtWebServer