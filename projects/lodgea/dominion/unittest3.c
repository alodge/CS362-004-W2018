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

// 390 - line Supply Count begins on
// 69 - line dominion.c initializes supply with

int main () {

	srand(time(NULL));

  	int i, n, r, p, deckCount, discardCount, handCount;
	int over;
	over = 0;
  	int k[10] = {adventurer, council_room, feast, gardens, mine,
		       remodel, smithy, village, baron, great_hall};

  	struct gameState g;
	struct gameState gmod;
	
	printf ("Testing isGameOver().\n");
	initializeGame(3, k, 1000, &g);
	p = 0;
	for (n = 0; n < 100000; n++)
	{
		r = rand() % 5;
		g.supplyCount[province] = r;
		over = over + isGameOver(&g);
		if (r == 0)
		{
			p++;
		}
	}

	printf("Game over for zero Province cards %d times out of 100000 randomly generated attempts\n", over);
	printf("Game should have ended for 0 province cards %d times\n", p);

	g.supplyCount[province] = 8;
	int x, y, z, zeroCount, shouldBeOver;;
	z = 0;
	for (x = 0; x < 100000; x++)
	{
		zeroCount = 0;
		shouldBeOver = 0;
		over = 0;
		for (y = 0; y < 16; y++)
		{
			r = rand() % 10;
			g.supplyCount[y] = r;
			if (r == 0)
			{
				zeroCount ++;
			}
		}
		if((zeroCount >= 3) || (g.supplyCount[province] == 0))
		{
			shouldBeOver = 1;
		}
		over = over + isGameOver(&g);
		if (over == shouldBeOver)
		{
			z++;
		}
	}

	printf("Correctly ended game %d out of 100000 randomly generated attempts\n", z);

  return 0;
}
