// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_HERO_POWER_HPP
#define HEARTHSTONEPP_HERO_POWER_HPP

#include <hspp/Models/Entity.hpp>

namespace Hearthstonepp
{
//!
//! \brief HeroPower class.
//!
//! This class inherits from Entity structure.
//!
class HeroPower : public Entity
{
 public:
    //! Default constructor.
    HeroPower() = default;

    //! Constructs hero power with given \p _owner and \p _card.
    //! \param _owner An owner of the card.
    //! \param _card A reference to the card.
    HeroPower(Player& _owner, Card& _card);

    //! Default destructor.
    ~HeroPower() = default;

    //! Default copy constructor.
    HeroPower(const HeroPower& power) = default;

    //! Default move constructor.
    HeroPower(HeroPower&& power) = default;

    //! Default copy assignment operator.
    HeroPower& operator=(const HeroPower& power) = default;

    //! Default move assignment operator.
    HeroPower& operator=(HeroPower&& power) = default;

    //! Destroys hero power.
    void Destroy() override;
};
}  // namespace Hearthstonepp

#endif  // HEARTHSTONEPP_HERO_POWER_HPP