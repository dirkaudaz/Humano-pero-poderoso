#pragma once

#include <ostream>
#include <istream>
#include <memory>
#include <string>

#include "../util/hash.h"

constexpr size_t QUIT_COMMAND = Util::simple_hash("quit");
constexpr size_t HELP_COMMAND = Util::simple_hash("help");

namespace Shell
{

  template<class Engine, std::ostream &output_stream, std::istream &input_stream>
  class Shell
  {
  public:
    Shell(Engine&& e): engine(e)
    {
    }

    bool run()
    {
      std::string command;
      do
      {
        engine.display_state(output_stream);
        engine.display_prompt(output_stream);
        input_stream >> command;
      }
      while (handle_command(command));
      return true;
    }
  private:
    Engine engine;

    bool handle_command(const std::string &command)
    {
       auto hash =  Util::simple_hash(command);
       switch(hash)
       {
       case QUIT_COMMAND:
         return false;
       case HELP_COMMAND:
         break;
       default:
         engine.handle_command(command);
         break;
       }
       return true;
    }
  };

}
