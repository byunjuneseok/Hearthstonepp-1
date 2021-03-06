// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_CARD_LOADER_HPP
#define HEARTHSTONEPP_CARD_LOADER_HPP

#include <hspp/Cards/Card.hpp>

#include <json/json.hpp>

#include <vector>

namespace Hearthstonepp
{
//!
//! \brief CardLoader class.
//!
//! This class loads card data from cards.json.
//!
class CardLoader
{
 public:
    //! Loads card data from cards.json.
    //! \param cards Data storage to store added cards with power.
    static void Load(std::vector<Card>& cards);
};
}  // namespace Hearthstonepp

#endif  // HEARTHSTONEPP_CARD_LOADER_HPP