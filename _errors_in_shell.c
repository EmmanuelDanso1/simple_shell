#include "shell.h"
/**
*prints_input - prints an input string
* @s: the string to be printed
* Return: Nothing
*/
void prints_input(char *s)
{
int j = 0;
if (!s)
return;
while (s[j] != '\0')
{
print_char(s[j]);
j++;
}
}
/**
* write_char - writes the character c to stderr
* @c: character to be printed
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int write_char(char c)
{
static int j;
static char buffer[WRITE_BUFF_SIZE];
if (c == BUFFER_FLUSH || j >= WRITE_BUFF_SIZE)
{
write(2, buffer, j);
j = 0;
}
if (c != BUFFER_FLUSH)
buffer[j++] = c;
return (1);
}
/**
* writes_char_fd - writes the character c to given fd
* @c: character to print
* @fd: filedescriptor to be written to
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int writes_char_fd(char c, int fd)
{
static int j;
static char buffer[WRITE_BUFF_SIZE];
if (c == BUFF_FLUSH || j >= WRITE_BUFF_SIZE)
{
write(fd, buffer, j);
j = 0;
}
if (c != BUFF_FLUSH)
buffer[j++] = c;
return (1);
}
/**
* prints_string - prints an input string
* @s: string to be printed
* @fd: filedescriptor to write to
* Return: the number of chars put
*/
int prints_string(char *s, int fd)
{
int j = 0;
if (!s)
return (0);
while (*s)
{
j = j + print_fd(*s++, fd);
}
return (j);
}
