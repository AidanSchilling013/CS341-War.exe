#include "nonStandardDeck.h"
#include <fstream>
#include <iostream>

nonStandardDeck::nonStandardDeck() 
{
    std::ifstream file("deck.txt");
    file >> deckSize_;
    deck_ = new Card[deckSize_];
    numCards_ = 0;
}

nonStandardDeck::~nonStandardDeck() 
{
    if (deck_ != nullptr)
    {
        delete [] deck_;
    }
}

bool nonStandardDeck::addCard(Card c)
{
   if (numCards_ < deckSize_)
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

bool nonStandardDeck::mergeDecks(deck &otherDeck, bool rearrange)  //used rearrange bc shuffle was function name
{
    int otherDeckNum = otherDeck.getNumCards();
    if ((otherDeckNum + getNumCards()) <= deckSize_)
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

void nonStandardDeck::initializeDeck()
{
    int suitValue;
    int faceValue; 
    std::ifstream file("deck.txt");
    file >> deckSize_;
    if (deck_ != nullptr)  // freeing up memory when the deck is already previously initialized
    {
        delete[] deck_;
    }
    deck_ = new Card[deckSize_];
    numCards_ = deckSize_;
    
    for (int i = 0; i < deckSize_; i++) //assigning card values to deck
    {
        file >> suitValue >> faceValue;
        deck_[i].initialize(suitValue, faceValue);
    }
}