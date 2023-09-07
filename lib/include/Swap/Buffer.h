#pragma once

#include <vector>

#include <Swap/Medium.h>

namespace Swap
{
  class Buffer : public Medium
  {
    std::vector<char> Data;
    size_t Head;
    size_t Tail;

    enum 
    {
      GROW = 4 * 1024,
      MAX_BUFFER_SIZE = 16 * 1024 * 1024
    };

  public:
    Buffer();

    Status Append(const void* data, size_t size) override;
    Status Read(void* buffer, size_t max_size, size_t& nread) override;
    size_t Size() const override;
  };
}