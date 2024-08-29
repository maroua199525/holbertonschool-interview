#include "regex.h"


/**
* regex_match- func
* @str: char *
* @pattern: char const
* Return: int
*/
int regex_match(char const *str, char const *pattern)
{
	int i = 0, rv = 0;

	do
	{
		rv = regex_match_rec(str, pattern + i);
		if (rv)
			break;
		i++;
	} while (pattern[i]);
	return (rv);
}


/**
* regex_match_rec- func
* @str: char *
* @pattern: char const
* Return: int
*/
int regex_match_rec(char const *str, char const *pattern)
{
	int a1 = 0;
    if (*str == '\0' && *pattern == '\0')
	    return (1);

    if (*str != '\0' && *pattern == '\0')
		return (0);
	if (pattern[0] == '.')
		return (1 * regex_match(str + 1, pattern + 1));
	if (pattern[0] == '*')
	{
		if (pattern[1] == '\0')
			return (1);
		if (str[0] == '\0')
			return (0);
		a1 = regex_match(str, pattern + 1);
		return ((!a1) ? (regex_match(str + 1, pattern)) : 1);
	}
	if (pattern[0] == '\0')
		return (0);
	if (str[0] != pattern[0])
		return (0);
	return (regex_match(str + 1, pattern + 1));
}
