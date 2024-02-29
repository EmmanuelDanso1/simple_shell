#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define READ_BUFF_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_FLUSH -1
#define CMD_NORM
#define CMD_OR
#define CMD_AND	
#define CMD_CHAIN
#define CHANGE_TO_LOWERCASE
#define CONVERT_UNSIGNED
#define USE_GETLINE
#define USE_STRTOK
#define HIST_FILE
#define HIST_MAXIM

/**
* struct ls_str - singly linked list
* @n: the number field
* @s: a string
* @nxt: points to the next node
*/
typedef struct ls_str
{
int n;
char *s;
struct ls_str *nxt;
} ls_t;
/**
*struct _inform - contains pseudo-arguements to pass into a fnx
*@arg: a string generated from getline containing arguments
*@argv: an array of strings generated from argument vector
*@path: a string path for the current command
*@argc: the argument count
*@line_cnt: the error count
*@file_nm: the program filename
*@envi: linked list local copy of environ
*@histry: the history node
*@known_as: the alias node
*@read_file_dec: the file_dec from which to read line input
*@hist_count: the history line number count
*/
typedef struct _inform
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_cnt;
char *file_nm;
ls_t *envi;
ls_t *histry;
ls_t *known_as;
char **environ;
int env_changed;
int read_file_dec;
int hist_cnt;
} inform_t;
/**
*struct builtin_func - contains a builtin string and related function
*@t: builtin command flagged
*@fnx:  function
*/
typedef struct builtin_func
{
char *t;
			int (*fnx)(inform_t *);
} builtin_schema;
int correct_output(inform_t *inform);
int is_delimet(char c, char *delimet);
int _isalpha_bet(int c);
int _conversion(char *s);
int exit_command(inform_t *inform);
int _change_dir(inform_t *inform);
int helper_dir(inform_t *inform);
int disp_history(inform_t *inform);
int set_known_as(inform_t *inform, char *str);
int set_known(inform_t *inform, char *str);
int output_known_as(ls_t *node);
int new_known_as(inform_t *inform);
int print_env(inform_t *inform);
char *get_env_val(inform_t *inform, const char *nm);
int set_new_env(inform_t *inform);
int rm_set_env_var(inform_t *inform);
int generate_env_list(inform_t *inform);
void prints_input(char *s);
int write_char(char c);
int writes_char_fd(char c, int fd);
int prints_string(char *s, int fd);
int str_to_int(char *str);
void print_err_msg(inform_t *inform, char *err_str);
int prints_decim(int _input, int fd);
char *num_converter(long int num, int beneath, int flgs);
void replacer(char *buff);
char *string_cpy(char *desti, char *source, int amt);
char *str_concate(char *desti, char *source, int amt);
char *str_char_locator(char *str, char charac);
char **str_arr(inform_t *inform);
int rm_env(inform_t *inform, char *env_var);
int init_env(inform_t *inform, char *str_var, char *str_value);
void init_inform(inform_t *inform);
void inform_set(inform_t *inform, char **args);
void free_fields(inform_t *inform, int ethin);
char *hist_file(inform_t *inform);
int append_file(inform_t *inform);
int hist_read(inform_t *inform);
int hist_to_linked_list(inform_t *inform, char *buff, int line_cnt);
int reassign_hist(inform_t *inform);
ls_t *node_adding(ls_t **address_ptr, const char *s, int node_index);
ls_t *new_node_add(ls_t **address_ptr, const char *s, int node_index);
size_t print_str_el(const ls_t *first_n);
int del_node_index(ls_t **address_ptr, unsigned int inx);
void free_node(ls_t **address_ptr);
#endif
