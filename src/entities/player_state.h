#pragma once

#include "resource_vector.h"
#include "../types/resources.h"

namespace Entities
{
  class PlayerState
  {
  public:
    PlayerState(const ResourceVector &initial_resources);

    const ResourceVector &get_current_resources() const;

    void add_resources(const ResourceVector &value);


  private:
    ResourceVector resource_vector;
  };
 
}
