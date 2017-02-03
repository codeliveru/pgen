/*
 * This source writed by Sergey Levitin (2011).
 * You can to modify this source for anything.
 * If you want to donate to me, my paypal is selevit@yandex.ru :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *gen_pw(unsigned int length)
{
	unsigned int i, j;
	/*
	 * Random 0 to 99 integer value.
	 * Need to sort big, small and special symbols in new password.
	*/
	unsigned int nrand;
	/*
	 * Number of small, big and special symbols in new password.
	*/
	unsigned int ns_latin, ns_glatin, ns_esc;
	/*
	 * New password/ Will be returned for this function.
	*/
	char *pw;
	/*
	 * Values of small latin symbols.
	*/
	char s_latin[] = {
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
	};
	/*
	 * Values of big latin symbols.
	*/
	char s_glatin[] = {
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
	};
	/*
	 * Values of special ANSI symbols.
	*/
	char s_esc[] = {
		'!','@','#','$','%','^','&','*','(',')','-','=','+','.',',',':',';','"','?'
	};

	/*
	 * Allocating memory for new password array.
	*/
	pw = (char *) malloc (length * sizeof(char));

	ns_latin = length - rand() % (length + 1);
	ns_glatin = length - ns_latin - rand() % (length - ns_latin + 1);

	if (ns_glatin > 0)
		ns_esc = length - ns_latin - ns_glatin;
	else
		ns_esc = length - ns_latin;

	for (i = 0; i < (length-1); i++) {
		nrand = rand() % 100;

		/*
		 * Sorting a big, small and special symbols for new password.
		 * You cat to modify it, if you don't like this algorithm.
		*/

		if (nrand > 50)
			pw[i] = s_latin[rand() % sizeof(s_latin)];
		else
			if (nrand > 20 && nrand <= 50)
				pw[i] = s_glatin[rand() % sizeof(s_glatin)];
			else
				pw[i] = s_esc[rand() % sizeof(s_esc)];
	}
	pw[length-1] = '\0';
	return pw;
}
int main(int argc, char **argv)
{
	srand(time(0));
	unsigned int length;
	char *pw;
	/*
	 * If user entered empty value for first argument.
	*/
	if (!argv[1]) {
		printf("Usage: pgen <length>\n");
		exit(1);
	}
	else
		/*
		 * If password is too long or too short.
		*/
		if (atoi(argv[1]) > 4096 || atoi(argv[1]) < 5) {
			printf("Incorrect password length value.\nEnter 5 to 4096 integer value.\n");
			exit(2);
		} else // All's ok
			length = atoi(argv[1]);
	/*
	 * Generating new password and print it.
	*/
	pw = gen_pw(length);
	printf("%s\n",pw);
	// exit
	return 0;
}
