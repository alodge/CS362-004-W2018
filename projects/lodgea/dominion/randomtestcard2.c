/*
 * Card Test - Council Room
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

#define TESTCARD "council_room"

// card effect is on line 757 of the dominion code
// council_room is implementation on line 728 

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
	int currentPlayer;
	int numPlayers;
	int runs;
	runs = 15;
	int x, y, z;
	int p, q, r;
	int success, tries;
	z = 0;
	tries = 0;

	for(x = 0; x < runs; x++)
	{
		// increment attempts counter
		tries ++;
		success = 1;

		//
		// Base the game state on random numbers
		//

		// random number of players between 2 and 4
		numPlayers = rand() %2 + 2;

		// current player chose at random
		currentPlayer = rand() % numPlayers;

		// random deck
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
				if (kd[r] != -42);
				{
					kdd[p] = kd[r];
					kd[r] = -42;
					q = 1;
				}
			}
		}

		// initialize a game state and player cards based on
		// these randomly set parameters
		initializeGame(numPlayers, kdd, x+1, &G);
		G.whoseTurn = currentPlayer;

		// make a copy of this game state			
		memcpy(&testG, &G, sizeof(struct gameState));
		
		// play the card on the copied game state
		cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
		
		//
		// compare the effects
		//

		// test for +4 cards this player
		if (G.deckCount[currentPlayer] != testG.deckCount[currentPlayer] + 4)
		{
			printf("FAILURE: CURRENT PLAYER ISN'T UP 4 CARDS\n");
			printf("   G deck curr %d   ", G.deckCount[currentPlayer]);
			printf("   testG deck curr %d\n", testG.deckCount[currentPlayer]);
			printf("   seed: %d\n", x+1);
			printf("   numPlayers: %d\n", numPlayers);
			printf("   currentPlayer: %d\n", currentPlayer);
			success = 0;
		}

		// test for +1 card other players
		int testOthers;
		for (testOthers = 0; testOthers < y; testOthers++)
		{
			if (testOthers != currentPlayer)
			{ 
				if(G.deckCount[testOthers] != testG.deckCount[testOthers]+1)
				{
					// printf("b\n");
					printf("FAILURE: ANOTHER PLAYER ISN'T UP 1 CARD\n");
					printf("   othersPlayer = %d\n", testOthers);
					printf("   currentPlayer: %d\n", currentPlayer);
					printf("   G deck size:   %d   ", G.deckCount[testOthers]);
					printf("   testG deck size:  %d\n", testG.deckCount[testOthers]);
					printf("   seed: %d\n");
					success = 0;
				}
			}
		}

		// test for +1 buys
		if(G.numBuys != testG.numBuys-1)
		{
			printf("FAILURE: NUMBER OF BUYS ISN'T UP 1\n");
			printf("   currentPlayer: %d\n", currentPlayer);
			printf("   G.numbuys: %d   ", G.numBuys);
			printf("   testG.numbuys: %d\n", testG.numBuys);
			printf("   seed: %d\n", x+1);
			success = 0;
		}

		// if all tests pass, this run was a success		
		if(success == 1)
		{
			// if the card had the right effect, increment
			// the successes counter
			z++;		
		}
	}


	printf("%s passed %d out of %d attempts\n", TESTCARD, z, tries);


	return 0;
}


