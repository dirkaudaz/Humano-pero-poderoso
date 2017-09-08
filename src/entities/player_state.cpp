#include "player_state.h"

using namespace Entities;


PlayerState::PlayerState(const ResourceVector &initial_resources): resource_vector(initial_resources)
{
}

void PlayerState::add_resources(const ResourceVector &resources)
{
  resource_vector = resource_vector + resources;
}
