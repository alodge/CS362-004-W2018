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

// card effect is on line 757 of the dominion code
// adventurer implementation on line 646
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

	// iterate through to test many times
	for(x = 0; x < runs; x++)
	{
		tries++;
		/**********************************
 		 * Set game state randomly 		
 		 **********************************/
		// randomize numPlayers
		numPlayers = rand() % 2 + 2;
		
		// randomize beginning deck
		for (p = 0; p < 10; p++)
		{
			kd[p] = k[p];
		}
		for (p=0; p < 10; p++)
		{
			q = 0;
			while(q == 0)
			{
				r = rand() %10;
				if (kd[r] != -14)
				{
					kdd[p] = kd[r];
					kd[r] = -14;
					q = 1;
				}
			}	
		}
//		for (p = 0; p < 10; p++)
//		{
//			printf("kdd[%d] = %d\n", p, kdd[p]);
//		}

		// initialize a game state based on those parameters
		initializeGame(numPlayers, kdd, x+1, &G);

		// randomize whose turn it is
		G.whoseTurn = rand() % + numPlayers;

		// give them silver and gold for branch coverage
		int trand;
		trand = rand() % 3;
		if (trand == 0)
		{
			G.deck[G.whoseTurn][3] = copper;
		}
		if (trand == 1)
		{
			G.deck[G.whoseTurn][3] = silver;
		}
		if (trand == 2)
		{
			G.deck[G.whoseTurn][3] = gold;
		}
		trand = rand() %3;
		if (trand == 0)
		{
			G.deck[G.whoseTurn][4] = copper;
		}
		if (trand == 1)
		{
			G.deck[G.whoseTurn][4] = silver;
		}
		if (trand == 2)
		{
			G.deck[G.whoseTurn][4] = gold;
		}

		/**********************************
 		 * Set game state randomly 		
 		 **********************************/

		// copy this game state for testing			
		memcpy(&testG, &G, sizeof(struct gameState));
	
		//***********************************
		// Play the card on the test state
		//***********************************
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

		//***********************************
		// Test the results 
		//***********************************

		int before, added;
		int success;
		success = 1;

		// see that the initial hand is the same
		for(before = 0; before < G.handCount[currentPlayer]; before++)
		{
			if(G.hand[currentPlayer][before] != testG.hand[currentPlayer][before])
			{
				success = 0;
				// display the failing parameters
				printf("FAILURE: INITIAL HAND CHANGED\n");
				printf("   Seed = %d\n", x+1);
				printf("   numPlayers = %d\n", numPlayers);
				printf("   currentPlayer = %d\n", G.whoseTurn);
				printf("   hand = ");
				for (p = 0; p < 10; p++)
				{
					printf ("%d ", kdd[p]);
				}
				printf("\n");
			}	
		}

		// see that all additional cards are treasure
		for(before = G.handCount[currentPlayer]; before < testG.handCount[currentPlayer]; before++)
		{
			if(testG.hand[currentPlayer][before] != copper 
				&& testG.hand[currentPlayer][before] != silver 
				&& testG.hand[currentPlayer][before] != gold)
			{
				success = 0;
				// Display the failing parameters
				printf("FAILURE: ADDITIONAL CARDS NOT TREASURE\n");
				printf("   Seed = %d\n", x+1);
				printf("   numPlayers = %d\n", numPlayers);
				printf("   currentPlayer = %d\n", G.whoseTurn);
				printf("   hand = ");
				for (p = 0; p < 10; p++)
				{
					printf ("%d ", kdd[p]);
				}
				printf("\n");	

			}
		}

		// see that there are two additional cards
		if (testG.handCount[currentPlayer] - G.handCount[currentPlayer] != 2)
		{
			success = 0;
			printf("FAILURE: HAND COUNT DIDN'T CHANGE 2\n");
			printf("   Seed = %d\n", x+1);
			printf("   numPlayers = %d\n", numPlayers);
			printf("   currentPlayer = %d\n", G.whoseTurn);
			printf("   Initial Hand Count = %d\n", G.handCount[currentPlayer]);
			printf("   Final Hand Count = %d\n", testG.handCount[currentPlayer]);
			printf("   hand = ");
			for (p = 0; p < 10; p++)
			{
				printf ("%d ", kdd[p]);
			}
			printf("\n");
			printf("   cards: %d\n", testG.handCount[currentPlayer] - G.handCount[currentPlayer]);

		}
		
		if(success == 1)
		{
			z++;
			// printf("pass\n");
		}

	// end of iterator loop
	}

	// print the success ratio
	printf("Adventurer passed %d out of %d attempts\n", z, tries);
	return 0;
}


