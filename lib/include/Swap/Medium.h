#pragma once

#include <memory>
#include <stddef.h>

#include <Swap/Status.h>

namespace Swap
{
  enum class MediumType
  {
    MEMORY,
    FILE
  };

  class Medium
  {
    MediumType Type;

  public:
    Medium(MediumType type);
    virtual ~Medium();

    MediumType GetType() const;

    virtual Status Append(const void* data, size_t size) = 0;
    virtual Status Read(void* buffer, size_t max_size, size_t& nread) = 0;
    virtual size_t Size() const = 0;
  };

  typedef std::shared_ptr<Medium> MediumPtr;
}