/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/signin/public/identity_manager/brave_primary_account_mutator.h"

#include "base/logging.h"
#include "google_apis/gaia/core_account_id.h"

namespace signin {

BravePrimaryAccountMutator::BravePrimaryAccountMutator()
    : PrimaryAccountMutator() {}

BravePrimaryAccountMutator::~BravePrimaryAccountMutator() {}

bool BravePrimaryAccountMutator::SetPrimaryAccount(
    const CoreAccountId& account_id) {
  return false;
}

void BravePrimaryAccountMutator::SetUnconsentedPrimaryAccount(
    const CoreAccountId& account_id) {}

#if defined(OS_CHROMEOS)
void BravePrimaryAccountMutator::RevokeSyncConsent() {}
#endif

#if !defined(OS_CHROMEOS)
bool BravePrimaryAccountMutator::ClearPrimaryAccount(
    ClearAccountsAction action,
    signin_metrics::ProfileSignout source_metric,
    signin_metrics::SignoutDelete delete_metric) {
  return false;
}
#endif

}  // namespace signin
