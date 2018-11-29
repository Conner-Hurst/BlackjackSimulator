// File:	card.cpp
// Purpose: Implementation of member functions for the card class

#include "card.h"

// Default constructor
Card::Card()
{
	suit = Invalid;
	point = 0;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p)
{
	suit = s;
	point = p;
}

// Compare with another card and determine which is higher
int Card::compareTo(Card other)
{
	if (point > other.point)
		return 1;
	else if (point < other.point)
		return -1;
	else
		return 0;
}

// Print card to output
void Card::print()
{
	const char * printSuit = NULL;
	switch (suit)
	{
		case Spade:		printSuit = SPADE;
			break;
		case Club:		printSuit = CLUB;
			break;
		case Heart:		printSuit = HEART;
			break;
		case Diamond:	printSuit = DIAMOND;
			break;
	}

	if (point > 10)
	{
		char printPoint;
		switch (point)
		{
		case 11:	printPoint = 'J';
			break;
		case 12:	printPoint = 'Q';
			break;
		case 13:	printPoint = 'K';
			break;
		case 14:	printPoint = 'A';
			break;
		}
		//cout << printPoint << " (" << printSuit << ")" << endl;
	}
	//else
		//cout << point << " (" << printSuit << ")" << endl;
}

