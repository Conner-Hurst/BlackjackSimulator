// Program: card.h
// Purpose: Declaring the class for a playing card

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

// Unicode for the four suits (display purposes only)
const char SPADE[] = "s";
const char CLUB[] = "c";
const char HEART[] = "h";
const char DIAMOND[] = "d";

class Card
{
	public:
		// Type definition for suits of a playing card. Invalid means the card hasn't been initialized.
		typedef enum {Invalid, Spade, Club, Heart, Diamond} cSuits;

		// Type definition for the point value of a playing card. 0 means the card hasn't been initialized.
		typedef unsigned int cPoints;

		// Default constructor
		Card();

		// Alternate constructor. Creates card with specified suit and point.
		Card(cSuits s, cPoints p);

		// Compare with another card, determine which is higher
		int compareTo(Card other);

		// Display a description of the card to the output. Looks like (suit)(point)(suit)
		void print();

		cSuits suit;	// Suit of the card
		cPoints point;	// Point value

}; 
#endif