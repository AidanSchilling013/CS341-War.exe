#include "deck.h"
#include "card.h"


bool deck::isEmpty()
{
    if (numCards_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int deck::getNumCards()
{
    return numCards_;
}

void deck::printDeck()
{
    for (int i = 0; i < numCards_; i++)
    {
        std::cout << deck_[i].print() << std::endl;
    }
}

void deck::displayCard(int i)
{
    std::cout << deck_[i].print() << std::endl;
}

void deck::shuffle()  
{
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < numCards_; x++)
        {
            int randomCard = rand() % numCards_;
            Card temp = deck_[x];
            deck_[x] = deck_[randomCard];
            deck_[randomCard] = temp;
        }
    }
}


Card deck:: dealCard()
{
    numCards_ -= 1;
    return deck_[numCards_];
}
