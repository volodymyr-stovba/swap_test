#include <filesystem>

#include <Swap/Folder.h>

namespace fs = std::filesystem;

using namespace Swap;

Folder::Folder(const std::string& path)
  : Path(path)
{
}

std::string Folder::NextChunkName(const std::string& id, size_t offset)
{
  std::stringstream ss;
  ss << "#" << std::hex << offset << ".bin";

  fs::path dir(Path);
  auto file = dir / (id + ss.str());

  return file.string();
}
