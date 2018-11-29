// File:	hand.cpp
// Purpose:	Implement member functions for the hand class

#include<sstream>
#include "hand.h"

void Hand::assignValue()
{
	// Loop through hand, add point values of each card
	int sum = 0;
	int aceSum = 0;
	int isAce = 0;
	for (int i = 0; i < cards.size(); i++)
	{
		int cardValue, acecardValue = 0;
		if (cards[i].point >= 11 && cards[i].point <= 13)
			cardValue = 10;
		else if (cards[i].point == 14)
		{
			isAce = 1;
			hasAce = 1;
			cardValue = 11;
			acecardValue = 1;
		}
		else
			cardValue = cards[i].point;
		
		sum += cardValue;
		if (isAce == 1)
			aceSum += acecardValue;
		else
			aceSum += cardValue;
		isAce = 0;
	} // Sum and aceSum now hold the values for value and Acevalue, respectively
	
	// Bust if over 21
	if (sum > 21)
		value = 0;
	else
		value = sum;
	if (aceSum > 21)
		Acevalue = 0;
	else
		Acevalue = aceSum;
	
	// End hand if busted
	if (hasAce != 0)
	{
		if (value == 0 && Acevalue == 0)
			done = 1;
	}
	else
	{
		if (value == 0)
			done = 1;
	}
} // DONT FORGET ABOUT SPLITTING (I'll do this later maybe)

void Hand::hit(Deck &deck)
{
	cards.push_back(deck.deal_a_card());
}

void Hand::stand()
{
	done = 1;
	return;
}

void Hand::doubledown(Deck deck)
{
	cards.push_back(deck.deal_a_card());
}

void Hand::split(Deck deck)
{
	// Take card from hand and put it into split hand
	splitHand.push_back(cards[1]);
	cards.pop_back();

	// Deal two new cards into each new hand
	splitHand.push_back(deck.deal_a_card());
	cards.push_back(deck.deal_a_card());
}

void Hand::print()
{
	for (int i = 0; i < cards.size(); i++)
	{
		cards[i].print();
	}
	assignValue();

	string printValue;
	if (value == 0)
		printValue = "BUST";
	else
	{
		std::stringstream ss;
		ss << value;
		printValue = ss.str();
	}
	if (hasAce == 1)
	{
		if (value == 0 && Acevalue == 0)
		{
			done = 1;
			//cout << "BUSTED" << endl;
		}
		//else
			//cout << "Total: " << printValue << " or " << Acevalue << endl;
	}
	else
	{
		if (printValue == "BUST")
			done = 1;
		//cout << "Total: " << printValue << endl << endl;
	}
}

void Hand::reset()
{
	int size = cards.size();
	for (int i = 0; i < size; i++)
		cards.pop_back();
	value = 0;
	hasAce = 0;
	Acevalue = 0;
	done = 0;
	is16v7 = 0;
}


