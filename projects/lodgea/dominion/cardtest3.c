/*
 * Card Test - Village
 * Reference - I am beginning with the code provided in class
 * and modifying it so that it works for the Smithy card 
 * 
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

// card effect is on line 646 of the dominion code
// village implementation on line 842
// cards 4, 5, 6 are the treasure cards

int main() {
	printf("*****************\n");
	printf("Testing %s card.\n", TESTCARD);
	printf("*****************\n");

	// variables
    	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    	int seed = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int currentPlayer;
	currentPlayer = 0;
	int numPlayers;
	numPlayers = 4;
	int runs;
	runs = 10000;
	int x, y, z, tries;
	tries = 0;
	z = 0;

	// iterate for number of players from 2 to 4
	for(y = 2; y <= numPlayers; y++)
	{
		// iterate for whose turn it is from 0 to num players
		for(currentPlayer = 0; currentPlayer < y; currentPlayer++)
		{
			for(x = 0; x < runs; x++)
			{
				// increment attempts counter
				tries ++;

				// initialize a game state and player cards
				initializeGame(y, k, x+1, &G);
				G.whoseTurn = currentPlayer;			
				memcpy(&testG, &G, sizeof(struct gameState));
		
				// play the card
				cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
				//
		
				if(G.numActions == testG.numActions - 2)
				{
					// if the card had the right effect, increment
					// the successes counter
					z++;		
				}
			}
		}
	}
	printf("Village passed %d out of %d attempts\n", z, tries);


	return 0;
}


