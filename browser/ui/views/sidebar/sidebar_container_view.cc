/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <memory>

#include "brave/browser/ui/views/sidebar/sidebar_container_view.h"

#include "brave/browser/ui/brave_browser.h"
#include "brave/browser/ui/views/sidebar/sidebar_items_container_view.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/ui/browser.h"
#include "content/public/browser/browser_context.h"
#include "ui/views/border.h"
#include "ui/views/controls/webview/webview.h"
#include "url/gurl.h"

namespace {
constexpr int kBorderThickness = 1;
constexpr int kSidebarContainerViewWidth = 380;
}  // namespace

SidebarContainerView::SidebarContainerView(Browser* browser)
    : browser_(browser) {}

SidebarContainerView::~SidebarContainerView() = default;

void SidebarContainerView::Init() {
  initialized_ = true;
  SetBorder(views::CreateSolidSidedBorder(0, 0, 0, kBorderThickness,
                                          SkColorSetRGB(0xD9, 0xDC, 0xDF)));
  sidebar_items_container_view_ =
      AddChildView(std::make_unique<SidebarItemsContainerView>(
          static_cast<BraveBrowser*>(browser_)));
  webview_ = AddChildView(
      std::make_unique<views::WebView>(browser_->profile()));
  // webview_->LoadInitialURL(GURL("https://together.brave.com/"));
  // |webview_| will be visible when user opens any sidebar panel.
  webview_->SetVisible(false);
}

void SidebarContainerView::Layout() {
  if (!initialized_)
    return View::Layout();

  const int container_view_preferred_width =
      sidebar_items_container_view_->GetPreferredSize().width();
  sidebar_items_container_view_->SetBounds(
      0, 0,
      container_view_preferred_width, height());
  if(webview_->GetVisible()) {
    webview_->SetBounds(
        container_view_preferred_width, 0,
        width() - container_view_preferred_width - kBorderThickness, height());
  }
}

gfx::Size SidebarContainerView::CalculatePreferredSize() const {
  if (!initialized_)
    return View::CalculatePreferredSize();

  const int container_view_preferred_width =
      sidebar_items_container_view_->GetPreferredSize().width();

  return gfx::Size(webview_->GetVisible() ? kSidebarContainerViewWidth
                                          : container_view_preferred_width, 0);
}
