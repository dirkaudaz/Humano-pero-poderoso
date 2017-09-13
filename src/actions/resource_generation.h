#pragma once

#include <string>

#include "action.h"
#include "../elements/worker.h"
#include "../entities/game_state.h"
#include "../entities/resource_generator.h"

namespace Actions
{

  class ResourceGeneration: Action
  {
  public:
    static ResourceGeneration deserialize(std::string &serialized);

    ResourceGeneration(const std::string &name, const Entities::ResourceGenerator &generator);
    
    Entities::GameState execute(const Entities::GameState &current_state, const Elements::Worker &worker);

    std::string to_string() const;

  private:
    std::string name;
    Entities::ResourceGenerator generator;
  };
}
