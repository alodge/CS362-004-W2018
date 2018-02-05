/*
 * Card Test - Adventurer
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

#define TESTCARD "adventurer"

// card effect is on line 646 of the dominion code
// adventurer implementation on line 669
// cards 4, 5, 6 are the treasure cards

int main() {
	printf("***************\n");
	printf("Testing %s card.\n", TESTCARD);
	printf("***************\n");
	
	// variables to use
    	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    	int seed = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int currentPlayer;
	currentPlayer = 0;
	int numPlayers;
	numPlayers = 3;
	int runs;
	runs = 1;
	int x, y, z, tries;
	tries = 0;
	z = 0;

	// iterate through to test many times
	for(x = 0; x < runs; x++)
	{
		tries++;
		// initialize a game state with different seeds
		initializeGame(numPlayers, k, x+1, &G);
		G.whoseTurn = currentPlayer;			
		memcpy(&testG, &G, sizeof(struct gameState));
	
		//***********************************
		// Play the card on the test state
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
		//***********************************
	
		int before, added;
		int success;
		success = 1;
		for(before = 0; before < G.handCount[currentPlayer]; before++)
		{
			if(G.hand[currentPlayer][before] != testG.hand[currentPlayer][before])
			{
				printf("a\n");
				success = 0;
			}	
		}
		for(before = G.handCount[currentPlayer]; before < testG.handCount[currentPlayer]; before++)
		{
			if(testG.hand[currentPlayer][before] != copper)
			{
				printf("b\n");
				success = 0;
			}
		}
		if (testG.handCount[currentPlayer] - G.handCount[currentPlayer] != 2)
		{
			printf("c\n");
			printf("%d\n", testG.handCount[currentPlayer] - G.handCount[currentPlayer]);
			success = 0;
		}
		
		if(success == 1)
		{
			z++;
		}

	// end of iterator loop
	}



	printf("Adventurer passed %d out of %d attempts\n", z, tries);


	return 0;
}


