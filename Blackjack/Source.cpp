#include <iostream>
#include <string>
#include <vector>
#include "deck.h"
#include "card.h"
#include "hand.h"
#include "player.h"


using namespace std;

void main()
{
	cout << "-------------------------------------" << endl;
	cout << "|             BLACKJACK             |" << endl;
	cout << "-------------------------------------" << endl;

	Player player1;
	player1.wins = 0;
	Player dealer;
	Deck deck;
	deck.create8Deck();
	deck.shuffleDeck();
	int numHands = 0;


	//string stop = "";
	//while (stop != "q" && stop != "Q")
	//{
		cout << endl << "How many hands would you like to simulate? ";
		cin >> numHands;

		for (int z = 0; z < numHands; z++)
		{
			// If deck has 52 or less cards in it, reshuffle
			if (deck.deck.size() <= 52)
			{
				// Clear old deck
				for (int y = 0; y < deck.deck.size(); y++)
					deck.deck.pop_back();
				// Create new 8 deck deck
				deck.create8Deck();
				deck.shuffleDeck();
			}
			cout << "Number processed: " << z << endl;
			// Deal out cards
			for (int i = 0; i < 2; i++)
			{
				player1.hand.cards.push_back(deck.deal_a_card());
				dealer.hand.cards.push_back(deck.deal_a_card());
			}

			// Print hands
			//cout << "Player 1's Hand:" << endl;
			player1.hand.print();
			//cout << "Dealer's Hand:" << endl;
			dealer.hand.cards[0].print();
			//cout << "?" << endl;

			//if (dealer.hand.cards[0].point == 7)
				//system("pause");
			
			// Players take turns
			//cout << "Player 1's turn!" << endl;
			player1.turn(dealer.hand.cards[0], deck);
			//cout << "Player 1's turn is over!" << endl;
			//cout << endl << "Player 1's final hand:" << endl;
			player1.hand.print();
			//cout << endl << "The dealer's hand: " << endl;
			dealer.hand.print();
			//cout << "The dealer's turn!" << endl;
			dealer.dealer_turn(deck);
			//cout << "The dealer's turn is over!" << endl;
			dealer.hand.print();

			// Decide if player won
			if (player1.playerWin(dealer))
			{
				cout << "You Win!" << endl;
				player1.wins++;

				// 16v7
				if (player1.hand.is16v7 == 1)
					player1.sixteen_v_seven_wins++;
			}

			// Clear table, reset hands
			player1.hand.reset();
			dealer.hand.reset();

			system("CLS");
		}

		cout << "---------- FINAL STATS -----------" << endl;
		cout << "Total number of hands: " << numHands << endl;
		cout << "Total number of wins: " << player1.wins << endl;
		cout << "Total number of 16v7's: " << player1.sixteen_v_seven << endl;
		cout << "Total number of 16v7 wins: " << player1.sixteen_v_seven_wins << endl;
		cout << "----------------------------------" << endl;
		//cout << "Play again? Press Q to exit. " << endl;
		//cin >> stop;
		system("pause");
	//}
}

