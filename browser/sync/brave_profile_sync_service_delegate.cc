/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */
 
#include "brave/browser/sync/brave_profile_sync_service_delegate.h"

#include "chrome/browser/sync/device_info_sync_service_factory.h"

namespace syncer {

BraveProfileSyncServiceDelegate::BraveProfileSyncServiceDelegate(
    Profile* profile) : 
    device_info_sync_service_(DeviceInfoSyncServiceFactory::GetForProfile(profile)) {
  DCHECK(device_info_sync_service_);
}

BraveProfileSyncServiceDelegate::~BraveProfileSyncServiceDelegate() {}

DeviceInfoSyncService* 
    BraveProfileSyncServiceDelegate::GetDeviceInfoSyncService() {
  return device_info_sync_service_;
}
  
}  // namespace syncer
