/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/signin/public/identity_manager/brave_identity_manager.h"

#include <vector>

#include "brave/components/signin/public/identity_manager/brave_primary_account_mutator.h"
#include "components/signin/public/identity_manager/accounts_in_cookie_jar_info.h"

namespace signin {

BraveIdentityManager::BraveIdentityManager() {}

BraveIdentityManager::~BraveIdentityManager() {}

void BraveIdentityManager::AddObserver(
    BraveIdentityManager::Observer* observer) {}

void BraveIdentityManager::RemoveObserver(
    BraveIdentityManager::Observer* observer) {}

AccountsInCookieJarInfo BraveIdentityManager::GetAccountsInCookieJar() const {
  // accounts_in_cookie_jar_info.accounts_are_fresh must be false,
  // see `ProfileSyncService::OnEngineInitialized`
  return AccountsInCookieJarInfo(false, std::vector<gaia::ListedAccount>(),
                                 std::vector<gaia::ListedAccount>());
}

PrimaryAccountMutator* BraveIdentityManager::GetPrimaryAccountMutator() {
  // We need it non-null for  `case DISABLE_SYNC_ON_CLIENT:` in
  // `ProfileSyncService::OnActionableError`
  if (!primary_account_mutator_) {
    primary_account_mutator_.reset(new BravePrimaryAccountMutator());
  }

  return primary_account_mutator_.get();
}

}  // namespace signin
