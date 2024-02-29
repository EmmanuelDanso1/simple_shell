#include "shell.h"
/**
*string_cpy - copies a string
*@desti: the destination string to be copied to
*@source: the source string
*@amt: the amount of characters to be copied
*Return: the concatenated string
*/
char *string_cpy(char *desti, char *source, int amt)
{
int j, k;
char *str = desti;
j = 0;
while (source[j] != '\0' && j < amt - 1)
{
desti[j] = source[j];
j++;
}
if (j < amt)
{
k = j;
while (k < amt)
{
desti[k] = '\0';
k++;
}
}
return (str);
}

/**
*str_concate - concatenates two strings
*@desti: the first string
*@source: the second string
*@amt: the amount of bytes to be maximally used
*Return: the concatenated string
*/
char *str_concate(char *desti, char *source, int amt)
{
int j, k;
char *str = desti;
j = 0;
k = 0;
while (desti[j] != '\0')
j++;
while (source[k] != '\0' && k < amt)
{
desti[j] = source[k];
j++;
k++;
}
if (k < amt)
desti[j] = '\0';
return (str);
}
/**
*str_char_locator - locates a character in a string
*@str: the string to be parsed
*@charac: the character to look for
*Return: (str) a pointer to the memory area str
*/
char *str_char_locator(char *str, char charac)
{
do {
if (*str == charac)
return (str);
} while (*str++ != '\0');
return (str);
}
