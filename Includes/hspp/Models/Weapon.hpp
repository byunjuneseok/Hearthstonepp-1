// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_WEAPON_HPP
#define HEARTHSTONEPP_WEAPON_HPP

#include <hspp/Models/Entity.hpp>

namespace Hearthstonepp
{
//!
//! \brief Weapon class.
//!
//! This class inherits from Entity class.
//! Also, it stores durability that shows the number of times you can use that
//! weapon before it is destroyed.
//!
class Weapon : public Entity
{
 public:
    //! Default constructor.
    Weapon() = default;

    //! Constructs weapon with given \p _owner and \p _card.
    //! \param _owner An owner of the card.
    //! \param _card A reference to the card.
    Weapon(Player& _owner, Card& _card);

    //! Default destructor.
    virtual ~Weapon() = default;

    //! Default copy constructor.
    Weapon(const Weapon& weapon) = default;

    //! Default move constructor.
    Weapon(Weapon&& weapon) = default;

    //! Default copy assignment operator.
    Weapon& operator=(const Weapon& weapon) = default;

    //! Default move assignment operator.
    Weapon& operator=(Weapon&& weapon) = default;

    //! Returns the value of attack.
    //! \return The value of attack.
    virtual std::size_t GetAttack() const;

    //! Sets the value of attack.
    //! \param attack the value of attack.
    void SetAttack(std::size_t attack);

    //! Returns the value of durability.
    //! \return The value of durability.
    virtual std::size_t GetDurability() const;

    //! Sets the value of durability.
    //! \param durability the value of durability.
    void SetDurability(std::size_t durability);

    //! Destroys weapon.
    void Destroy() override;

 protected:
    std::size_t m_attack = 0;
    std::size_t m_durability = 0;
};
}  // namespace Hearthstonepp

#endif  // HEARTHSTONEPP_WEAPON_HPP