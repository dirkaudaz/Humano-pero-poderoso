#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>

namespace Util
{

  template<class Entity>
  std::vector<Entity> parse(const std::string &filename)
  {
     std::ifstream file(filename);
     std::vector<std::string> lines;
     std::copy(std::istream_iterator<std::string>(file),
               std::istream_iterator<std::string>(),
               std::back_inserter(lines));
     std::vector<Entity> entities;
     std::transform(lines.begin(),
                    lines.end(),
                    std::back_inserter(entities),
                    [](auto line) { return Entity::deserialize(line); });
     return entities;
  }

}
