#include <iostream>
#include <string>

#include "util/parser.h"
#include "actions/resource_generation.h"
#include "shell/basic_engine.h"
#include "shell/shell.h"

int main(int argc, char** argv)
{
  auto generators = Util::file_parser<Actions::ResourceGeneration>(argv[1]);
  Shell::Shell<Shell::BasicEngine, std::cout, std::cin> shell(Shell::BasicEngine(std::move(generators)));
  shell.run();
  return 0;
}
