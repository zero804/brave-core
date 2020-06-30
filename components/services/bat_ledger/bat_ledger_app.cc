/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/services/bat_ledger/bat_ledger_app.h"

#include <string>
#include <utility>

#include "brave/components/services/bat_ledger/bat_ledger_service_impl.h"

namespace bat_ledger {

BatLedgerApp::BatLedgerApp(service_manager::mojom::ServiceRequest request) :
    service_binding_(this, std::move(request)),
    service_keepalive_(&service_binding_, base::TimeDelta()) {
}

BatLedgerApp::~BatLedgerApp() = default;

void BatLedgerApp::OnStart() {
  binders_.Add(base::BindRepeating(&BatLedgerApp::BindBatLedgerServiceReceiver,
      base::Unretained(this),
      &service_keepalive_));
}

void BatLedgerApp::BindBatLedgerServiceReceiver(
    service_manager::ServiceKeepalive* keepalive,
    mojo::PendingReceiver<bat_ledger::mojom::BatLedgerService> receiver) {
  receivers_.Add(
      std::make_unique<bat_ledger::BatLedgerServiceImpl>(
          keepalive->CreateRef()),
      std::move(receiver));
}

void BatLedgerApp::OnConnect(
    const service_manager::ConnectSourceInfo& source_info,
    const std::string& interface_name,
    mojo::ScopedMessagePipeHandle receiver_pipe) {
  binders_.TryBind(interface_name, &receiver_pipe);
}

}  // namespace bat_ledger