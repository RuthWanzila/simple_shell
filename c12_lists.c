#include "shell.h"

/**
* add_node - adds a node to the head of the list
* @head: pointer to head node
* @str: memory area
* @num: node indx used by history
* Return: size of list
*/
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_head;
if (!head)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (str)
{
new_head->str = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *head;
*head = new_head;
return (new_head);
}

/**
* add_node_end - adds a node to the end of the list
* @head: pointer to head node
* @str: memory area
* @num: node indx used by history
*
* Return: size of list
*/
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new_node, *node;

if (!head)
return (NULL);

node = *head;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*head = new_node;
return (new_node);
}

/**
* print_list_str - prints only the str element of a list_t linked list
* @g: pointer to first node
*
* Return: size of list
*/
size_t print_list_str(const list_t *g)
{
size_t i = 0;

while (g)
{
_puts(g->str ? g->str : "(nil)");
_puts("\n");
g = g->next;
i++;
}
return (i);
}

/**
* delete_node_at_index - deletes node at given indx
* @head: address of pointer to first node
* @indx: indx of node to delete
*
* Return: 1 on success, 0 on failure
*/
int delete_node_at_index(list_t **head, unsigned int indx)
{
list_t *node, *prev_node;
unsigned int i = 0;

if (!head || !*head)
return (0);

if (!indx)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (i == indx)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
i++;
prev_node = node;
node = node->next;
}
return (0);
}

/**
* free_list - frees all nodes of a list
* @headpointer: pointer to head node
*
* Return: void
*/
void free_list(list_t **headpointer)
{
list_t *node, *next_node, *head;

if (!headpointer || !*headpointer)
return;
head = *headpointer;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*headpointer = NULL;
}
