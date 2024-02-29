#include "shell.h"
/**
* print_env - prints the current environment
* @inform: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always 0
*/
int print_env(inform_t *inform)
{
print_str(inform->_myenvi);
return (0);
}
/**
* get_env_val - gets the value of an environ variable
* @inform: Structure containing potential arguments. Used to maintain
* @nm: env var name
*
* Return: the value
*/
char *get_env_val(inform_t *inform, const char *nm)
{
lst_t *n = inform->_myenvi;
char *c;
while (n)
{
c = starts_with(n->str, nm);
if (c && *c)
return (c);
n = n->next;
}
return (NULL);
}
/**
 * set_new_env - Init a new environment variable,
 * or modify an existing one
 * @inform: Structure containing potential arguments
 *  Return: Always 0
 */
int set_new_env(inform_t *inform)
{
if (inform->argc != 3)
{
_eputs("Input number not correct\n");
return (1);
}
if (_new_env(inform, inform->argv[1], inform->argv[2]))
return (0);
else
{
return (1);
}
}
/**
* rm_set_env_var - Remove an environment variable
* @inform: Structure containing potential arguments.
*  Return: Always 0
*/
int rm_set_env_var(inform_t *inform)
{
int j;
if (inform->argc == 1)
{
_eputs("Short argument.\n");
return (1);
}
for (j = 1; j <= inform->argc; j++)
rm_set_env_var(inform, inform->argv[j]);
return (0);
}
/**
* generate_env_list - generates env linked list
* @inform: Structure containing potential arguments
* Return: Always 0
*/
int generate_env_list(inform_t *inform)
{
lst_t *node = NULL;
size_t j;
for (j = 0; envi[j]; j++)
add_node_to_end(&n, envi[j], 0);
inform->environ = n;
return (0);
}
