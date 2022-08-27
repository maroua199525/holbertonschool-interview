#include "substring.h"

/**
 * find_substring - finds a substring in a string
 * @s: is the string to scan
 * @words:  is the array of words all strings must be
 * a concatenation arrangement of
 * @nb_words:  is the number of elements in the array words
 * @n: holds the address at which to store the number
 * of elements in the returned array.
 * Return: an allocated array, storing each index in s
 * at which a substring was found.
 * If no solution is found, NULL can be returned.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, len_word, x;
	int j, i = 0;
	int *strings, *exsit;

	if (!s)
		return (NULL);

	*n = 0;
	len = strlen(s);
	len_word = strlen(words[0]);

	exsit = malloc(nb_words * sizeof(int));
	strings = malloc(len * sizeof(int));

	while (i <= (len - nb_words * len_word))
	{
		for (j = 0; j < nb_words; j++)
			exsit[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (x = 0; x < nb_words; x++)
			{
				if (exsit[x] == 0 && strncmp(s + i + j *
					len_word, words[x], len_word) == 0)
				{
					exsit[x] = 1;
					break;
				}
			}
			if (x == nb_words)
				break;
		}
		if (j == nb_words)
			strings[(*n)++] = i;
		i++;
	}
	free(exsit);
	return (strings);
}
