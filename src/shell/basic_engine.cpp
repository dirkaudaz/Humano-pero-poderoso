#include "basic_engine.h"

using namespace Shell;

BasicEngine::BasicEngine(std::vector<Actions::ResourceGeneration>&& generators): generators(generators)
{
}

void BasicEngine::display_state(std::ostream &output_stream) const
{
  for (auto generator : generators)
  {
    output_stream << generator.to_string();
  }
}

void BasicEngine::display_prompt(std::ostream &output_stream) const
{
  output_stream << "hpp 0.0.1> ";
}

bool BasicEngine::handle_command(const std::string &command)
{
  return true;
}
