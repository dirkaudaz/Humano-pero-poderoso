#pragma once

#include "../types/resources.h"

namespace Entities
{
  class PlayerState
  {
  public:
    void add_resource(const Types::Resources type, int value);
  };
}
