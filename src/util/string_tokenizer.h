#pragma once

#include <sstream>
#include <string>
#include <tuple>

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

    template<char delim>
    struct tok_impl<delim, std::string>
    {
      static std::tuple<std::string> tok(std::istringstream &iss)
      {
        std::string s;
        std::getline(iss, s, delim);
        return { s };
      }
    };

    template<char delim>
    struct tok_impl<delim, int>
    {
      static std::tuple<int> tok(std::istringstream &iss)
      {
        std::string s;
        std::getline(iss, s, delim);
        return { std::stoi(s) };
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
