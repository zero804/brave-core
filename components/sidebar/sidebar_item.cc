/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/sidebar/sidebar_item.h"

namespace sidebar {

// static
SidebarItem SidebarItem::Create(const std::string& url,
                                const std::string& title,
                                Type type) {
  SidebarItem item;
  item.url = GURL(url);
  item.title = title;
  item.type = type;
  return item;
}

bool SidebarItem::IsBuiltInType() const {
  return type == Type::kTypeBuiltIn;
}

SidebarItem::SidebarItem() = default;

SidebarItem::~SidebarItem() = default;

}  // namespace sidebar

