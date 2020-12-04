/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_PRIMARY_ACCOUNT_MUTATOR_H_
#define BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_PRIMARY_ACCOUNT_MUTATOR_H_

#include "components/signin/public/identity_manager/primary_account_mutator.h"

namespace signin {

class BravePrimaryAccountMutator : public PrimaryAccountMutator {
 public:
  BravePrimaryAccountMutator();
  ~BravePrimaryAccountMutator() override;

  // BravePrimaryAccountMutator is non-copyable, non-moveable.
  BravePrimaryAccountMutator(BravePrimaryAccountMutator&& other) = delete;
  BravePrimaryAccountMutator const& operator=(
      BravePrimaryAccountMutator&& other) = delete;

  BravePrimaryAccountMutator(const BravePrimaryAccountMutator& other) = delete;
  BravePrimaryAccountMutator const& operator=(
      const BravePrimaryAccountMutator& other) = delete;

 private:
  bool SetPrimaryAccount(const CoreAccountId& account_id) override;
  void SetUnconsentedPrimaryAccount(const CoreAccountId& account_id) override;
#if defined(OS_CHROMEOS)
  void RevokeSyncConsent() override;
#endif
#if !defined(OS_CHROMEOS)
  bool ClearPrimaryAccount(
      ClearAccountsAction action,
      signin_metrics::ProfileSignout source_metric,
      signin_metrics::SignoutDelete delete_metric) override;
#endif
};

}  // namespace signin

#endif  // BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_PRIMARY_ACCOUNT_MUTATOR_H_
