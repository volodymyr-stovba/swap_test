#pragma once

#include <list>
#include <stddef.h>
#include <string>

#include <Swap/Chunk.h>
#include <Swap/Medium.h>

namespace Swap
{
  constexpr static size_t MAX_CHUNK = 1024 * 1024;

  class File : public Medium
  {
    std::string ID;
    size_t Offset;

    std::list<ChunkPtr> Chunks;
  
  public:
    // ...
  };
}