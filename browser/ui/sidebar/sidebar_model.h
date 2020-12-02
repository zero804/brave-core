/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_UI_SIDEBAR_SIDEBAR_MODEL_H_
#define BRAVE_BROWSER_UI_SIDEBAR_SIDEBAR_MODEL_H_

#include <memory>
#include <vector>

#include "base/observer_list.h"
#include "base/optional.h"
#include "brave/browser/ui/sidebar/sidebar_model_data.h"

class Profile;

namespace sidebar {

class SidebarModelData;

// Manage sidebar runtime state.
class SidebarModel {
 public:
  class Observer : public base::CheckedObserver {
   public:
    virtual void OnItemAdded(const SidebarItem& item, int index) = 0;

   protected:
    ~Observer() override = default;
  };

  explicit SidebarModel(Profile* profile);
  virtual ~SidebarModel();

  SidebarModel(const SidebarModel&) = delete;
  SidebarModel& operator=(const SidebarModel&) = delete;

  void Init();

  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  void AddItem(const SidebarItem& item);
  void RemoveItem(const SidebarItem& item);

  // Return null if sidebar panel is not opened.
  base::Optional<int> GetActiveIndex();

  const std::vector<std::unique_ptr<SidebarModelData>>& data() const {
    return data_;
  }

 private:
  // Non-negative if sidebar panel is opened.
  int active_index_ = -1;
  Profile* profile_ = nullptr;
  base::ObserverList<Observer> observers_;
  std::vector<std::unique_ptr<SidebarModelData>> data_;
};

}  // sidebar

#endif  // BRAVE_BROWSER_UI_SIDEBAR_SIDEBAR_MODEL_H_
