/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/ui/views/sidebar/sidebar_items_container_view.h"

#include "base/notreached.h"
#include "brave/browser/ui/brave_browser.h"
#include "brave/browser/ui/sidebar/sidebar_controller.h"
#include "brave/browser/ui/sidebar/sidebar_model.h"
#include "brave/browser/ui/views/sidebar/sidebar_item_view.h"
#include "brave/grit/brave_theme_resources.h"
#include "ui/base/resource/resource_bundle.h"
#include "ui/views/background.h"
#include "ui/views/border.h"
#include "ui/views/controls/image_view.h"
#include "ui/views/layout/box_layout.h"

namespace {

constexpr int kBorderThickness = 1;
constexpr int kSidebarItemsContainerViewWidth = 40;

int GetImageResourcesForBuiltInItem(const sidebar::SidebarItem& item,
                                    bool focused) {
  if (item.url == GURL("brave://wallet/"))
    return focused ? IDR_SIDEBAR_CRYPTO_WALLET_FOCUSED
                   : IDR_SIDEBAR_CRYPTO_WALLET;

  if (item.url == GURL("https://together.brave.com/"))
    return focused ? IDR_SIDEBAR_BRAVE_TOGETHER_FOCUSED
                   : IDR_SIDEBAR_BRAVE_TOGETHER;
  if (item.url == GURL("brave://bookmarks/"))
    return focused ? IDR_SIDEBAR_BOOKMARKS_FOCUSED : IDR_SIDEBAR_BOOKMARKS;
  if (item.url == GURL("brave://history/"))
    return focused ? IDR_SIDEBAR_HISTORY_FOCUSED : IDR_SIDEBAR_HISTORY;

  NOTREACHED();
  return IDR_SIDEBAR_BRAVE_TOGETHER;
}

}  // namespace

SidebarItemsContainerView::SidebarItemsContainerView(BraveBrowser* browser)
    : browser_(browser) {
  DCHECK(browser_);
  SetBackground(views::CreateSolidBackground(SkColorSetRGB(0xF3, 0xF3, 0xF5)));
  SetBorder(views::CreateSolidSidedBorder(0, 0, 0, kBorderThickness,
                                          SkColorSetRGB(0xD9, 0xDC, 0xDF)));
  SetLayoutManager(std::make_unique<views::BoxLayout>(
      views::BoxLayout::Orientation::kVertical, gfx::Insets(15, 0), 26));

  DCHECK(browser->sidebar_controller());
  observed_.Add(browser->sidebar_controller()->model());
}

SidebarItemsContainerView::~SidebarItemsContainerView() = default;

gfx::Size SidebarItemsContainerView::CalculatePreferredSize() const {
  return gfx::Size(children().empty() ? 0 : kSidebarItemsContainerViewWidth, 0);
}

void SidebarItemsContainerView::OnItemAdded(
    const sidebar::SidebarItem& item, int index) {
  LOG(ERROR) << __func__ << item.url;

  if (item.IsBuiltInType())
    return AddBuiltInItemView(item);
}

void SidebarItemsContainerView::AddBuiltInItemView(
    const sidebar::SidebarItem& item) {
  auto& bundle = ui::ResourceBundle::GetSharedInstance();
  auto* item_view = AddChildView(std::make_unique<SidebarItemView>());
  item_view->SetImageHorizontalAlignment(views::ImageButton::ALIGN_CENTER);
  item_view->SetImageVerticalAlignment(views::ImageButton::ALIGN_MIDDLE);
  item_view->SetImage(
      views::Button::STATE_NORMAL,
      bundle.GetImageSkiaNamed(GetImageResourcesForBuiltInItem(item, false)));
  item_view->SetImage(
      views::Button::STATE_HOVERED,
      bundle.GetImageSkiaNamed(GetImageResourcesForBuiltInItem(item, true)));
  item_view->SetImage(
      views::Button::STATE_PRESSED,
      bundle.GetImageSkiaNamed(GetImageResourcesForBuiltInItem(item, true)));
  Layout();
}
