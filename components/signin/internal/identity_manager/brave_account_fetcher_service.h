/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_SIGNIN_INTERNAL_IDENTITY_MANAGER_BRAVE_ACCOUNT_FETCHER_SERVICE_H_
#define BRAVE_COMPONENTS_SIGNIN_INTERNAL_IDENTITY_MANAGER_BRAVE_ACCOUNT_FETCHER_SERVICE_H_

#include "components/signin/internal/identity_manager/account_fetcher_service.h"

class BraveAccountFetcherService : public AccountFetcherService {
 public:
   BraveAccountFetcherService();
   ~BraveAccountFetcherService() override;

  // must be overridden (identity_manager):
  // account_fetcher_service_->Shutdown();
  // account_fetcher_service_->OnNetworkInitialized();
  // account_fetcher_service_->ForceRefreshOfAccountInfo(account_id);
  //
  // but maybe we dont need


  BraveAccountFetcherService(const BraveAccountFetcherService&) = delete;
  BraveAccountFetcherService& operator=(const BraveAccountFetcherService&) = delete;
  //DISALLOW_COPY_AND_ASSIGN(AccountFetcherService);
};

#endif  // BRAVE_COMPONENTS_SIGNIN_INTERNAL_IDENTITY_MANAGER_BRAVE_ACCOUNT_FETCHER_SERVICE_H_
