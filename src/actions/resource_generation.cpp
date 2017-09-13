#include "resource_generation.h"

#include <string>
#include <sstream>

#include "../entities/player_state.h"
#include "../util/string_tokenizer.h"

using namespace Actions;

ResourceGeneration ResourceGeneration::deserialize(std::string &serialized)
{
  std::string name, support_str, money_str, corruption_str;
  Util::tokenize<','>(serialized, name, support_str, money_str, corruption_str);
  int support = std::stoi(support_str),
      money = std::stoi(money_str),
      corruption = std::stoi(corruption_str);
  Entities::ResourceGenerator generator({ support, money, corruption });
  return ResourceGeneration(name, generator);
}

ResourceGeneration::ResourceGeneration(const std::string &name, const Entities::ResourceGenerator &generator): name(name), generator(generator)
{
}

Entities::GameState ResourceGeneration::execute(const Entities::GameState &current_state, const Elements::Worker &worker)
{
  Entities::GameState new_state(current_state);
  auto& player_state = new_state.get_player_state(worker); 
  generator.apply(player_state);
  return new_state; 
} 

std::string ResourceGeneration::to_string() const
{
  std::ostringstream oss;
  oss << "Name: " << name << std::endl;
  oss << "Generator:" << std::endl;
  oss << generator.to_string() << std::endl;
  return oss.str();
}
