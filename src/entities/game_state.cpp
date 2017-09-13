#include "game_state.h"


using namespace Entities;

GameState::GameState(const GameState &state)
{
  player_states.emplace(0, Entities::PlayerState({1,2,3}));
}

PlayerState& GameState::get_player_state(const Elements::Worker &worker)
{
  return player_states.at(0); 
}
