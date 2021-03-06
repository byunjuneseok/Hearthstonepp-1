// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_CONTROL_TASK_HPP
#define HEARTHSTONEPP_CONTROL_TASK_HPP

#include <hspp/Tasks/Tasks.hpp>

namespace Hearthstonepp::SimpleTasks
{
//!
//! \brief ControlTask class.
//!
//! This class represents the task for taking control.
//!
class ControlTask : public ITask
{
 public:
    //! Constructs task with given \p entityType.
    //! \param entityType The entity type of target to take control.
    explicit ControlTask(EntityType entityType);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    TaskStatus Impl(Player& player) override;
};
}  // namespace Hearthstonepp::SimpleTasks

#endif  // HEARTHSTONEPP_CONTROL_TASK_HPP
