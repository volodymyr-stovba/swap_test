#pragma once

#include <memory>
#include <string>

namespace Swap
{
  class Folder
  {
    std::string Path;

  public:
    Folder(const std::string& path);

    std::string NextChunkName(const std::string& id, size_t offset);
  };

  typedef std::shared_ptr<Folder> FolderPtr;
}