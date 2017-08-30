#include "resource_generator.h"

using namespace Entities;

ResourceGenerator::ResourceGenerator(Types::Resources type, int value): resource_type(type), value(value)
{
}

void ResourceGenerator::apply(PlayerState &state) const
{
  state.add_resource(resource_type, value);
}


