/*
**********************************************************************************
**
** This file was created for LibreCAD (https://github.com/LibreCAD/LibreCAD).
**
** Copyright (C) 2016 ravas (https://github.com/r-a-v-a-s)
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
** http://www.gnu.org/licenses/gpl-2.0.html
**
**********************************************************************************
*/

#include "lc_actiongroupmanager.h"

#include <QActionGroup>

LC_ActionGroupManager::LC_ActionGroupManager(QObject* parent)
    : QObject(parent)
    , block(new QActionGroup(this))
    , circle(new QActionGroup(this))
    , curve(new QActionGroup(this))
    , edit(new QActionGroup(this))
    , ellipse(new QActionGroup(this))
    , file(new QActionGroup(this))
    , dimension(new QActionGroup(this))
    , info(new QActionGroup(this))
    , layer(new QActionGroup(this))
    , line(new QActionGroup(this))
    , modify(new QActionGroup(this))
    , options(new QActionGroup(this))
    , other(new QActionGroup(this))
    , polyline(new QActionGroup(this))
    , select(new QActionGroup(this))
    , snap(new QActionGroup(this))
    , view(new QActionGroup(this))
    , widgets(new QActionGroup(this))
{
    block->setObjectName(QObject::tr("Block"));
    circle->setObjectName(QObject::tr("Circle"));
    curve->setObjectName(QObject::tr("Curve"));
    edit->setObjectName(QObject::tr("Edit"));
    ellipse->setObjectName(QObject::tr("Ellipse"));
    file->setObjectName(QObject::tr("File"));
    dimension->setObjectName(QObject::tr("Dimension"));
    info->setObjectName(QObject::tr("Info"));
    layer->setObjectName(QObject::tr("Layer"));
    line->setObjectName(QObject::tr("Line"));
    modify->setObjectName(QObject::tr("Modify"));
    options->setObjectName(QObject::tr("Options"));
    other->setObjectName(QObject::tr("Other"));
    polyline->setObjectName(QObject::tr("Polyline"));
    select->setObjectName(QObject::tr("Select"));
    snap->setObjectName(QObject::tr("Snap"));
    view->setObjectName(QObject::tr("View"));
    widgets->setObjectName(QObject::tr("Widgets"));

    foreach (auto ag, findChildren<QActionGroup*>())
    {
        ag->setExclusive(false);
        if (ag->objectName() != QObject::tr("File"))
        {
            connect(parent, SIGNAL(windowsChanged(bool)),
                    ag, SLOT(setEnabled(bool)));
        }
    }

    foreach (auto ag, toolGroups())
    {
        connect(ag, SIGNAL(triggered(QAction*)),
                parent, SLOT(relayAction(QAction*)));
    }
}

QList<QActionGroup*> LC_ActionGroupManager::toolGroups()
{
    QList<QActionGroup*> ag_list;
    ag_list << block
            << circle
            << curve
            << ellipse
            << dimension
            << info
            << line
            << modify
            << other
            << polyline
            << select;

    return ag_list;
}
