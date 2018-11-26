// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_PLAY_MINION_TASK_HPP
#define HEARTHSTONEPP_PLAY_MINION_TASK_HPP

#include <hspp/Tasks/Requirement.hpp>
#include <hspp/Tasks/TaskAgent.hpp>
#include <hspp/Tasks/Tasks.hpp>

namespace Hearthstonepp::PlayerTasks
{
//!
//! \brief PlayMinionTask class.
//!
//! This class represents the task for playing minion.
//! It summons minion and processes power.
//!
class PlayMinionTask : public ITask
{
 public:
    //! Constructs task with given \p agent and \p entity.
    //! \param agent The task agent that interacts with game interface.
    //! \param source A pointer to source entity to play card.
    //! \param fieldPos A value indicating where to place card.
    //! \param target A target of the card to receive power.
    PlayMinionTask(TaskAgent& agent, Entity* source = nullptr,
                   int fieldPos = -1, Entity* target = nullptr);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    MetaData Impl(Player& player) override;

    Requirement m_requirement;
    int m_fieldPos = -1;
};
}  // namespace Hearthstonepp::PlayerTasks

#endif  // HEARTHSTONEPP_PLAY_MINION_TASK_HPP