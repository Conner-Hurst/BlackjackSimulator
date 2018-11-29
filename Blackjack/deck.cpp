// File:	deck.cpp
// Purpose:	Implementation of member functions for the deck class

#include <random>
#include "deck.h"

void Deck::createDeck()
{
	for (int i = 1; i < 5; i++)
	{
		Card::cSuits suit = Card::cSuits(i);
		for (int j = 2; j < 15; j++)
		{
			deck.push_back(Card(suit, j));
		}
	}
}

void Deck::create8Deck()
{
	for (int i = 0; i < 8; i++)
	{
		createDeck();
	}
}

void Deck::shuffleDeck()
{
	//std::random_shuffle(deck.begin(), deck.end());
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(deck.begin(), deck.end(), g);
}

Card Deck::deal_a_card()
{
	Card dealt = deck.back();
	deck.pop_back();
	return dealt;
}
