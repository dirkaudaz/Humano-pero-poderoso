#include "game_state.h"


using namespace Entities;

GameState::GameState(std::initializer_list<PlayerState> initial_states)
{
  size_t i = 0;
  for(auto player_state : initial_states)
  {
    player_states.emplace(i++, player_state);
  }
}

GameState::GameState(const GameState &state)
{
  player_states.emplace(0, Entities::PlayerState({1,2,3}));
}

PlayerState& GameState::get_player_state(const Elements::Worker &worker)
{
  return player_states.at(0); 
}
