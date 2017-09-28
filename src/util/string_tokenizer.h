#pragma once

#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>

#include "parse.h"

namespace Util
{
  namespace Internal
  {
    template<char delim, typename T, typename... Ts>
    struct tok_impl
    {
      static std::tuple<T, Ts...> tok(std::istringstream &iss)
      {
        return std::tuple_cat(tok_impl<delim, T>::tok(iss), tok_impl<delim, Ts...>::tok(iss));
      }
    };

    template<char delim, typename T>
    struct tok_impl<delim, T>
    {
      static std::tuple<T> tok(std::istringstream &iss)
      {
        std::string s;
        std::getline(iss, s, delim);
        return { parse<T>(s) };
      }
    };
  }

  template<char delim, typename... Ts>
  std::tuple<Ts...> tokenize(const std::string &src)
  {
    std::istringstream iss(src);
    return Internal::tok_impl<delim, Ts...>::tok(iss);
  }
}
