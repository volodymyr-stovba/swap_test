#pragma once

#include <chrono>

class CustomRate
{
  std::chrono::steady_clock::time_point Start;

  long long BytesInRealTime;
  long long BytesWithCustomRate;
  long CustomRateDivider;

public:
  CustomRate(long divider = 1);

  double Calculate(bool custom = true);
  void Adjust();

  void ReportRealTime(long long cb);
  void ReportCustom(long long cb);
};
