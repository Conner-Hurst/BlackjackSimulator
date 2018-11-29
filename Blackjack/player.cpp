// File:	player.cpp
// Purpose: Implement member functions for the player class

#include "player.h"

void Player::turn(Card dealerCard, Deck deck)
{
	int showCard = dealerCard.point;
	
	while (hand.done != 1)
	{
		// If there's no ace
		if (hand.hasAce != 1)
		{
			if (hand.value >= 4 && hand.value <= 11)
				hand.hit(deck);
			else if (hand.value == 12)
			{
				if (showCard == 4 || showCard == 5 || showCard == 6)
					hand.stand();
				else
					hand.hit(deck);
			}
			else if (hand.value >= 13 && hand.value <= 16)
			{
				// EXTRA CHANGE - STAY WHEN 16 AGAINST A 8
				if (hand.value == 16 && showCard == 9)
				{
					hand.is16v7 = 1;
					sixteen_v_seven++;
					//hand.stand();
					hand.hit(deck);
				}
				else if (showCard >= 2 && showCard <= 8)
					hand.stand();
				else
					hand.hit(deck);
			}
			else
				hand.stand();
			hand.assignValue();
		}
		// If there is an ace
		else
		{
			// If the ace counts as 11
			if (hand.value != 0)
			{
				if (hand.value > 0 && hand.value <= 17)
					hand.hit(deck);
				else if (hand.value == 18)
				{
					if (showCard >= 2 && showCard <= 8)
						hand.stand();
					else
						hand.hit(deck);
				}
				else
					hand.stand();
			}
			// If the ace counts as 1
			else
			{
				if (hand.Acevalue >= 4 && hand.Acevalue <= 11)
					hand.hit(deck);
				else if (hand.Acevalue == 12)
				{
					if (showCard == 4 || showCard == 5 || showCard == 6)
						hand.stand();
					else
						hand.hit(deck);
				}
				else if (hand.Acevalue >= 13 && hand.Acevalue <= 16)
				{
					// CONTINUATION OF THE EXTRA
					if (hand.Acevalue == 16 && showCard == 9)
					{
						hand.is16v7 = 1;
						sixteen_v_seven++;
						//hand.stand();
						hand.hit(deck);
					}
					if (showCard >= 2 && showCard <= 6)
						hand.stand();
					else
						hand.hit(deck);
				}
				else
					hand.stand();
				hand.assignValue();
			}
		}
		hand.assignValue();
	}
}

void Player::dealer_turn(Deck deck)
{
	while (hand.done != 1)
	{
		// If there's no ace
		if (hand.hasAce != 1)
		{
			if (hand.value <= 16)
				hand.hit(deck);
			else
				hand.stand();
		}
		// If there is an ace (must hit on soft 17)
		else
		{
			// If the ace counts as 11
			if (hand.value != 0)
			{
				if (hand.value <= 17)
					hand.hit(deck);
				else
					hand.stand();
			}
			// If the ace counts as 1
			else
			{
				if (hand.Acevalue <= 16)
					hand.hit(deck);
				else
					hand.stand();
			}
		}
		hand.assignValue();
	}
}

bool Player::playerWin(Player dealer)
{
	int playerScore = 0;
	int dealerScore = 0;
	
	// Decide player's score to compare
	// If player has an ace
	if (hand.hasAce != 0)
	{
		// Primarily use 'value'
		if (hand.value != 0)
			playerScore = hand.value;
		// Otherwise, use Acevalue
		else
		{
			if (hand.Acevalue != 0)
				playerScore = hand.Acevalue;
			// Lose because bust
			else
				return false;
		}
	}
	// If player doesn't have an ace, use 'value'
	else
		playerScore = hand.value;

	// Decide dealer's score to compare
	// If dealer has ace
	if (dealer.hand.hasAce != 0)
	{
		// Primarily use 'value'
		if (dealer.hand.value != 0)
			dealerScore = dealer.hand.value;
		// Otherwise, use Acevalue
		else
		{
			if (hand.Acevalue != 0)
				dealerScore = dealer.hand.Acevalue;
			// Win because dealer bust
			// NOTE: It should be checking if the player busted before this (above)
			//       so if they both bust it should be a loss for the player
			else
				return true;
		}
	}
	// If dealer doesn't have ace, use value
	else
		dealerScore = dealer.hand.value;

	// Now, compare player's and dealer's scores (ties are losses)
	if (playerScore > dealerScore)
		return true;
	else
		return false;
}
