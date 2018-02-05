/*
 * Card Test - Smithy
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

#define TESTCARD "smithy"

// card effect is on line 646 of the dominion code
// smithy implementation on line 832

int main() {
	printf("**********************\n");
	printf("Testing %s card.\n", TESTCARD);
	printf("**********************\n");


	// variables to use
    	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    	int seed = 1000;
    	int numPlayers = 3;
    	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int runs;
	runs = 10000;
	int x, y, z, tries;
	tries = 0;
	z = 0;

	// loop through a variety of player numbers
	for (x=0; x < numPlayers; x++)
	{	
		for (y=0; y < runs; y++)
		{ 
			tries++;
			
			// initialize a game state and player cards
			initializeGame(numPlayers, k, y+1, &G);
			G.whoseTurn = x;			

			// copy the game state to a test case
			memcpy(&testG, &G, sizeof(struct gameState));
	
			// run the cardEffect function, calling the current card - Smithy
			cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

			// compare the decks
			if (G.handCount[x] == testG.handCount[x] - 2)
			{
				z++;
			}		

		}
	}
	printf("Smithy passed %d out of %d tests\n", z, tries);


	return 0;
}


