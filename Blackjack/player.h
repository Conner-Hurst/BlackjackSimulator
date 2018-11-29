// File:	player.h
// Purpose: Declare the player class

#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class Player
{
	public:

		// The player takes their turn
		// This includes the logic for when they should hit, stay, etc.
		void turn(Card dealerCard, Deck deck);

		// The dealer takes their turn
		// Includes all logic for when dealers need to hit, stay, etc.
		void dealer_turn(Deck deck);

		// Decides winner between player and dealer
		bool playerWin(Player dealer);

		// The player's hand
		Hand hand;
		int wins;
		int sixteen_v_seven;
		int sixteen_v_seven_wins;
};
#endif