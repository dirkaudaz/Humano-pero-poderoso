#pragma once

#include <initializer_list>
#include <map>

#include "player_state.h"
#include "../actions/action.h"
#include "../elements/worker.h"

namespace Entities
{
  class GameState
  {
  public:
    GameState(std::initializer_list<PlayerState> player_states);

    GameState(const GameState& state);
  
    PlayerState& get_player_state(const Elements::Worker &worker);
  private:
    std::map<uint32_t, PlayerState> player_states;
    std::vector<std::tuple<Actions::Action, bool>> actions;
  };
}

