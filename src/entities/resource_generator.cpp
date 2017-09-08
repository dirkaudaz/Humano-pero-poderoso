#include "resource_generator.h"

using namespace Entities;

ResourceGenerator::ResourceGenerator(const ResourceVector &vector): resource_vector(vector)
{
}

void ResourceGenerator::apply(PlayerState &state) const
{
  state.add_resources(resource_vector);
}


