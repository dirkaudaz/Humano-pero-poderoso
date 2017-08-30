#pragma once

#include <string>
#include <vector>

#include "action.h"
#include "../elements/worker.h"
#include "../entities/game_state.h"
#include "../entities/resource_generator.h"

namespace Actions
{

  class ResourceGeneration: Action
  {
  public:

    ResourceGeneration(const std::string name, std::vector<Entities::ResourceGenerator> generators);
    
    Entities::GameState execute(const Entities::GameState &current_state, const Elements::Worker &worker);

  private:
    std::vector<Entities::ResourceGenerator> generators; 
  };
}
