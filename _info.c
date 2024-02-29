#include "shell.h"
/**
* init_inform - initializes info_t struct
* @inform: struct address
*/
void init_inform(inform_t *inform)
{
inform->arg = NULL;
inform->argv = NULL;
inform->path = NULL;
inform->argc = 0;
}
/**
* inform_set - initializes info_t struct
* @inform: struct address
* @args: argument vector
*/
void inform_set(inform_t *inform, char **args)
{
int j = 0;
inform->fname = args[0];
if (inform->arg)
{
inform->argv = strtow(inform->arg, " \t");
if (!inform->argv)
{
inform->argv = malloc(sizeof(char *) * 2);
if (inform->argv)
{
inform->argv[0] = _strdup(inform->arg);
inform->argv[1] = NULL;
}
}
for (j = 0; inform->argv && inform->argv[j]; j++)
;
inform->argc = j;
replace_known_as(inform);
replace_var(inform);
}
}
/**
* free_fields- frees inform_t struct fields
* @inform: struct address
* @ethin: true if freeing all fields
*/
void free_fields(inform_t *inform, int ethin)
{
free(inform->argv);
inform->argv = NULL;
inform->path = NULL;
if (ethin)
{
if (!inform->chmd_buffer)
free(inform->arg);
if (inform->envi)
free_list(&(inform->envi));
if (inform->histy)
free_list(&(inform->histy));
if (inform->known_as
free_list(&(inform->known_as));
ffree(inform->envi);
inform->envi = NULL;
bfree((void **)inform->chmd_buffer);
if (inform->readfd > 2)
close(inform->readfd);
_putchar(BUFF_FLUSH);
}
}
