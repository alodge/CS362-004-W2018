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

// card effect is on line 646 of the dominion code
// council_room is implementation on line 690

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
	int x, y, z;
	int success, tries;
	z = 0;
	tries = 0;

	// iterate the number of players
	for(y = 2; y <= numPlayers; y++)
	{
		// iterate for whose turn it is from 0 to num players
		for(currentPlayer = 0; currentPlayer < y; currentPlayer++)
		{
			for(x = 0; x < runs; x++)
			{
				// increment attempts counter
				tries ++;
				success = 1;
				// initialize a game state and player cards
				initializeGame(y, k, x+1, &G);
				G.whoseTurn = currentPlayer;			
				memcpy(&testG, &G, sizeof(struct gameState));
		
				// play the card
				cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
				//
		
				// compare the effects

				// test for +4 cards this player
				if (G.deckCount[currentPlayer] != testG.deckCount[currentPlayer] + 4)
				{
					printf("G deck curr %d   ", G.deckCount[currentPlayer]);
					printf("testG deck curr %d\n", testG.deckCount[currentPlayer]);
					printf("a\n");
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
							printf("test others = %d\n", testOthers);
							printf("currentPlayer: %d\n", currentPlayer);
							printf("G:   %d   ", G.deckCount[testOthers]);
							printf("testG:  %d\n", testG.deckCount[testOthers]);
							success = 0;
						}
					}
				}

				// test for +1 buys
				if(G.numBuys != testG.numBuys-1)
				{
					printf("c\n");
					printf("G.numbuys: %d   ", G.numBuys);
					printf("testG.numbuys: %d\n", testG.numBuys);
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
		}
	}
	printf("%s passed %d out of %d attempts\n", TESTCARD, z, tries);


	return 0;
}


