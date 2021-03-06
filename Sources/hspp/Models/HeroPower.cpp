// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <hspp/Models/HeroPower.hpp>

namespace Hearthstonepp
{
HeroPower::HeroPower(Player& _owner, Card& _card) : Entity(_owner, _card)
{
    // Do nothing
}

void HeroPower::Destroy()
{
    // Do nothing
}
}  // namespace Hearthstonepp