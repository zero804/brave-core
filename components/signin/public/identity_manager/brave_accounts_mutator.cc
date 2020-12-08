/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/signin/public/identity_manager/brave_accounts_mutator.h"

#include "base/logging.h"
#include "google_apis/gaia/core_account_id.h"

namespace signin {

BraveAccountsMutator::BraveAccountsMutator() : AccountsMutator() {
DLOG(ERROR) << "[BraveSync] " << __func__ << " 000";
}

BraveAccountsMutator::~BraveAccountsMutator() {
DLOG(ERROR) << "[BraveSync] " << __func__ << " 000";
}

CoreAccountId BraveAccountsMutator::AddOrUpdateAccount(
    const std::string& gaia_id,
    const std::string& email,
    const std::string& refresh_token,
    bool is_under_advanced_protection,
    signin_metrics::SourceForRefreshTokenOperation source) {
  return CoreAccountId();
}

void BraveAccountsMutator::UpdateAccountInfo(
    const CoreAccountId& account_id,
    base::Optional<bool> is_child_account,
    base::Optional<bool> is_under_advanced_protection) {
  ;
}

void BraveAccountsMutator::RemoveAccount(
    const CoreAccountId& account_id,
    signin_metrics::SourceForRefreshTokenOperation source) {
 ;
}

void BraveAccountsMutator::RemoveAllAccounts(
    signin_metrics::SourceForRefreshTokenOperation source) {
 ;
}

void BraveAccountsMutator::InvalidateRefreshTokenForPrimaryAccount(
    signin_metrics::SourceForRefreshTokenOperation source) {
 ;
}

#if BUILDFLAG(ENABLE_DICE_SUPPORT)
void BraveAccountsMutator::MoveAccount(AccountsMutator* target,
                         const CoreAccountId& account_id) {
  ;
}
#endif

}  // namespace signin
