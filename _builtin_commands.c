#include "shell.h"
/**
* exit_command - exits the shell
* @inform: Structure containing potential arguments. Used to maintain
* constant function prototype.
*  Return: exits with a given exit stat
* (0) if info.argv[0] != "exit"
*/
int exit_command(inform_t *inform)
{
int exit_checker;
if (inform->argv[1])
{
exit_checker = err_last(inform->argv[1]);
if (exit_checker == -1)
{
inform->stat = 2;
print_error(inform, "Not real number: ");
_eputs(inform->argv[1]);
_eputchar('\n');
return (1);
}
inform->error_num =_err_last(inform->argv[1]);
return (-2);
}
inform->error_num = -1;
return (-2);
}
/**
* _change_dir - changes the current directory of the process
* @inform: Structure containing potential arguments. Used to maintain
* constant function prototype.
*  Return: Always 0
*/
int _change_dir(inform_t *inform)
{
char *s, *direct, buffer[1024];
int change_dir;
s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!inform->argv[1])
{
direct = _getenv(inforn, "HOME=");
if (!direct)
chd_ir((direct = _getenv(inform, "PWD=")) ? direct : "/");
else
change_dir = ch_dir(direct);
}
else if (_strcmp(inform->argv[1], "-") == 0)
{
if (!_getenv(inform, "OLD PWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(inform, "OLD PWD=")), _putchar('\n');
ch_dir((direct = _getenv(info, "OLD PWD=")) ? direct : "/");
}
else
{
change_dir = ch_dir(inform->argv[1]);
}
if (change_dir == -1)
{
print_error(info, "can't change directory to ");
_eputs(inform->argv[1]), _eputchar('\n');
}
else
{
_setenv(inform, "OLD PWD", _getenv(inform, "PWD="));
_setenv(inform, "PWD", getcwd(buffer, 1024));
}
return (0);
}
/**
* helper_dir - changes the current directory of the process
* @inform: Structure containing potential arguments. Used to maintain
* constant function prototype.
*  Return: Always 0
*/
int helper_dir(inform_t *inform)
{
char **arg_array;
arg_array = inform->argv;
_puts("Function yet to be implemented \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}
