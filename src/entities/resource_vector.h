#pragma once

#include "../types/resources.h"
#include "../util/tagged_tuple.h"

namespace Entities
{

   using ResourceVector = Util::tagged_tuple<Types::Resources, int, Types::Resources::Support, Types::Resources::Money, Types::Resources::Corruption>;

}
