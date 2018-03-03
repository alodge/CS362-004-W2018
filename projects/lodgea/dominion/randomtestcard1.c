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

// card effect is on line 757 of the dominion code
// village implementation on line 711
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
	int kd[10];
	int kdd[10];
	int p, q, r;
	int currentPlayer;
	currentPlayer = 0;
	int numPlayers;
	int runs;
	runs = 15;
	int x, y, z, tries;
	tries = 0;
	z = 0;
	int success;

	for(x = 0; x < runs; x++)
	{
		success = 1;
		tries ++;
	
		//
		// randomize game state		
		//

		// randomize numPlayers
		numPlayers = rand() %2 + 2;

		// randomize current player
		currentPlayer = rand() % numPlayers;

		// randomize deck
		for (p = 0; p < 10; p++)
		{
			kd[p] = k[p];
		}
		for (p = 0; p < 10; p++)
		{
			q = 0;
			while (q == 0)
			{
				r = rand() % 10;
				if(kd[r] != -14)
				{
					kdd[p] = kd[r];
					kd[r] = -14;
					q = 1;
				}
			}
		}
	

		// initialize a game state and player cards
		initializeGame(numPlayers, kdd, x+1, &G);
		G.whoseTurn = currentPlayer;			
		memcpy(&testG, &G, sizeof(struct gameState));
		
		// play the card
		cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
		//
		printf("testG = %d;   G = %d\n", testG.numActions, G.numActions);
		if(G.numActions != testG.numActions - 2)
		{
			// if the card had the right effect, increment
			// the successes counter
			success = 0;		
			printf("FAILURE: numActions isn't +2 with these params\n");
			printf("   seed: %d\n", x+1);
			printf("   numPLayers: %d\n", numPlayers);
			printf("   currentPlaer: %d\n", currentPlayer);
			printf("   delta(actions) = %d\n", testG.numActions - G.numActions);
			printf("   hand: ");
			for (p = 0; p < 10; p++)
			{
				printf("%d ", kdd[p]);
			}
			printf("\n");
		}
		if(success == 1)
		{
			z++;
		}
	}


	printf("Village passed %d out of %d attempts\n", z, tries);


	return 0;
}


