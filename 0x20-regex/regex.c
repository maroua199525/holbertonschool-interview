#include "regex.h"


/**
*regex_match - a function that checks whether a given pattern
*matches a given string.
*@str:is the string to scan
*@pattern:is the regular expression
*Return: return 1 if the pattern matches the string, or 0 if it doesn’t
*/

int regex_match(char const *str, char const *pattern)
{
	int ptr = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));
	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			ptr = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || ptr);
	}
	return (0);
}
