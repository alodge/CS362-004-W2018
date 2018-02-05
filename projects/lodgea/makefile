CFLAGS = -Wall -fpic -lm -std=c99

default: testme

testme: testme.c

	gcc -o testme testme.c $(CFLAGS)
	testme

clean:
	rm testme

cleanall: 
	rm testme
