#include "shell.h"
/**
*  node_adding - adds a node to the start of the list
* @address_ptr: address of pointer to head node
* @s: string field of node
* @node_index: node index used by histry
* Return: size of list
*/
ls_t *node_adding(ls_t **address_ptr, const char *s, int node_index)
{
ls_t *new_address_ptr;
if (!address_ptr)
return (NULL);
new_node_index = malloc(sizeof(ls_t));
if (!new_address_ptr)
return (NULL);
memset((void *)new_address_ptr, 0, sizeof(ls_t));
new_address_ptr->node_index = node_index;
if (s)
{
new_address_ptr->s = strdup(s);
if (!new_address_ptr->s)
{
free(new_address_ptr);
return (NULL);
}
}
new_address_ptr->next = *address_ptr;
*address_ptr = new_address_ptr;
return (new_address_ptr);
}
/**
* new_node_add - adds a node to the end of the list
* @address_ptr: address of pointer to head node
* @s: string field of node
* @node_index: node index used by history
* Return: size of list
*/
ls_t *new_node_add(ls_t **address_ptr, const char *s, int node_index)
{
ls_t *new_n, *n;
if (!address_ptr)
return (NULL);
n = *address_ptr;
new_n = malloc(sizeof(ls_t));
if (!new_n)
return (NULL);
memset((void *)new_n, 0, sizeof(ls_t));
new_n->node_index = node_index;
if (s)
{
new_n->s = s_up(s);
if (!new_n->s)
{
free(new_n);
return (NULL);
}
}
if (n)
{
while (n->nxt)
n = n->nxt;
n->nxt = new_n;
}
else
*address_ptr = new_n;
return (new_n);
}
/**
* print_str_el - prints only the string element of a list_t linked list
* @first_n: pointer to first node
* Return: size of list
*/
size_t print_str_el(const ls_t *first_n)
{
size_t j = 0;
while (first_n)
{
puts(first_n->s ? first_n->s : "(nil)");
puts("\n");
first_n = first_n->nxt;
j++;
}
return (j);
}
/**
* del_node_index - deletes node at given index
* @address_ptr: address of pointer to first node
* @inx: index of node to delete
* Return: 1 on success, 0 on failure
*/
int del_node_index(ls_t **address_ptr, unsigned int inx)
{
ls_t *n, *previ_n;
unsigned int j = 0;
if (!address_ptr || !*address_ptr)
return (0);
if (!inx)
{
n = *address_ptr;
*address_ptr = (*address_ptr)->nxt;
free(n->s);
free(n);
return (1);
}
n = *address_ptr;
while (n)
{
if (j == inx)
{
previ_n->nxt = n->nxt;
free(n->s);
free(n);
return (1);
}
j++;
prev_n = n;
n = n->nxt;
}
return (0);
}
/**
* free_node - frees all nodes of a list
* @address_ptr: address of pointer to head node
* Return: void
*/
void free_node(ls_t **address_ptr)
{
ls_t *n, *nxt_n, *address_ptr;
if (!address_ptr || !*address_ptr)
return;
address_ptr = *address_ptr;
n = address_ptr;
while (n)
{
nxt_n = n->nxt;
free(n->s);
free(n);
n = nxt_n;
}
*address_ptr = NULL;
}
