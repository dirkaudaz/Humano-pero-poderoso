#include <iostream>
#include <string>

#include "util/parser.h"
#include "actions/resource_generation.h"

int main(int argc, char** argv)
{
  auto generators = Util::parse<Actions::ResourceGeneration>(argv[1]);
  for (auto generator : generators)
  {
    std::cout << generator.to_string();
  }
  return 0;
}
