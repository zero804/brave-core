/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_DIAGNOSTICS_PROVIDER_H_
#define BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_DIAGNOSTICS_PROVIDER_H_

#include "base/time/time.h"
#include "components/signin/public/identity_manager/diagnostics_provider.h"
#include "components/signin/public/identity_manager/load_credentials_state.h"

namespace signin {

class BraveDiagnosticsProvider : public DiagnosticsProvider {
 public:
  BraveDiagnosticsProvider();
  ~BraveDiagnosticsProvider() override;
  BraveDiagnosticsProvider(const BraveDiagnosticsProvider&) = delete;
  BraveDiagnosticsProvider& operator=(const BraveDiagnosticsProvider&)
      = delete;

  signin::LoadCredentialsState
  GetDetailedStateOfLoadingOfRefreshTokens() const override;

  base::TimeDelta GetDelayBeforeMakingAccessTokenRequests() const override;

  // Returns the time until a cookie request can be sent (will be zero if the
  // release time is in the past).
  base::TimeDelta GetDelayBeforeMakingCookieRequests() const override;
};

}  // namespace signin

#endif  // BRAVE_COMPONENTS_SIGNIN_PUBLIC_IDENTITY_MANAGER_BRAVE_DIAGNOSTICS_PROVIDER_H_
