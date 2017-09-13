#include <sstream>
#include <string>

namespace Util
{
  namespace Internal
  {
    template<char delim>
    void tok(std::istringstream &iss, std::string &s)
    {
      std::getline(iss, s, delim);
    }

    template<char delim, typename... Ts>
    void tok(std::istringstream &iss, std::string &s, Ts&... args)
    {
      tok<delim>(iss, s);
      tok<delim>(iss, args...);
    }  
  }

  template<char delim, typename... Ts>
  void tokenize(const std::string &src, Ts&... args)
  {
    std::istringstream iss(src);
    Internal::tok<delim>(iss, args...);
  }
}
