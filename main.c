#include <stdio.h>
#include "List.h"

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    char    line[MAX_LINE_LENGTH];

    if(argc < 2)
    {
        printf("No file selected");
        return 0;
    }

    //textfile = fopen("input.txt", "r");
    FILE *input_file = fopen(argv[1], "r");

    if(input_file == NULL)
    {
        printf("No file valid to read");
        return -1;
    }

    List* l = list_new();
    list_load_from_file(l, input_file);
    list_print(l);
    scroll_head(l);
    list_print(l);

    fclose(input_file);

    FILE *result_file = fopen("../result.txt","w");
    //FILE *result_file = fopen(argv[1], "w");
    if(result_file == NULL)
    {
        printf("No file valid to write");
        return -1;
    }

    list_load_from_write(l,result_file);
    fclose(result_file);

    return 0;
}