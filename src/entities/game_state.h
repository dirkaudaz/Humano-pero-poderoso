#pragma once

#include <map>

#include "player_state.h"
#include "../elements/worker.h"

namespace Entities
{
  class GameState
  {
  public:
    GameState(const GameState& state);
  
    PlayerState& get_player_state(const Elements::Worker &worker);
  private:
    std::map<uint32_t, PlayerState> player_states;
  };
}

