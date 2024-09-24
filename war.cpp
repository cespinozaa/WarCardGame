#include <iostream>
#include <list>

#include "deck.h"
#include "card.h"
#include "war.h"

War::War() {

}

War::~War() {

}

void Deck::play() {
	std::string playerName;

	std::cout << "Welcome to WAR, please enter your name: ";
	std::cin >> playerName;

	std::cout << "Hello, " << playerName << ". ";
	std::cout << "Cards are dealt and you will receive half of the deck." << std::endl;
	std::cout << "The player with the higher rank card wins the round and wins the card(s) of their opponent." << std::endl;
	std::cout << "First player to collect all 52 cards wins." << std::endl;
	std::cout << std::endl;
	std::cout << "Your number of cards: ";
	std::cout << player_list.size() << std::endl;
	std::cout << "Computer's number of cards: ";
	std::cout << computer_list.size() << std::endl;

	bool gameOver = false;
	std::string playString;
	playString = "Y";

	while (playString == "Y" && gameOver == false) {

		std::cout << std::endl;

		std::string roundString;
		std::cout << "Enter R to play the round: ";
		std::cin >> roundString;

		std::cout << "Your card is: ";
		std::cout << player_list.front()->print() << std::endl;

		std::cout << "Computer's card is: ";
		std::cout << computer_list.front()->print() << std::endl;

		std::cout << std::endl;

		int compare = (player_list.front())->compareValue(*computer_list.front());

		switch (compare) {
		case 0:
			std::cout << "This means war!!!!!!!! " << std::endl;
			break;
		case 1:
			std::cout << "You win this round!" << std::endl;
			break;
		case -1:
			std::cout << "Computer wins this round!" << std::endl;
			break;
		}

		this->updateLists(compare);
		std::cout << std::endl;
		std::cout << "Want to continue the game? Enter Y if yes, N if no: ";
		std::cin >> playString;

		if (this->player_list.size() == 52 || this->computer_list.size() == 52) {
			std::cout << "The Game has ended" << std::endl;
			if (this->player_list.size() == 52) {
				std::cout << "Congrats! You have won!" << std::endl;
			}
			else {
				std::cout << "Sorry, the computer has won!" << std::endl;
			}
			gameOver = true;
		}
	}

	if (playString == "N") {
		std::cout << "You have chosen to forfeit." << std::endl;
		std::cout << "Your number of cards: ";
		std::cout << player_list.size() << std::endl;
		std::cout << "The computer's number of cards: ";
		std::cout << computer_list.size() << std::endl;
	}
}


void Deck::updateLists(int compare) {

	if (compare == 1) {
		this->player_list.push_back(computer_list.front());
		this->computer_list.pop_front();
		this->player_list.push_back(player_list.front());
		this->player_list.pop_front();
	}
	if (compare == -1) {
		this->computer_list.push_back(player_list.front());
		this->player_list.pop_front();
		this->computer_list.push_back(player_list.front());
		this->computer_list.pop_front();
	}

	if (compare == 0) {
		std::cout << "Onto the next cards: one card of each player will be placed face down,";
		std::cout << " the next card will be placed face up and will be evaluated" << std::endl;
		std::cout << "Highest card wins, player with winning card takes all cards in the pile" << std::endl;

		//add playing cards to temp list
		this->temp_list.push_back(player_list.front());
		this->temp_list.push_back(computer_list.front());

		//remove playing cards from player & computer list
		this->player_list.pop_front();
		this->computer_list.pop_front();

		//repeat with next pair of cards
		this->temp_list.push_back(player_list.front());
		this->temp_list.push_back(computer_list.front());
		this->player_list.pop_front();
		this->computer_list.pop_front();

		//compare next pair of cards
		std::cout << std::endl;
		std::cout << "Your face-up card is: ";
		std::cout << player_list.front()->print() << std::endl;

		std::cout << "Computer's face-up card is: ";
		std::cout << computer_list.front()->print() << std::endl;

		std::cout << std::endl;

		int compare = (player_list.front())->compareValue(*computer_list.front());

		switch (compare) {
		case 0:
			std::cout << "This means war! ";
			break;
		case 1:
			std::cout << "You win this round!" << std::endl;
			for (int i = this->temp_list.size(); i > 0; i--) {
				this->player_list.push_back(this->temp_list.front());
				this->temp_list.pop_front();
			}
			break;
		case -1:
			std::cout << "Computer wins this round!" << std::endl;
			for (int i = this->temp_list.size(); i > 0; i--) {
				this->computer_list.push_back(this->temp_list.front());
				this->temp_list.pop_front();
			}
			break;
		}

		this->updateLists(compare);
	}

}