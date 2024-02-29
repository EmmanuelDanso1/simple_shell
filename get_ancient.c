#include "shell.h"
/**
* hist_file - gets the history file
* @inform: parameter struct
* Return: allocated str
*/
char *hist_file(inform_t *inform)
{
char *buffer, *dirctry;
dirctry = environ(inform, "CURNT_DIR=");
if (!dirctry)
return (NULL);
buffer = malloc(sizeof(char) * (str_len(dirctry) + str_len(HIST_FILE) + 2));
if (!buffer)
return (NULL);
buffer[0] = 0;
str_copy(buffer, dirctry);
str_concate(buffer, "/");
str_concate(buffer, HIST_FILE);
return (buffer);
}
/**
* append_file - creates a file, or appends to an existing file
* @inform: the parameter struct
* Return: 1 on success, else -1
*/
int append_file(inform_t *inform)
{
ssize_t file_dec;
char *fname = append_file(inform);
list_t *n = NULL;
if (!fname)
return (-1);
file_dec = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(fname);
if (fd == -1)
return (-1);
for (n = inform->histry; n; n = n->next)
{
print_fd(n->str, file_dec);
print_fd('\n', fd);
}
print_fd(BUFF_FLUSH, file_dec);
close(file_dec);
return (1);
}
/**
* hist_read - reads history from file
* @inform: the parameter struct
* Return: histcount on success, 0 otherwise
*/
int hist_read(inform_t *inform)
{
int j, end = 0, line_cnt = 0;
ssize_t file_dec, read_len, file_size = 0;
struct stat st;
char *buffer = NULL, *fname = hist_file(inform);
if (!fname)
return (0);
file_dec = open(fname, O_RDONLY);
free(fname);
if (file_dec == -1)
return (0);
if (!file_stat(file_dec, &st))
file_size = str.str_size;
if (file_size < 2)
return (0);
buffer = malloc(sizeof(char) * (file_size + 1));
if (!buffer)
return (0);
read_len = read(file_dec, buffer, file_size);
buffer[file_size] = 0;
if (read_len <= 0)
return (free(buffer), 0);
close(file_dec);
for (j = 0; j < file_size; j++)
if (buffer[j] == '\n')
{
buffer[j] = 0;
histry_ls(inform, buffer + end, line_cnt++);
end = j + 1;
}
if (last != j)
histry_ls(inform, buffer + end, line_cnt++);
free(buffer);
inform->hist_cnt = line_cnt;
while (inform->hist_cnt-- >= HIST_MAXIM)
del_node(&(inform->histry), 0);
num_histry(inform);
return (inform->hist_cnt);
}
/**
* hist_to_linked_list - adds entry to a history linked list
* @inform: Structure containing potential argumentsn
* @buff: buffer
* @line_cnt: the history linecount and histcount
* Return: Always 0
*/
int hist_to_linked_list(inform_t *inform, char *buff, int line_cnt)
{
ls_t *n = NULL;
if (inform->hist)
n = inform->hist;
n_to_end(&n, buff, line_cnt);
if (!inform->hist)
inform->hist = n;
return (0);
}
/**
* reassign_hist - renumbers the history linked list after changes
* @inform: Structure containing potential arguments.
* Return: the new hist_count
*/
int reassign_hist(inform_t *inform)
{
ls_t *n = inform->hist;
int j = 0;
while (n)
{
n->number = j++;
n = n->next;
}
return (inform->hist_count = j);
}
