#include <Swap/Medium.h>

using namespace Swap;

Medium::Medium(MediumType type)
  : Type(type)
{
}

Medium::~Medium()
{
}

MediumType Medium::GetType() const
{
  return Type;
}
