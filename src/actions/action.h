#include <string>

#include "../elements/worker.h"
#include "../entities/game_state.h"

namespace Actions
{
  class Action
  {
    virtual Entities::GameState execute(const Entities::GameState &current_state, const Elements::Worker &worker) = 0;
  };
}
