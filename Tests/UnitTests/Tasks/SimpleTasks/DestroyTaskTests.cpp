// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Utils/TestUtils.hpp>
#include "gtest/gtest.h"

#include <hspp/Managers/GameAgent.hpp>
#include <hspp/Models/Minion.hpp>
#include <hspp/Models/Weapon.hpp>
#include <hspp/Tasks/SimpleTasks/DestroyTask.hpp>

using namespace Hearthstonepp;
using namespace SimpleTasks;
using namespace TestUtils;

TEST(DestroyTask, GetTaskID)
{
    const DestroyTask task(EntityType::EMPTY);
    EXPECT_EQ(task.GetTaskID(), +TaskID::DESTROY);
}

TEST(DestroyTask, Run)
{
    GameAgent agent(CardClass::ROGUE, CardClass::DRUID, PlayerType::PLAYER1);
    Player& player1 = agent.GetPlayer1();
    Player& player2 = agent.GetPlayer2();

    auto card = GenerateMinionCard("minion1", 1, 1);

    // Destroy Source Minion
    auto minion1 = new Minion(&agent, card);
    minion1->SetOwner(player1);
    player1.GetField().AddMinion(*minion1, 0);

    DestroyTask task1(EntityType::SOURCE);
    task1.SetSource(player1.GetField().GetMinion(0));

    MetaData result = task1.Run(player1);
    EXPECT_EQ(result, MetaData::DESTROY_SUCCESS);
    EXPECT_EQ(player1.GetField().GetNumOfMinions(), 0u);

    // Destroy Target Minion
    auto minion2 = new Minion(&agent, card);
    minion2->SetOwner(player2);
    player2.GetField().AddMinion(*minion2, 0);

    DestroyTask task2(EntityType::TARGET);
    task2.SetTarget(player2.GetField().GetMinion(0));

    MetaData result2 = task2.Run(player1);
    EXPECT_EQ(result2, MetaData::DESTROY_SUCCESS);
    EXPECT_EQ(player2.GetField().GetNumOfMinions(), 0u);

    // Destroy Target Weapon
    Card weaponCard;
    player2.GetHero()->weapon = new Weapon(&agent, weaponCard);
    player2.GetHero()->weapon->SetOwner(player2);

    DestroyTask task3(EntityType::ENEMY_WEAPON);

    MetaData result3 = task3.Run(player1);
    EXPECT_EQ(result3, MetaData::DESTROY_SUCCESS);
    EXPECT_EQ(player2.GetHero()->HasWeapon(), false);
}
