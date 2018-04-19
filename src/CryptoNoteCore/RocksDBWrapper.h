// Copyright (c) 2012-2017
// Copyright (c) 2017-2018
//
//The CryptoNote developers, The Bytecoin developers and NPCoin developers
//
// This file is part of Bytecoin.
//
// NPCoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// NPCoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with NPCoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <atomic>
#include <memory>
#include <string>

#include "rocksdb/db.h"

#include "IDataBase.h"
#include "DataBaseConfig.h"

#include <Logging/LoggerRef.h>

namespace CryptoNote {

class RocksDBWrapper : public IDataBase {
public:
  RocksDBWrapper(Logging::ILogger& logger);
  virtual ~RocksDBWrapper();

  RocksDBWrapper(const RocksDBWrapper&) = delete;
  RocksDBWrapper(RocksDBWrapper&&) = delete;

  RocksDBWrapper& operator=(const RocksDBWrapper&) = delete;
  RocksDBWrapper& operator=(RocksDBWrapper&&) = delete;

  void init(const DataBaseConfig& config);
  void shutdown();
  void destoy(const DataBaseConfig& config); //Be careful with this method!

  std::error_code write(IWriteBatch& batch) override;
  std::error_code writeSync(IWriteBatch& batch) override;
  std::error_code read(IReadBatch& batch) override;

private:
  std::error_code write(IWriteBatch& batch, bool sync);

  rocksdb::Options getDBOptions(const DataBaseConfig& config);
  std::string getDataDir(const DataBaseConfig& config);

  enum State {
    NOT_INITIALIZED,
    INITIALIZED
  };

  Logging::LoggerRef logger;
  std::unique_ptr<rocksdb::DB> db;
  std::atomic<State> state;
};
}
