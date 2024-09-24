// warproj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "deck.h"
#include "war.h"

int main(int argc, char **argv)
{
    Deck deck;

    deck.shuffle();
    deck.deal();
    deck.play();

    return 1;
}

