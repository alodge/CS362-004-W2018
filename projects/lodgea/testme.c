#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	// rewrite this function
	int r;
	char c;
	r = rand() % 9;
	if (r == 0)
	{
		c = '[';
	}
	if (r == 1)
	{
		c = '(';
	}
	if (r == 2)
	{
		c = '{';
	}
	if (r == 3)
	{
		c = ' ';
	}
	if (r == 4)
	{
		c = 'a';
	}
	if (r == 5)
	{
		c = 'x';
	}
	if (r == 6)
	{
		c = '}';
	}
	if (r == 7)
	{
		c = ')';
	}
	if (r == 8)
	{
		c = ']';
	}
	return c;
}

char *inputString()
{
	// rewrite this function
	int r;
	int x;
	char c;
	static char s[10];
	for(x = 0; x < 6; x++)
	{
		r = rand() % 5;
		if (r == 0)
		{
			c = 'r';
		}
		if (r == 1)
		{
			c = 'e';
		}
		if (r == 2)
		{
			c = 's';
		}
		if (r == 3)
		{
			c = 't';
		}
		if (r == 4)
		{
			c = '\0';
		}
		s[x] = c;
	// end of iterator
	}
	return s;
}

void testme()
{
	int tcCount = 0;
	char *s;
	char c;
	int state = 0;
	while (1)
	{
		tcCount++;
		c = inputChar();
		s = inputString();
		printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' '&& state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e'
			&& s[2] == 's' && s[3] == 'e'
			&& s[4] == 't' && s[5] == '\0'
			&& state == 9)
		{
			printf("error ");
			exit(200);
		}
	}
}


int main(int argc, char *argv[])
{
	srand(time(NULL));
	testme();
	return 0;
}
