#pragma once

#include <vector>
#include <stack>
#include <list>

#include "card.h"

class Deck {

public:
	Deck();
	~Deck();

public:
	void deal();
	void play();
	void shuffle();
	void updateLists(int compare);
	Card* draw();

protected:
	std::vector <Card*> full_deck;
	std::stack<Card*> draw_deck;
	std::list<Card*> player_list;
	std::list<Card*> computer_list;
	std::list<Card*> temp_list;
};