#include <chrono>
#include <stddef.h>
#include <thread>

#include <gtest/gtest.h>

#include <Swap/Item.h>

#include "CustomRate.h"

using namespace Swap;

const size_t TOTAL_BYTES = 16 * 1024 * 1024;
const size_t BLOCK_SIZE = 4 * 1024;

TEST(swap, one)
{
  auto item = std::make_shared<Item>("one");

  std::string tx("12345");
  auto status1 = item->Append(tx.c_str(), tx.size());
  EXPECT_EQ(status1, Status::OK);

  size_t cb = 0;
  char buffer[256]{};
  auto status2 = item->Read(buffer, sizeof(buffer), cb);
  EXPECT_EQ(status2, Status::OK);

  EXPECT_EQ(tx, std::string(buffer, cb));
}

TEST(swap, two)
{
  // AppendRate = real time,  ReadRate = AppendRate / 2
  CustomRate rate(2);

  // each 4K block of appending data contains hex character. '0', then '1', ... 'F'. then again '0', ....
  char block[BLOCK_SIZE]{};

  auto item = std::make_shared<Item>("two");
  auto worker = [](CustomRate& rate, ItemPtr item) {
    // implement:
    // reads data by 4K blocks. checks that data is consistent. if no, aborts test with an error
    // uses rate.ReportCustom() and rate.Adjust() to adjust rate
  };
  std::thread reader(worker, std::ref(rate), item);

  long long cb = 0;
  for (; cb < TOTAL_BYTES; cb += BLOCK_SIZE)
  {
    // fill block
    // item->Append(block, blockSize);
    // uses rate.ReportRealTime()
  }

  reader.join();
}

TEST(swap, three)
{
  // The same as test two but 2 * AppendRate = ReadRate

  // AppendRate = real time,  ReadRate = AppendRate / 2
  CustomRate rate(2);

  // each 4K block of appending data contains hex character. '0', then '1', ... 'F'. then again '0', ....
  char block[BLOCK_SIZE]{};

  auto item = std::make_shared<Item>("two");
  auto worker = [](CustomRate& rate, ItemPtr item) {
    // implement:
    // reads data by 4K blocks. checks that data is consistent. if no, aborts test with an error
    // uses rate.ReportRealTime()
  };
  std::thread reader(worker, std::ref(rate), item);

  long long cb = 0;
  for (; cb < TOTAL_BYTES; cb += BLOCK_SIZE)
  {
    // fill block
    // item->Append(block, blockSize);
    // uses ReportCustom() and rate.Adjust() to adjust rate
  }

  reader.join();
}