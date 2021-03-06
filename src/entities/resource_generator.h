#pragma once

#include <string>

#include "player_state.h"
#include "resource_vector.h"
#include "../types/resources.h"

namespace Entities
{
  class ResourceGenerator
  {
  public:
    ResourceGenerator(const ResourceVector &vector);

    void apply(PlayerState &state) const;

    std::string to_string() const;

  private:
    ResourceVector resource_vector;

  };
}
