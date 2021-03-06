// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_BASIC_POLICY_HPP
#define HEARTHSTONEPP_BASIC_POLICY_HPP

#include <hspp/Policies/Policy.hpp>

#include <functional>

namespace Hearthstonepp
{
//!
//! \brief BasicPolicy class.
//!
//! The purpose of this class is easier implementation of IPolicy for GameAgent.
//!
class BasicPolicy : public IPolicy
{
 public:
    //! Default constructor.
    BasicPolicy() = default;

    //! Default destructor.
    ~BasicPolicy() = default;

    //! Gets next behavior from given \p game.
    //! \param game The current game status.
    //! \return The behavior serialized as TaskMeta.
    TaskMeta Next(const Game& game) override;

    //! Gets proper requirement with given \p player and \p id.
    //! \param player The player who requests the requirement.
    //! \param id The requested TaskID.
    TaskMeta Require(Player& player, TaskID id) override;

    //! Notify serialized data to IPolicy.
    //! \param meta The serialized data.
    void Notify(const TaskMeta& meta) override;

 private:
    //! Virtual method for MulliganTask requirement.
    virtual TaskMeta RequireMulligan(Player& player);

    //! Virtual method for PlaySpellTask requirement.
    virtual TaskMeta RequirePlaySpell(Player& player);

    //! Virtual method for PlayCardTask requirement.
    virtual TaskMeta RequirePlayCard(Player& player);

    //! Virtual method for PlayMinionTask requirement.
    virtual TaskMeta RequirePlayMinion(Player& player);

    //! Virtual method for CombatTask requirement.
    virtual TaskMeta RequireCombat(Player& player);

    //! Virtual method for OverDraw notifying.
    virtual void NotifyOverDraw(const TaskMeta& meta);

    std::map<TaskID, std::function<TaskMeta(BasicPolicy&, Player&)>>
        m_require = {
            { TaskID::MULLIGAN, &BasicPolicy::RequireMulligan },
            { TaskID::PLAY_SPELL, &BasicPolicy::RequirePlaySpell },
            { TaskID::PLAY_CARD, &BasicPolicy::RequirePlayCard },
            { TaskID::PLAY_MINION, &BasicPolicy::RequirePlayMinion },
            { TaskID::COMBAT, &BasicPolicy::RequireCombat },
        };

    std::map<TaskID, std::function<void(BasicPolicy&, const TaskMeta&)>>
        m_notify = {
            { TaskID::OVERDRAW, &BasicPolicy::NotifyOverDraw },
        };
};
}  // namespace Hearthstonepp

#endif  // HEARTHSTONEPP_BASIC_POLICY_HPP