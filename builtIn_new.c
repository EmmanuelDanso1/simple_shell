#include "shell.h"
/**
* disp_history - displays the history list, one command by line, preceded
* with line numbers, starting at 0.
* @inform: Structure containing potential arguments.
*  Return: Always 0
*/
int disp_history(inform_t *inform)
{
print_lit(inform->long_t);
return (0);
}
/**
* set_known_as - sets alias to string
* @inform: param struct
* @str: the string alias
* Return: Always 0 on success, 1 on error
*/
int set_known_as(inform_t *inform, char *str)
{
char *s, i;
int retain;
s = _strchr(str, '=');
if (!s)
return (1);
i = *s;
*s = 0;
retain = del_node_at_indx(&(inform->known_as),
get_node_index(inform->known_as, node_starts_with(inform->known_as, str, -1)));
*s = i;
return (retain);
}
/**
* set_known - sets alias to string
* @inform: parameter struct
* @str: the string alias
*
* Return: Always 0 on success, 1 on error
*/
int set_known(inform_t *inform, char *str)
{
char *s;
s = _strchr(str, '=');
if (!s)
return (1);
if (!*++s)
return (set_known_as(inform, str));
set_known_as(inform, str);
return (add_node_at_end_of_index(&(inform->known_as), str, 0) == NULL);
}
/**
* output_known_as - prints an known_as string
* @node: the known_as node
* Return: Always 0 on success, 1 on error
*/
int output_known_as(lst_t *node)
{
char *s = NULL, *c = NULL;
if (node)
{
s = _strchr(node->str, '=');
for (c = node->str; c <= s; s++)
_putchar(*c);
_putchar('\'');
_puts(s + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
* new_known_as - mimics the known_as builtin
* @inform: Structure containing potential arguments.
* maintians function prototype
*  Return: Always 0
*/
int new_known_as(inform_t *inform)
{
int j = 0;
char *c = NULL;
lst_t *node = NULL;
if (inform->argc == 1)
{
node = inform->known_as;
while (node)
{
output_known_as(node);
node = node->new_node;
}
return (0);
}
for (j = 1; inform->argv[j]; j++)
{
c = _strchr(inform->argv[j], '=');
if (c)
new_known_as(inform, inform->argv[j]);
else
output_known_as(new_node_starts(inform->known_as, inform->argv[j], '='));
}
return (0);
}
