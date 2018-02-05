#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define DEBUG 0
#define NOISY_TEST 1

/*
 * Reference - I am beginning with the code provided in OSU CS362 and modifying
 * it to test this function
 */

// 32 - line Supply Count begins on
//

int main () {

	srand(time(NULL));

  	int i, n, r, p, deckCount, discardCount, handCount;

  	int k[10] = {adventurer, council_room, feast, gardens, mine,
		       remodel, smithy, village, baron, great_hall};

  	struct gameState g;
	struct gameState gmod;
	printf("**************************\n");
	printf ("Testing Full Deck Count.\n");
	printf("**************************\n");
	initializeGame(3, k, 1000, &g);

	int cards;
	cards = 5;
	int j;
	int currCard;
	currCard = 0;
	int numCards;
	int quantity_of_card;
	int passingTests;
	passingTests = 0;
	
	// for each of three players
	for (p=0; p<3; p++)
	{

		// First, assign 5 cards at random in each of the card, deck, and discard
		g.deckCount[p] = 5;
		g.handCount[p] = 5;
		g.discardCount[p] = 5;
		for(j=0; j < cards; j++)
		{
			currCard = rand() % 26;
			g.deck[p][j] = currCard;
		}
		for(j=0; j < cards; j++)
		{
			currCard = rand() % 26;
			g.hand[p][j] = currCard;
		}
		for(j=0; j < cards; j++)
		{
			currCard = rand() % 26;
			g.discard[p][j] = currCard;
		}
		
		// Then, loop through each of the 28 cards to count them
		numCards = 0;
		for (currCard = 0; currCard < 27; currCard++)
		{
			quantity_of_card = fullDeckCount(p, currCard, &g);
			numCards = numCards + quantity_of_card;
		}

		// fullDeckCount() should have found 15 cards
		if(numCards == 15)
		{
			passingTests ++;
		}
	}

	printf("Supply Count passed %d of 3 tests.\n", passingTests);
	printf("Each test ran the fullDeckCount() function 15 times using randomly assigned card values.\n");

  return 0;
}
