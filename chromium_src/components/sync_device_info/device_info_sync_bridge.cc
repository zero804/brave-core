// Copyright (c) 2020 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#include "brave/components/sync_device_info/brave_device_info.h"

#define BRAVE_MAKE_LOCAL_DEVICE_SPECIFICS \
  specifics->mutable_brave_fields()->set_is_self_delete_supported(true);

#define BRAVE_SPECIFICS_TO_MODEL_1 BraveDeviceInfo

#define BRAVE_SPECIFICS_TO_MODEL_2                             \
    , specifics.has_brave_fields() &&                          \
    specifics.brave_fields().has_is_self_delete_supported() && \
    specifics.brave_fields().is_self_delete_supported()

#include "../../../../components/sync_device_info/device_info_sync_bridge.cc"

#undef BRAVE_SPECIFICS_TO_MODEL_1
#undef BRAVE_SPECIFICS_TO_MODEL_2
#undef BRAVE_MAKE_LOCAL_DEVICE_SPECIFICS

#include "base/threading/sequenced_task_runner_handle.h"

namespace syncer {

namespace {

std::unique_ptr<BraveDeviceInfo> BraveSpecificsToModel(
    const DeviceInfoSpecifics& specifics) {
  std::unique_ptr<DeviceInfo> device_info = SpecificsToModel(specifics);
  return std::unique_ptr<BraveDeviceInfo>(
      static_cast<BraveDeviceInfo*>(device_info.release()));
}

}  // namespace

void DeviceInfoSyncBridge::DeleteDeviceInfo(const std::string& client_id,
                                            base::OnceClosure callback) {
  std::unique_ptr<WriteBatch> batch = store_->CreateWriteBatch();
  change_processor()->Delete(client_id, batch->GetMetadataChangeList());
  DeleteSpecifics(client_id, batch.get());
  batch->GetMetadataChangeList()->ClearMetadata(client_id);
  CommitAndNotify(std::move(batch), /*should_notify=*/true);
  base::SequencedTaskRunnerHandle::Get()->PostDelayedTask(
      FROM_HERE,
      base::BindOnce(&DeviceInfoSyncBridge::OnDeviceInfoDeleted,
                     weak_ptr_factory_.GetWeakPtr(), client_id,
                     std::move(callback)),
      base::TimeDelta::FromSeconds(1));
}

void DeviceInfoSyncBridge::OnDeviceInfoDeleted(const std::string& client_id,
                                               base::OnceClosure callback) {
  // Make sure the deleted device info is sent
  if (change_processor()->IsEntityUnsynced(client_id)) {
    base::SequencedTaskRunnerHandle::Get()->PostDelayedTask(
        FROM_HERE,
        base::BindOnce(&DeviceInfoSyncBridge::OnDeviceInfoDeleted,
                       weak_ptr_factory_.GetWeakPtr(), client_id,
                       std::move(callback)),
        base::TimeDelta::FromSeconds(1));
  } else {
    std::move(callback).Run();
  }
}

std::vector<std::unique_ptr<BraveDeviceInfo>>
DeviceInfoSyncBridge::GetAllBraveDeviceInfo() const {
  std::vector<std::unique_ptr<BraveDeviceInfo>> list;
  for (auto iter = all_data_.begin(); iter != all_data_.end(); ++iter) {
    list.push_back(BraveSpecificsToModel(*iter->second));
  }
  return list;
}

}  // namespace syncer
