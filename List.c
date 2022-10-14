//
// Created by Valentin on 07/10/2022.
//

#include "List.h"

typedef struct node
{
    int value;
    struct node *next;
}
Node;

struct list
{
    Node *head;
};

List* list_new()
{
    List *new = malloc(sizeof (List));
    new->head = NULL;
    return new;
}

Node* node_new(int value)
{
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;
    return new;
}

List* list_append(List *l, int value_to_add)
{
    if(l->head == NULL)
    {
        l->head = node_new(value_to_add);
        return l;
    }
    Node *current = l->head;
    while (current->next)
        current = current->next;

    current->next = node_new(value_to_add);
    return l;
}

List* list_load_from_file(List* l,FILE* input_file)
{
    int i = 0;
    char buffer [10000];
    //l->head = malloc(sizeof(int ) * 255);

    while (fgets(buffer,32767,input_file) != NULL)
    {
        i = atoi(buffer);  //Esto esta bien
        //printf("%d\n",i+1);
        list_append(l, i); //Esto ya quedo
    }
    return l;
}

void list_print(List *l)
{
    Node *current = l->head;
    while (current)
    {
        printf("[%d]->", current->value);
        current = current->next;
    }
    printf("\n");
}

List* scroll_head(List *l)
{

    Node *max_value = l->head;
    Node *current_value = l->head;
    while (current_value)
    {
        if (max_value->value < current_value->value)
        max_value->value = current_value->value;
        current_value = current_value->next;
    }
}