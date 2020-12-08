/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ledger/internal/testing/ledger_test.h"

#include "base/files/file_util.h"
#include "base/path_service.h"
#include "base/strings/string_split.h"
#include "base/strings/string_util.h"

// npm run test -- brave_unit_tests --filter='LedgerDatabaseMigrationTest.*'

namespace ledger {
namespace testing {

class LedgerDatabaseMigrationTest : public LedgerTest {
 protected:
  void SetUp() override {
    // Noop
  }

  std::string GetExpectedSchema() {
    base::FilePath path =
        GetTestDataPath().AppendASCII("publisher_info_schema_current.txt");

    std::string data;
    if (!base::ReadFileToString(path, &data)) {
      return "";
    }

#if defined(OS_WIN)
    // Test data files may or may not have line endings converted to CRLF by
    // git checkout on Windows (depending on git autocrlf setting). Remove
    // CRLFs if they are there and replace with just LF, otherwise leave the
    // input data as is.
    auto split = base::SplitStringUsingSubstr(
        data, "\r\n", base::KEEP_WHITESPACE, base::SPLIT_WANT_NONEMPTY);

    if (split.size() > 1) {
      data = base::JoinString(split, "\n") + "\n";
    } else if (split.size() == 1) {
      bool ends_with_newline = (data.at(data.size() - 1) == '\n');
      data = split[0];
      if (ends_with_newline && data.at(data.size() - 1) != '\n') {
        data += "\n";
      }
    }
#endif

    return data;
  }
};

TEST_F(LedgerDatabaseMigrationTest, SchemaCheck) {
  std::string expected_schema = GetExpectedSchema();
  InitializeLedger();
  EXPECT_FALSE(expected_schema.empty());
  auto* db = client()->database()->GetInternalDatabaseForTesting();
  EXPECT_EQ(db->GetSchema(), expected_schema);
}

}  // namespace testing
}  // namespace ledger
