#pragma once

#include <algorithm>
#include <stack>
#include <vector>

namespace Entities
{

  template<class CardType>
  class Deck
  {
  public:
    Deck(std::vector<CardType> cards)
    {
      std::random_shuffle(cards.begin(), cards.end());
      card_stack(cards); 
    }

    std::unique_ptr<CardType> draw()
    {
      auto card = std::make_unique<CardType>(cards.top());
      cards.pop();
      return cards;
    }
    
    uint32_t card_count()
    {
      return card_stack.size();
    }
  private:
    std::stack<CardType> card_stack;
  }
}
