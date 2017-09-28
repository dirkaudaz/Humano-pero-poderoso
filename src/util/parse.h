#pragma once

#include <string>
#include <type_traits>

namespace Util
{
  template<typename T>
  T parse(std::string str)
  {
    if constexpr (std::is_same_v<int, T>)
    {
      return std::stoi(str);
    }
    else
    {
       return str;
    }
  }
}
