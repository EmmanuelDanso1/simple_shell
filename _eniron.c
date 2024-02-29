#include "shell.h"
/**
* str_arr - returns the string array copy of our environ
* @inform: Structure containing potential arguments.
* Return: Always 0
*/
char **str_arr(inform_t *inform)
{
if (!inform->env || inform->changed_envi)
{
inform->my_env = list_to_strings(inform->envi);
info->env_changed = 0;
}
return (inform->env);
}
/**
* rm_env - Remove an environment variable
* @inform: Structure containing potential argument
* Return: 1 on delete, 0 otherwise
* @env_var: the string env var property
*/
int rm_env(inform_t *inform, char *env_var)
{
list_t *n = inform->envi;
size_t j = 0;
char *c;
if (!n || !env_var)
return (0);
while (n)
{
c = starts_with(n->s, env_var);
if (c && *c == '=')
{
inform->changed_envi = delete_node(&(inform->envi), j);
j = 0;
n = inform->envi;
continue;
}
n = n->next;
j++;
}
return (inform->changed_envi);
}
/**
*init_env - Initialize a new environment variable,
* or changed an existing one
* @inform: Structure containing potential arguments
* @str_var: the string env var property
* @str_value: the string environ var value
* Return: Always 0
 */
int init_env(inform_t *inform, char *str_var, char *str_value)
{
char *buffer = NULL;
list_t *n;
char *c;
if (!str_var || !str_value)
return (0);
buffer = malloc(_strlen(str_var) + _strlen(str_value) + 2);
if (!buffer)
return (1);
str_copy(buffer, str_var);
str_concate(buffer, "=");
str_concate(buffer, str_value);
n = inform->envi;
while (n)
{
c = begin_with(n->s, str_var);
if (c && *c == '=')
{
free(n->s);
n->s = buffer;
inform->changed_envi = 1;
return (0);
}
n = n->next;
}
add_n_to_end(&(inform->envi), buffer, 0);
free(buffer);
inform->changed_envi = 1;
return (0);
}
