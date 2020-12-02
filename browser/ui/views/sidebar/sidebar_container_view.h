/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_UI_VIEWS_SIDEBAR_SIDEBAR_CONTAINER_VIEW_H_
#define BRAVE_BROWSER_UI_VIEWS_SIDEBAR_SIDEBAR_CONTAINER_VIEW_H_

#include "ui/views/view.h"

namespace views {
class WebView;
}  // namespace views

class Browser;

class SidebarItemsContainerView;

// This view is the parent view of all sidebar ui.
// Sidebar items view and sidebar contents view could be the children of this
// view.
class SidebarContainerView : public views::View {
 public:
  explicit SidebarContainerView(Browser* browser);
  ~SidebarContainerView() override;

  SidebarContainerView(const SidebarContainerView&) = delete;
  SidebarContainerView& operator=(const SidebarContainerView&) = delete;

  void Init();

  // views::View overrides:
  void Layout() override;
  gfx::Size CalculatePreferredSize() const override;

 private:
  Browser* browser_ = nullptr;
  views::WebView* webview_ = nullptr;
  bool initialized_ = false;
  SidebarItemsContainerView* sidebar_items_container_view_ = nullptr;
};

#endif  // BRAVE_BROWSER_UI_VIEWS_SIDEBAR_SIDEBAR_CONTAINER_VIEW_H_
