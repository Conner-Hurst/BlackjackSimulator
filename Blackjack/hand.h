// File:	hand.h
// Purpose: Declaring the class for a hand

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "card.h"
#include "deck.h"

class Hand
{
	public:
		// Assign the value of the hand
		void assignValue();

		// Take another card from the deck
		void hit(Deck &deck);

		// Stay with current cards
		void stand();
		
		// Take only one more card, double bet
		void doubledown(Deck deck);

		// Split hand
		void split(Deck deck);

		// Print hand
		void print();

		// Resets hand
		void reset();

		int value;
		int hasAce;
		int Acevalue;
		int done;
		vector<Card> cards;
		vector<Card> splitHand;

		int is16v7;
};
#endif

