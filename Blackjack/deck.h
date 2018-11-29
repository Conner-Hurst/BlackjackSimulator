// File: deck.h
// Purpose: Declaring the class for a deck of playing cards


#ifndef DECK_H
#define DECK_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "card.h"

using namespace std;

// Constants for a standard 52-card deck
const int CARD_START = 2;	// First card is 2
const int SUITS = 4;		// 4 suits in a deck
const int RANKS = 13;		// 13 different point values

class Deck
{
	public:
		// Create standard 52-card deck
		void createDeck();

		// Create standard 8-deck blackjack deck
		void create8Deck();

		// Shuffle cards
		void shuffleDeck();

		// Return a card from the tail of the deck
		Card deal_a_card();

		vector<Card> deck;
};
#endif