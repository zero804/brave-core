/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_LEDGER_LEDGER_DATABASE_IMPL_H_
#define BAT_LEDGER_LEDGER_DATABASE_IMPL_H_

#include <memory>

#include "base/memory/memory_pressure_listener.h"
#include "base/sequence_checker.h"
#include "bat/ledger/ledger_database.h"
#include "sql/database.h"
#include "sql/init_status.h"
#include "sql/meta_table.h"

namespace ledger {

struct UseInMemoryDatabaseForTesting {};

class LedgerDatabaseImpl : public LedgerDatabase {
 public:
  explicit LedgerDatabaseImpl(const base::FilePath& path);
  explicit LedgerDatabaseImpl(UseInMemoryDatabaseForTesting);

  LedgerDatabaseImpl(const LedgerDatabaseImpl&) = delete;
  LedgerDatabaseImpl& operator=(const LedgerDatabaseImpl&) = delete;

  ~LedgerDatabaseImpl() override;

  void RunTransaction(type::DBTransactionPtr transaction,
                      type::DBCommandResponse* command_response) override;

  sql::Database* GetInternalDatabaseForTesting() { return &db_; }

 private:
  type::DBCommandResponse::Status Initialize(
      int32_t version,
      int32_t compatible_version,
      type::DBCommandResponse* command_response);

  type::DBCommandResponse::Status Execute(type::DBCommand* command);

  type::DBCommandResponse::Status Run(type::DBCommand* command);

  type::DBCommandResponse::Status Read(
      type::DBCommand* command,
      type::DBCommandResponse* command_response);

  type::DBCommandResponse::Status Migrate(int32_t version,
                                          int32_t compatible_version);

  void OnMemoryPressure(
      base::MemoryPressureListener::MemoryPressureLevel memory_pressure_level);

  const base::FilePath db_path_;
  sql::Database db_;
  sql::MetaTable meta_table_;
  bool initialized_ = false;
  bool in_memory_ = false;

  std::unique_ptr<base::MemoryPressureListener> memory_pressure_listener_;

  SEQUENCE_CHECKER(sequence_checker_);
};

}  // namespace ledger

#endif  // BAT_LEDGER_LEDGER_DATABASE_IMPL_H_
