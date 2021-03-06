/*  akonadi-kopano
    Copyright (C) 2016 Bo Simonsen, bo@geekworld.dk

    Code based on akonadi airsync download by Martin Koller, kollix@aon.at

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
*/

#include <KJob>

#include <akonadi/resourcebase.h>

#include <mapi.h>
#include <mapiutil.h>

#include <kopano/Util.h>
#include <KMime/Message>

#include <mapi.h>
#include <mapiutil.h>

#include "MapiSession.h"
#include "Utils.h"

class ItemsRemovedJob : public KJob {
  Q_OBJECT

  public:
    ItemsRemovedJob(Akonadi::Item::List const& items, Session* session); 
    ~ItemsRemovedJob();
    void start();
    
    Akonadi::Item::List items;
  private:
    Session* session;

    IMAPIFolder *lpFolder;	

};
