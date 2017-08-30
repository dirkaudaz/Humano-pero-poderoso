#pragma once

#include "player_state.h"

namespace Entities
{
  class GameState
  {
  public:
    GameState(const GameState& state);
  
    PlayerState& get_player_state(const Elements::Worker &worker);
  };
}

