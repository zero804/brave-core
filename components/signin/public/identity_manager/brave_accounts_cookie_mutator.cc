/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/signin/public/identity_manager/brave_accounts_cookie_mutator.h"

#include "google_apis/gaia/core_account_id.h"
#include "google_apis/gaia/gaia_auth_fetcher.h"

namespace signin {

BraveAccountsCookieMutator::BraveAccountsCookieMutator() {
  ;
}

BraveAccountsCookieMutator::~BraveAccountsCookieMutator() {
  ;
}

void BraveAccountsCookieMutator::AddAccountToCookie(
    const CoreAccountId& account_id,
    gaia::GaiaSource source,
    AddAccountToCookieCompletedCallback completion_callback) {
  ;
}

void BraveAccountsCookieMutator::AddAccountToCookieWithToken(
    const CoreAccountId& account_id,
    const std::string& access_token,
    gaia::GaiaSource source,
    AddAccountToCookieCompletedCallback completion_callback) {
  ;
}

void BraveAccountsCookieMutator::SetAccountsInCookie(
    const MultiloginParameters& parameters,
    gaia::GaiaSource source,
    base::OnceCallback<void(SetAccountsInCookieResult)>
        set_accounts_in_cookies_completed_callback) {
  ;
}

std::unique_ptr<AccountsCookieMutator::SetAccountsInCookieTask>
BraveAccountsCookieMutator::SetAccountsInCookieForPartition(
    PartitionDelegate* partition_delegate,
    const MultiloginParameters& parameters,
    base::OnceCallback<void(SetAccountsInCookieResult)>
        set_accounts_in_cookies_completed_callback) {
  return std::make_unique<AccountsCookieMutator::SetAccountsInCookieTask>();
}

void BraveAccountsCookieMutator::TriggerCookieJarUpdate() {
;
}

#if defined(OS_IOS)
void BraveAccountsCookieMutator::ForceTriggerOnCookieChange() {
;
}
#endif

void BraveAccountsCookieMutator::LogOutAllAccounts(
    gaia::GaiaSource source,
    LogOutFromCookieCompletedCallback completion_callback) {
;
}

}  // namespace signin
