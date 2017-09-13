#include "resource_generator.h"

#include <sstream>

using namespace Entities;

ResourceGenerator::ResourceGenerator(const ResourceVector &vector): resource_vector(vector)
{
}

void ResourceGenerator::apply(PlayerState &state) const
{
  state.add_resources(resource_vector);
}

std::string ResourceGenerator::to_string() const
{
  std::ostringstream oss;
  oss << "[M, S, C] = [" << resource_vector.get<Types::Resources::Money>() << ", "
                         << resource_vector.get<Types::Resources::Support>() << ", "
                         << resource_vector.get<Types::Resources::Corruption>() << "]";
  return oss.str();
}

