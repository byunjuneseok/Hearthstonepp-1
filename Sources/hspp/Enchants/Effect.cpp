// This code is based on Sabberstone project.
// Copyright (c) 2017-2018 SabberStone Team, darkfriend77 & rnilva
// Hearthstone++ is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#include <hspp/Enchants/Effect.hpp>
#include <hspp/Models/Character.hpp>

namespace Hearthstonepp
{
Effect::Effect(GameTag gameTag, EffectOperator effectOperator, int value)
    : m_gameTag(gameTag), m_effectOperator(effectOperator), m_value(value)
{
    // Do nothing
}

void Effect::Apply(Character* character, bool isOneTurnEffect) const
{
    if (isOneTurnEffect)
    {
        // TODO: Process one turn effect
    }

    const int prevValue = character->GetGameTag(m_gameTag);

    switch (m_effectOperator)
    {
        case EffectOperator::ADD:
            character->SetGameTag(m_gameTag, prevValue + m_value);
            break;
        case EffectOperator::SUB:
            character->SetGameTag(m_gameTag, prevValue - m_value);
            break;
        case EffectOperator::MUL:
            character->SetGameTag(m_gameTag, prevValue * m_value);
            break;
        case EffectOperator::SET:
            character->SetGameTag(m_gameTag, m_value);
            break;
        default:
            throw std::invalid_argument("Invalid effect operator!");
    }
}
}  // namespace Hearthstonepp