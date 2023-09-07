#pragma once

#include <memory>
#include <stddef.h>
#include <string>

namespace Swap
{
  class Chunk
  {
    std::string FileName;

    int Handle;                             // Use open/close from io.h

    size_t ReadPos;
  };

  typedef std::shared_ptr<Chunk> ChunkPtr;
}