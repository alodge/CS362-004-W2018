#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#define DEBUG 0
#define NOISY_TEST 1

/*
 * Reference - I am beginning with the code provided in OSU CS362 and modifying
 * it to test this function
 */

// 320 - line Supply Count begins on
//

int main () {

  	int i, n, r, p, deckCount, discardCount, handCount;

  	int k[10] = {adventurer, council_room, feast, gardens, mine,
		       remodel, smithy, village, baron, great_hall};

  	struct gameState g;
	struct gameState gmod;
	
	printf ("Testing Supply Count.\n");
	initializeGame(2, k, 1000, &g);

	printf("curse: %d\n", g.supplyCount[curse]);
	printf("estate: %d\n", g.supplyCount[estate]);
	printf("duchy: %d\n", g.supplyCount[duchy]);
	printf("province: %d\n", g.supplyCount[province]);
	printf("copper: %d\n", g.supplyCount[copper]);
	printf("silver: %d\n", g.supplyCount[silver]);
	printf("gold: %d\n", g.supplyCount[gold]);

	memcpy(&gmod, &g, sizeof(struct gameState));

	gmod.supplyCount[curse] ++;
	gmod.supplyCount[estate] ++;
	gmod.supplyCount[duchy] ++;
	gmod.supplyCount[province] ++;
	gmod.supplyCount[copper] ++;
	gmod.supplyCount[silver] ++;
	gmod.supplyCount[gold] ++;

	int passingTests;
	passingTests = 0;

	// printf("curse... g: %d, gmod: %d\n", supplyCount(curse, &g), supplyCount(curse, &gmod));
	if (supplyCount(curse, &g) == supplyCount(curse, &gmod) - 1)
	{
		passingTests ++;
	}
	if (supplyCount(estate, &g) == supplyCount(estate, &gmod) - 1)
	{
		passingTests ++;
	}
	if (supplyCount(duchy, &g) == supplyCount(duchy, &gmod) - 1)
	{
		passingTests ++;
	}
	if (supplyCount(province, &g) == supplyCount(province, &gmod) - 1)
	{
		passingTests ++;
	}
	if (supplyCount(copper, &g) == supplyCount(copper, &gmod) - 1)
	{
		passingTests ++;
	}
	if (supplyCount(silver, &g) == supplyCount(silver, &gmod) - 1)
	{
		passingTests ++;
	}
	if (supplyCount(gold, &g) == supplyCount(gold, &gmod) - 1)
	{
		passingTests ++;
	}

	printf("The supplyCount() function passed %d out of 7 tests.\n", passingTests);

  return 0;
}
