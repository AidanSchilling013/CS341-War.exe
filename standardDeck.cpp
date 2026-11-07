// Honor Pledge:
//
//I pledge that I have neither given nor
// received any help on this assignment.
//
// aschilling

#include "standardDeck.h"


StandardDeck::StandardDeck() //heap
{
    deck_ = new Card[DECK_SIZE];
    numCards_ = 0;
}

StandardDeck::~StandardDeck() //destructor
{
    if (deck_ != nullptr)
    {
        delete [] deck_;
    }
}

// bool StandardDeck::isEmpty()
// {
//     if (numCards_ == 0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// // int StandardDeck::getNumCards()
// // {
// //     return numCards_;
// // }

// void StandardDeck::printDeck()
// {
//     for (int i = 0; i < numCards_; i++)
//     {
//         std::cout << deck_[i].print() << std::endl;
//     }
// }

// void StandardDeck::displayCard(int i)
// {
//     std::cout << deck_[i].print() << std::endl;
// }

bool StandardDeck::addCard(Card c)
{
   if (numCards_ < DECK_SIZE)
   {
    deck_[numCards_] = c;
    numCards_++;
    return true;
   }
   else
   {
    return false;
   }
}

// void StandardDeck::shuffle()  //replace with shuffle instead of the randomize? Swap function is also available
// {
//     for (int i = 0; i < 3; i++)
//     {
//         for (int x = 0; x < numCards_; x++)
//         {
//             int randomCard = rand() % numCards_;
//             Card temp = deck_[x];
//             deck_[x] = deck_[randomCard];
//             deck_[randomCard] = temp;
//         }
//     }
// }

void StandardDeck::initializeDeck()
{
    numCards_ = DECK_SIZE;
    int suitValue=1;
    int faceValue=1;
    for (int i = 0; i < DECK_SIZE; i++) //assigning card values to deck
    {
        deck_[i].initialize(suitValue, faceValue);
        if (faceValue == 13)
        {
            faceValue = 0;
            suitValue++;
        }
        faceValue++;
        if (suitValue > 4)
        {
            suitValue = 1;
        }
    }
}

bool StandardDeck::mergeDecks(deck &otherDeck, bool rearrange)  //used rearrange bc shuffle was function name
{
    int otherDeckNum = otherDeck.getNumCards();
    if ((otherDeckNum + getNumCards()) <= DECK_SIZE)
    {
        for (int i = otherDeckNum; i > 0; i--)
        {
            addCard(otherDeck.dealCard());
        }
        if (rearrange == true)
        {
            shuffle();
        }
        return true;

    }
    else
    {
        std::cout<<"Too many cards to merge decks"<<std::endl;
        return false;
    }
}

// Card StandardDeck:: dealCard()
// {
//     numCards_ -= 1;
//     return deck_[numCards_];
// }