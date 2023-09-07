#include <Swap/Buffer.h>
#include <Swap/Item.h>

using namespace Swap;

Item::Item(const std::string& id, FolderPtr folder)
  : Folder(folder)
  , ID(id)
{
  Medium = std::make_shared<Buffer>();
}

Status Item::Append(const void* data, size_t size)
{
  std::lock_guard guard(Lock);

  Status status = Medium->Append(data, size);
  if (status == Status::LIMIT_EXCEEDED)
  {
    // TODO: Switch medium
  }
  return status;
}

Status Item::Read(void* buffer, size_t max_size, size_t& nread)
{
  std::lock_guard guard(Lock);
  return Medium->Read(buffer, max_size, nread);
}

