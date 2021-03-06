// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <hspp/Tasks/SimpleTasks/ControlTask.hpp>
#include <hspp/Tasks/SimpleTasks/IncludeTask.hpp>

namespace Hearthstonepp::SimpleTasks
{
ControlTask::ControlTask(EntityType entityType) : ITask(entityType)
{
    // Do nothing
}

TaskID ControlTask::GetTaskID() const
{
    return TaskID::CONTROL;
}

TaskStatus ControlTask::Impl(Player& player)
{
    auto entities =
        IncludeTask::GetEntities(m_entityType, player, m_source, m_target);
    auto& myField = player.GetField();
    auto& opField = player.GetOpponent().GetField();

    for (auto& entity : entities)
    {
        const auto minion = dynamic_cast<Minion*>(entity);
        if (minion == nullptr)
        {
            continue;
        }

        const auto opMinionPos = opField.FindMinionPos(*minion).value_or(
            std::numeric_limits<std::size_t>::max());
        if (opMinionPos == std::numeric_limits<std::size_t>::max())
        {
            return TaskStatus::CONTROL_INVALID_TARGET;
        }

        const auto myMinionPos = myField.FindEmptyPos().value_or(
            std::numeric_limits<std::size_t>::max());
        if (myMinionPos == std::numeric_limits<std::size_t>::max())
        {
            return TaskStatus::CONTROL_FIELD_IS_FULL;
        }

        const auto minionClone = new Minion(*minion);
        myField.AddMinion(*minionClone, myMinionPos);
        opField.RemoveMinion(*minion);
    }

    return TaskStatus::CONTROL_SUCCESS;
}
}  // namespace Hearthstonepp::SimpleTasks
