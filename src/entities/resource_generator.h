#pragma once

#include "player_state.h"
#include "../types/resources.h"

namespace Entities
{
  class ResourceGenerator
  {
  public:
    ResourceGenerator(Types::Resources type, int value);
    void apply(PlayerState &state) const;

  private:
    Types::Resources resource_type;
    int value;

  };
}
