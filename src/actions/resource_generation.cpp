#include "resource_generation.h"

#include "../entities/player_state.h"

using namespace Actions;

ResourceGeneration::ResourceGeneration(const std::string name, std::vector<Entities::ResourceGenerator> generators)
{
}

Entities::GameState ResourceGeneration::execute(const Entities::GameState &current_state, const Elements::Worker &worker)
{
  Entities::GameState new_state(current_state);
  auto& player_state = new_state.get_player_state(worker); 
  for (auto &generator : generators)
  {
    generator.apply(player_state);
  }
  return new_state; 
} 
