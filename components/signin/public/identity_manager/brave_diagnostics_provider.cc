/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/signin/public/identity_manager/brave_diagnostics_provider.h"

namespace signin {

BraveDiagnosticsProvider::BraveDiagnosticsProvider() : DiagnosticsProvider() {
}

BraveDiagnosticsProvider::~BraveDiagnosticsProvider() {}

LoadCredentialsState
BraveDiagnosticsProvider::GetDetailedStateOfLoadingOfRefreshTokens() const {
  return LoadCredentialsState::LOAD_CREDENTIALS_NOT_STARTED;
}

base::TimeDelta
BraveDiagnosticsProvider::GetDelayBeforeMakingAccessTokenRequests() const {
  return base::TimeDelta();
}

base::TimeDelta
BraveDiagnosticsProvider::GetDelayBeforeMakingCookieRequests() const {
  return base::TimeDelta();
}

}  // namespace signin
