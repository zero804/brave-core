/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/signin/public/identity_manager/brave_identity_manager.h"

#include "brave/components/signin/internal/identity_manager/brave_account_fetcher_service.h"
#include "brave/components/signin/public/identity_manager/brave_accounts_mutator.h"
#include "brave/components/signin/public/identity_manager/brave_accounts_cookie_mutator.h"
#include "brave/components/signin/public/identity_manager/brave_diagnostics_provider.h"
#include "components/signin/public/identity_manager/accounts_in_cookie_jar_info.h"


namespace signin {


BraveIdentityManager::BraveIdentityManager (
/* IdentityManager::InitParameters&& parameters*/) : IdentityManager(
    //IdentityManager::InitParameters()
    MakeInitParameters()
) {
DLOG(ERROR) << "[BraveSync] " << __func__ << " 000";
DLOG(ERROR) << "[BraveSync] " << __func__ << " 001 EXIT";
}

BraveIdentityManager::~BraveIdentityManager() {
DLOG(ERROR) << "[BraveSync] " << __func__ << " 000";
}

void BraveIdentityManager::AddObserver(IdentityManager::Observer* observer) {
DLOG(ERROR) << "[BraveSync] " << __func__ << " 000";
}

void BraveIdentityManager::RemoveObserver(IdentityManager::Observer* observer) {
DLOG(ERROR) << "[BraveSync] " << __func__ << " 000";
}

AccountsInCookieJarInfo BraveIdentityManager::GetAccountsInCookieJar() const {
DLOG(ERROR) << "[BraveSync] " << __func__ << " 000";
  // accounts_in_cookie_jar_info.accounts_are_fresh must be false
  return AccountsInCookieJarInfo(
     false,
     std::vector<gaia::ListedAccount>(),
     std::vector<gaia::ListedAccount>());
}

PrimaryAccountMutator* BraveIdentityManager::GetPrimaryAccountMutator() {
DLOG(ERROR) << "[BraveSync] " << __func__ << " 000";
  return nullptr;
  // must not be null, must have
  // account_mutator->ClearPrimaryAccount
}

IdentityManager::InitParameters BraveIdentityManager::MakeInitParameters() {
DLOG(ERROR) << "[BraveSync] " << __func__ << " 000";
  IdentityManager::InitParameters init_parameters;

  // Need to have
  //  diagnostics_provider_(std::move(parameters.diagnostics_provider)
  // account_fetcher_service_(std::move(parameters.account_fetcher_service)),

  // brave_diagnostics_provider.reset(new BraveDiagnosticsProvider());
  // brave_account_fetcher_service.reset(new BraveAccountFetcherService());
  //
  // init_parameters.diagnostics_provider = brave_diagnostics_provider.get();
  // init_parameters.account_fetcher_service = brave_account_fetcher_service.get();

  init_parameters.diagnostics_provider.reset(new BraveDiagnosticsProvider());
  init_parameters.account_fetcher_service.reset(
      new BraveAccountFetcherService());
  /*
  identity_mutator_(std::move(parameters.primary_account_mutator),
                    std::move(parameters.accounts_mutator),
                    std::move(parameters.accounts_cookie_mutator),
                    std::move(parameters.device_accounts_synchronizer)),
  */
  init_parameters.accounts_mutator.reset(new BraveAccountsMutator());
  init_parameters.accounts_cookie_mutator.reset(
      new BraveAccountsCookieMutator());

DLOG(ERROR) << "[BraveSync] " << __func__ << " 001 EXIT";
  return init_parameters;
}

}  // namespace signin
