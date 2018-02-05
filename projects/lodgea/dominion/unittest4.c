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

// 8 - line Supply Count begins on


int main () {

	printf("*****************\n");
	printf("Testing getCost() function\n");
	printf("*****************\n");

	srand(time(NULL));

  	int i, n, r, p, deckCount, discardCount, handCount;
	
  	int k[10] = {adventurer, council_room, feast, gardens, mine,
		       remodel, smithy, village, baron, great_hall};
	int testcard;
	int cost;
	int success;
	int runs;
	runs = 10000;
	int x, z;
	z = 0;
	int tries;
	tries = 0;
	// iterate through to check
	for (x = 0; x < runs; x++)
	{
		tries++;
		success = 1;
		testcard = rand() % 26;
		cost = getCost(testcard);
		// printf("%d\n", cost);
		if(testcard == curse)
		{	
			if(cost != 0)
			{
				success = 0;
			}
		}
		if(testcard == estate)
		{	
			if(cost != 2)
			{
				success = 0;
			}
		}
		if(testcard == duchy)
		{	
			if(cost != 5)
			{
				success = 0;
			}
		}
		if(testcard == province)
		{	
			if(cost != 8)
			{
				success = 0;
			}
		}
		if(testcard == copper)
		{	
			if(cost != 0)
			{
				success = 0;
			}
		}
		if(testcard == silver)
		{	
			if(cost != 3)
			{
				success = 0;
			}
		}
		if(testcard == gold)
		{	
			if(cost != 6)
			{
				success = 0;
			}
		}
		if(testcard == adventurer)
		{	
			if(cost != 6)
			{
				success = 0;
			}
		}
		if(testcard == council_room)
		{	
			if(cost != 5)
			{
				success = 0;
			}
		}
		if(testcard == feast)
		{	
			if(cost != 4)
			{
				success = 0;
			}
		}
		if(testcard == gardens)
		{	
			if(cost != 4)
			{
				success = 0;
			}
		}
		if(testcard == mine)
		{	
			if(cost != 5)
			{
				success = 0;
			}
		}
		if(testcard == remodel)
		{	
			if(cost != 4)
			{
				success = 0;
			}
		}
		if(testcard == smithy)
		{	
			if(cost != 4)
			{
				success = 0;
			}
		}
		if(testcard == village)
		{	
			if(cost != 3)
			{
				success = 0;
			}
		}
		if(testcard == baron)
		{	
			if(cost != 4)
			{
				success = 0;
			}
		}
		if(testcard == great_hall)
		{	
			if(cost != 3)
			{
				success = 0;
			}
		}
		if(testcard == minion)
		{	
			if(cost != 5)
			{
				success = 0;
			}
		}
		if(testcard == steward)
		{	
			if(cost != 3)
			{
				success = 0;
			}
		}
		if(testcard == tribute)
		{	
			if(cost != 5)
			{
				success = 0;
			}
		}
		if(testcard == ambassador)
		{	
			if(cost != 3)
			{
				success = 3;
			}
		}
		if(testcard == cutpurse)
		{	
			if(cost != 4)
			{
				success = 0;
			}
		}
		if(testcard == embargo)
		{	
			if(cost != 2)
			{
				success = 0;
			}
		}
	
		if(testcard == outpost)
		{	
			if(cost != 5)
			{
				success = 0;
			}
		}
		if(testcard == salvager)
		{	
			if(cost != 4)
			{
				success = 0;
			}
		}
		if(testcard == sea_hag)
		{	
			if(cost != 4)
			{
				success = 0;
			}
		}
		if(testcard == treasure_map)
		{	
			if(cost != 4)
			{
				success = 0;
			}
		}
	
		if(success == 1)
		{
			z++;
		}
	// end of iterator
	}

	printf("Correctly got cost %d times out of %d\n", z, tries);

  return 0;
}
