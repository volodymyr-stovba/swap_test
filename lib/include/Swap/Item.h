#pragma once

#include <mutex>
#include <string>

#include <Swap/Folder.h>
#include <Swap/Medium.h>

namespace Swap
{
  class Item
  {
    FolderPtr Folder;
    std::string ID;

    std::mutex Lock;
    MediumPtr Medium;
    
  public:
    Item(const std::string& id, FolderPtr folder = FolderPtr());

    Status Append(const void* data, size_t size);
    Status Read(void* buffer, size_t max_size, size_t& nread);
  };

  typedef std::shared_ptr<Item> ItemPtr;
}