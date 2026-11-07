#ifndef DECK_H
#define DECK_H

#include "card.h"

class deck
{
    public:


        virtual void initializeDeck() = 0;
        virtual bool addCard(Card c) = 0;
        virtual bool mergeDecks(deck &otherDeck, bool rearrange) = 0;
        void shuffle();
        bool isEmpty();
        int getNumCards();
        void printDeck();
        void displayCard(int i);
        Card dealCard();

    protected: 
		Card * deck_;	
		int numCards_;	
};
#endif