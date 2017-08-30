#include <string>

#include "base_card.h"

class ResourceCard: BaseCard
{
public:
  static ResourceCard deserialize(const std::string &serialized_value);
}
