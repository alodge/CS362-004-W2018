CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: tests

tests: dominion.c rngs.c randomtestadventurer.c randomtestcard1.c randomtestcard2.c

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

clean:
	rm adventurer village council

cleanall: 
	rm adventurer village council *.gcda *.gcno *.gcov
