#include <Swap/Buffer.h>

using namespace Swap;

// H-Head T-Tail S-Data.size()
// 
// H < T
//---------H------------T---------------------S
//         DATADATADATAD
//--------------------------------------------
// H > T
//-------T------------------------------H-----S
//TADATAD                               DATADA
//--------------------------------------------
// H == T - Empty buffer

Buffer::Buffer()
  : Medium(MediumType::MEMORY)
  , Data(GROW)
  , Head(0)
  , Tail(0)
{
}

Status Buffer::Append(const void* data, size_t size)
{
  size_t n = Size();

  if (n + size > MAX_BUFFER_SIZE)
    return Status::LIMIT_EXCEEDED;

  if (n + size > Data.size())
  {
    // 1. resize array on N*GROW bytes. N = (((n+size) + GROW - 1) / GROW) * GROW
    // 2. if Tail < Head, copy min(new_size-old_size, Tail) bytes starting from first new byte of array
    // 3. adjust Tail value
  }

  // 1. copy data starting from Tail offset
  // 2. adjust Tail

  return Status::OK;
}

Status Buffer::Read(void* buffer, size_t max_size, size_t& nread)
{
  // Implement read

  return Size() ? Status::OK : Status::EMPTY;
}

size_t Buffer::Size() const
{
  size_t n = Data.size();
  return Tail > Head ? Tail - Head : (n - Head) + Tail;
}