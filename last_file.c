#include "shell.h"
/**
* correct_output - returns true if shell output correctly
* @inform: struct address
*
* Return: 1 if interactive mode, 0 otherwise
*/
int correct_output(inform_t *inform)
{
return (is_last(STDIN_FILENO) && inform->read_file_dec <= 2);
}
/**
* is_delimet - checks if character is a delimeter
* @c: the character to be checked
* @delimet: the delimeter string
* Return: 1 if true, 0 if false
*/
int is_delimet(char c, char *delimet)
{
while (*delimet)
if (*delimet++ == c)
return (1);
else
return (0);
}
/**
*_isalpha_bet - checks for alphabetic character
*@c: The character to input
*Return: 1 if c is alphabetic, 0 otherwise
*/
int _isalpha_bet(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
/**
*_conversion - converts a string to an integer
*@s: the string to be converted
*Return: 0 if no numbers in string, converted number otherwise
*/
int _conversion(char *s)
{
int j, checked = 1, lag = 0, output;
unsigned int res = 0;
for (j = 0;  s[j] != '\0' && lag != 2; j++)
{
if (s[j] == '-')
checked *= -1;
if (s[j] >= '0' && s[j] <= '9')
{
lag = 1;
res *= 10;
res = res + (s[j] - '0');
}
else if (lag == 1)
lag = 2;
}
if (checked == -1)
output = -res;
else
output = res;
return (output);
}
