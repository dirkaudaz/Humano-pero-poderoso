#pragma once

#include <istream>
#include <ostream>
#include <string>
#include <vector>

#include "../actions/resource_generation.h"

namespace Shell
{

  class BasicEngine
  {
  public:
    BasicEngine(std::vector<Actions::ResourceGeneration>&& generators);

    void display_state(std::ostream &output_stream) const;
    void display_prompt(std::ostream &output_stream) const;;
    bool handle_command(const std::string &command);

  private:
    std::vector<Actions::ResourceGeneration> generators;
  };

}
