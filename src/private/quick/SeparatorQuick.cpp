/*
  This file is part of KDDockWidgets.

  Copyright (C) 2018-2019 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Sérgio Martins <sergio.martins@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "SeparatorQuick_p.h"
#include "multisplitter/MultiSplitterLayout_p.h"
#include "multisplitter/Anchor_p.h"
#include "Logging_p.h"
#include "Config.h"

#include <QQmlComponent>

using namespace KDDockWidgets;

SeparatorQuick::SeparatorQuick(KDDockWidgets::Anchor *anchor, QWidgetAdapter *parent)
    : Separator(anchor, parent)
{
    auto component = new QQmlComponent(Config::self().qmlEngine(),
                                       QUrl(QStringLiteral("qrc:/kddockwidgets/quick/qml/Separator.qml")));


    auto separatorItem = static_cast<QQuickItem*>(component->create());
    separatorItem->setParentItem(this);
    separatorItem->setParent(this);
}