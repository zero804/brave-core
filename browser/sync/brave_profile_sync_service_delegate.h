/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_SYNC_BRAVE_PROFILE_SYNC_SERVICE_DELEGATE_H_
#define BRAVE_BROWSER_SYNC_BRAVE_PROFILE_SYNC_SERVICE_DELEGATE_H_

#include "brave/components/sync/driver/profile_sync_service_delegate.h"

class Profile;

namespace syncer {

// Helper class to prevent pass of profile pointer into BraveProfileSyncService
// and to keep DeviceInfoSyncService
class BraveProfileSyncServiceDelegate : public ProfileSyncServiceDelegate {
 public:
  BraveProfileSyncServiceDelegate(Profile* profile);
  ~BraveProfileSyncServiceDelegate() override;
  
  DeviceInfoSyncService* GetDeviceInfoSyncService() override;
 private:
  DeviceInfoSyncService* device_info_sync_service_;
};
 
}  // namespace syncer

#endif  // BRAVE_BROWSER_SYNC_BRAVE_PROFILE_SYNC_SERVICE_DELEGATE_H_
