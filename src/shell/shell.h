#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../util/hash.h"

constexpr size_t QUIT_COMMAND = Util::simple_hash("quit");
constexpr size_t HELP_COMMAND = Util::simple_hash("help");

namespace Shell
{

  template<class Engine>
  class Shell
  {
  public:
    Shell(std::unique_ptr<Engine> e): engine(std::move(e))
    {
std::cout << "Quit: " << QUIT_COMMAND << std::endl;
std::cout << "Help: " << HELP_COMMAND << std::endl;
    }

    bool run()
    {
      std::string command;
      do
      {
        engine->display_state(std::cout);
        std::cin >> command;
      }
      while (handle_command(command));
      return true;
    }
  private:
    std::unique_ptr<Engine> engine;

    bool handle_command(const std::string &command)
    {
       auto hash =  Util::simple_hash(command);
std::cout << "Hash: " << hash << std::endl;
       switch(hash)
       {
       case QUIT_COMMAND:
         return false;
       case HELP_COMMAND:
         break;
       default:
         engine->handle_command(command);
         break;
       }
       return true;
    }
  };

}
