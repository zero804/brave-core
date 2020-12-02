/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/ui/sidebar/sidebar_model.h"

#include "base/logging.h"
#include "brave/browser/ui/sidebar/sidebar_model_data.h"
#include "brave/browser/ui/sidebar/sidebar_service_factory.h"
#include "brave/components/sidebar/sidebar_item.h"
#include "brave/components/sidebar/sidebar_service.h"

namespace sidebar {

SidebarModel::SidebarModel(Profile* profile) : profile_(profile) {}

SidebarModel::~SidebarModel() = default;

void SidebarModel::Init() {
  SidebarService* service =
      SidebarServiceFactory::GetForProfile(profile_);
  DCHECK(service);

  // Start with saved item list.
  for (const auto& item : service->GetSidebarItems())
    AddItem(item);
}

void SidebarModel::AddObserver(Observer* observer) {
  observers_.AddObserver(observer);
}

void SidebarModel::RemoveObserver(Observer* observer) {
  observers_.RemoveObserver(observer);
}

void SidebarModel::AddItem(const SidebarItem& item) {
  data_.push_back(std::make_unique<SidebarModelData>(item));
  for (Observer& obs : observers_)
    obs.OnItemAdded(item, data_.size());
}

void SidebarModel::RemoveItem(const SidebarItem& item) {
}

base::Optional<int> SidebarModel::GetActiveIndex() {
  if (active_index_ < 0)
    return base::nullopt;
  return active_index_;
}


}  // namespace sidebar
