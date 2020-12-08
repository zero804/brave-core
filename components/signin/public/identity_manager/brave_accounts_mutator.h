/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_ACCOUNTS_MUTATOR_H_
#define BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_ACCOUNTS_MUTATOR_H_

#include "components/signin/public/identity_manager/accounts_mutator.h"

namespace signin_metrics {
enum class SourceForRefreshTokenOperation;
}

struct CoreAccountId;

namespace signin {

class BraveAccountsMutator : public AccountsMutator {
 public:
  BraveAccountsMutator();
  ~BraveAccountsMutator() override;

  //DISALLOW_COPY_AND_ASSIGN
  BraveAccountsMutator(const BraveAccountsMutator&) = delete;
  BraveAccountsMutator& operator=(const BraveAccountsMutator&) = delete;

  CoreAccountId AddOrUpdateAccount(
      const std::string& gaia_id,
      const std::string& email,
      const std::string& refresh_token,
      bool is_under_advanced_protection,
      signin_metrics::SourceForRefreshTokenOperation source) override;

  void UpdateAccountInfo(
      const CoreAccountId& account_id,
      base::Optional<bool> is_child_account,
      base::Optional<bool> is_under_advanced_protection) override;

  void RemoveAccount(
      const CoreAccountId& account_id,
      signin_metrics::SourceForRefreshTokenOperation source) override;

  void RemoveAllAccounts(
      signin_metrics::SourceForRefreshTokenOperation source) override;

  void InvalidateRefreshTokenForPrimaryAccount(
      signin_metrics::SourceForRefreshTokenOperation source) override;

#if BUILDFLAG(ENABLE_DICE_SUPPORT)
  void MoveAccount(AccountsMutator* target,
                           const CoreAccountId& account_id) override;
#endif


};

}  // namespace signin

#endif  // BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_ACCOUNTS_MUTATOR_H_
