// This code is based on Sabberstone project.
// Copyright (c) 2017-2018 SabberStone Team, darkfriend77 & rnilva
// Hearthstone++ is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef HEARTHSTONEPP_TARGETING_HPP
#define HEARTHSTONEPP_TARGETING_HPP

#include <hspp/Models/Entity.hpp>

namespace Hearthstonepp::Generic
{
bool IsValidTarget(Entity* source, Entity* target);
}  // namespace Hearthstonepp::Generic

#endif  // HEARTHSTONEPP_TARGETING_HPP