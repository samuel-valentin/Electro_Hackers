//
// Created by Valentin on 07/10/2022.
//

#ifndef ELECTRO_HACKERS_LIST_H
#define ELECTRO_HACKERS_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct list List;

List *list_new();
List *list_append(List *l, int value_to_add);
void list_print(List *l);
List* list_load_from_file(List* l,FILE* input_file);
List *scroll_head(List *l);
List *list_load_from_write(List *l,FILE* resul_file);

#endif //ELECTRO_HACKERS_LIST_H
