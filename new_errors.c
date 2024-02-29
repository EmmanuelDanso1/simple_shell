#include "shell.h"
/**
* str_to_int - converts a string to an integer
* @str: the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
*-1 on error
*/
int str_to_int(char *str)
{
int j = 0;
unsigned long int res = 0;
if (*str == '+')
str++;
for (j = 0;  str[j] != '\0'; j++)
{
if (str[j] >= '0' && str[j] <= '9')
{
res = res * 10;
res = res + (str[j] - '0');
if (res > INT_MAX)
return (-1);
}
else
{
return (-1);
}
}
return (res);
}
/**
* print_err_msg - prints an error message
* @inform: the parameter & return info struct
* @err_str: string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
void print_err_msg(inform_t *inform, char *err_str)
{
_errputs(inform->file_nm);
_errputs(": ");
output_fd(inform->line_cnt, STDERR_FILENO);
_errputs(": ");
_errputs(inform->argv[0]);
_errputs(": ");
_errputs(err_str);
}
/**
* prints_decim - function prints a decimal (integer) number (base 10)
* @_input: the input
* @fd: the filedescriptor to write to
* Return: number of characters printed
*/
int prints_decim(int _input, int fd)
{
int (*__putchar)(char) = _putchar;
int j, cnt = 0;
unsigned int _absol_, curnt;
if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (_input < 0)
{
_absol_ = -input;
__putchar('-');
cnt++;
}
else
_absol_ = input;
curnt = _absol_;
for (j = 1000000000; j > 1; j /= 10)
{
if (_absol_ / j)
{
__putchar('0' + curnt / j);
cnt++;
}
curnt %= j;
}
__putchar('0' + curnt);
cnt++;
return (cnt);
}
/**
* num_converter - converter a function
* @num: number
* @beneath: base
* @flgs: argument flags
* Return: string
*/
char *num_converter(long int num, int beneath, int flgs)
{
static char *arr;
static char buff[50];
char s = 0;
char *pointer;
unsigned long n = num;
if (!(flgs & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
s = '-';
}
arr = flgs & CHANGE_TO_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
pointer = &buff[49];
*pointer = '\0';
do {
*pointer = arr[n % beneath];
n /= beneath;
} while (n != 0);
if (s)
*pointer = s;
return (pointer);
}
/**
* replacer - function replaces first instance of '#' with '\0'
* @buff: address of the string to modify
* Return: Always 0;
*/
void replacer(char *buff)
{
int j;
for (j = 0; buff[j] != '\0'; j++)
if (buff[j] == '#' && (!j || buff[j - 1] == ' '))
{
buff[j] = '\0';
break;
}
}
