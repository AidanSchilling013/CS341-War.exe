#ifndef NONSTANDARDDECK_H
#define NONSTANDARDDECK_H

#include "deck.h"

class nonStandardDeck : public deck
{
    public:
		/// Default constructor.
		nonStandardDeck();
		
		/// Default destructor.
		~nonStandardDeck();

        bool addCard(Card c);

        void initializeDeck(); 

        bool mergeDecks(deck &otherDeck, bool rearrange);

    private:
        int deckSize_;
};


#endif