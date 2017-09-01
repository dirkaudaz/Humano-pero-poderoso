#pragma once

#include <cstddef>
#include <string>

namespace Util
{
  
  template<std::size_t N>
  constexpr size_t simple_hash(const char(&str)[N])
  {
    std::size_t hash = 0;
    for (size_t i = 0; i < (N - 1); i++)
    {
      hash = hash*47 + str[i]; 
    }
    return hash;
  }

  size_t simple_hash(const std::string &str)
  {
    std::size_t hash = 0;
    for (auto c : str)
    {
std::cout << static_cast<std::size_t>(c) << std::endl;
      hash = hash*47 + c; 
    }
    return hash;
  }

}
