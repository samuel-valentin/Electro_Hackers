#include <stdio.h>
#include "List.h"

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE    *textfile;
    char    line[MAX_LINE_LENGTH];

    if(argc < 2)
    {
        printf("No file selected");
        return 0;
    }

    //textfile = fopen("input.txt", "r");
    textfile = fopen(argv[1], "r");

    if(textfile == NULL)
    {
        printf("No file valid to read");
        return -1;
    }

    List* l = list_new();
    list_load_from_file(l, textfile);


    fclose(textfile);
    //FILE *result_file = fopen("..result.txt","wb");
    FILE *result_file = fopen(argv[1], "w");

    if(result_file == NULL)
    {
        printf("No file valid to write");
        return -1;
    }

    return 0;
}