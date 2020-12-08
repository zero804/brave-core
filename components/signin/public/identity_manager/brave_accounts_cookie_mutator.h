/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_ACCOUNTS_COOKIE_MUTATOR_H_
#define BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_ACCOUNTS_COOKIE_MUTATOR_H_

#include "components/signin/public/identity_manager/accounts_cookie_mutator.h"

struct CoreAccountId;

namespace signin {

class BraveAccountsCookieMutator : public AccountsCookieMutator {
 public:
  BraveAccountsCookieMutator();
  ~BraveAccountsCookieMutator() override;

  //DISALLOW_COPY_AND_ASSIGN(AccountsCookieMutator);
  BraveAccountsCookieMutator(const BraveAccountsCookieMutator&) = delete;
  BraveAccountsCookieMutator& operator=(const BraveAccountsCookieMutator&)
                                                                       = delete;
  void AddAccountToCookie(
      const CoreAccountId& account_id,
      gaia::GaiaSource source,
      AddAccountToCookieCompletedCallback completion_callback) override;

  void AddAccountToCookieWithToken(
      const CoreAccountId& account_id,
      const std::string& access_token,
      gaia::GaiaSource source,
      AddAccountToCookieCompletedCallback completion_callback) override;

  void SetAccountsInCookie(
      const MultiloginParameters& parameters,
      gaia::GaiaSource source,
      base::OnceCallback<void(SetAccountsInCookieResult)>
          set_accounts_in_cookies_completed_callback) override;

  /////////////////////////////////////////////////////////////
  std::unique_ptr<AccountsCookieMutator::SetAccountsInCookieTask>
  SetAccountsInCookieForPartition(
      PartitionDelegate* partition_delegate,
      const MultiloginParameters& parameters,
      base::OnceCallback<void(SetAccountsInCookieResult)>
          set_accounts_in_cookies_completed_callback) override;

  void TriggerCookieJarUpdate() override;

#if defined(OS_IOS)
  void ForceTriggerOnCookieChange() override;
#endif

  void LogOutAllAccounts(
      gaia::GaiaSource source,
      LogOutFromCookieCompletedCallback completion_callback) override;
};

}  // namespace signin

#endif  // BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_ACCOUNTS_COOKIE_MUTATOR_H_
