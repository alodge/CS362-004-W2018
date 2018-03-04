CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: tests

tests: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c randomtestadventurer.c randomtestcard1.c randomtestcard2.c

	echo "Adventurer Card Random Test" >> randomtestadventurer.out
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o adventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	adventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	
	echo "Village Card Random Test" >> randomtestcard1.out
	echo "randomtestcard1.c:" >> randomtestcard1.out
	gcc -o village dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	village >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	
	echo "Council Room Card Random Test" >> randomtestcard2.out
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o council dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	council >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out

	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "cardtest1.c:" >> cardtestresults.out
	gcc -o cardtest1 dominion.c rngs.c cardtest1.c $(CFLAGS)
	cardtest1 >> cardtestresults.out
	gcov dominion.c >> cardtestresults.out
	
	echo "cardtest2.c:" >> cardtestresults.out
	gcc -o cardtest2 dominion.c rngs.c cardtest2.c $(CFLAGS)
	cardtest2 >> cardtestresults.out
	gcov dominion.c >> cardtestresults.out
	
	echo "cardtest3.c:" >> cardtestresults.out
	gcc -o cardtest3 dominion.c rngs.c cardtest3.c $(CFLAGS)
	cardtest3 >> cardtestresults.out
	gcov dominion.c >> cardtestresults.out
	
	echo "cardtest4.c:" >> cardtestresults.out
	gcc -o cardtest4 dominion.c rngs.c cardtest4.c $(CFLAGS)
	cardtest4 >> cardtestresults.out
	gcov dominion.c >> cardtestresults.out
	
clean:
	rm adventurer village council tests.out

cleanall: 
	rm adventurer village council tests.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov
