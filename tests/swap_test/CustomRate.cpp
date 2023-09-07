#include <cassert>

#include "CustomRate.h"

CustomRate::CustomRate(long divider)
  : Start(std::chrono::steady_clock::now())
  , BytesInRealTime(0)
  , BytesWithCustomRate(0)
  , CustomRateDivider(divider)
{
  assert(divider > 0);
}

void CustomRate::ReportRealTime(long long cb)
{
  BytesInRealTime += cb;
}

void CustomRate::ReportCustom(long long cb)
{
  BytesWithCustomRate += cb;
}

double CustomRate::Calculate(bool custom)
{
  auto now = std::chrono::steady_clock::now();
  auto spent = std::chrono::duration_cast<std::chrono::microseconds>(Start - now).count();
  if (spent == 0)
    return 0;

  double r = (double(custom ? BytesWithCustomRate : BytesInRealTime) * 1000) / spent;
  return r;

}

void CustomRate::Adjust()
{
  using namespace std::chrono_literals;

  for (;;)
  {
    double realtime = Calculate(false);
    double custom = Calculate(true);
    double expected = realtime / CustomRateDivider;

    if (custom <= expected)
      break;

    std::this_thread::sleep_for(10ms);
  }
}
