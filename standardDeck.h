#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include "card.h"
#include "deck.h"

#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck : public deck
{
	public:
		/// Default constructor.
		StandardDeck();
		
		/// Default destructor.
		~StandardDeck();

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		//bool isEmpty();	

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		//int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		//void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		//void printDeck();	

		/**
	     * returns TRUE/FALSE whether the deck is full or not.
		 * adds a card if its not full
	    */
		bool addCard(Card c);
		
		/**
	     * initializes the deck with 52 cards
		 * 
	    */
		void initializeDeck(); 

		/**
	     * shuffles the deck 
		 * 
	    */
		//void shuffle();

		/**
		 * This method should take Cards from an input StandardDeck and merge them with the
		current StandardDeck. The Boolean input parameter indicates whether or not we want
		to then shuffle (Default = FALSE). The output in this case should return TRUE on
		successful addition.
		 * 
		 */
		bool mergeDecks(deck &otherDeck, bool rearrange);

		/**
		 * This method will return the top most (the Card with the highest index value) Card on the
		 * Deck.
		 */
		//Card dealCard();


	
};

#endif