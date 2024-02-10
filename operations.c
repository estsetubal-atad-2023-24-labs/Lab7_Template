#include "operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


PtList fortniteLoadShop() {
    FILE* stream = fopen("fortniteshop.csv", "r");

    /* If file does not exist, abort */ 
    if(stream == NULL) return NULL;

    PtList list = listCreate();

    int count = 0;
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        
        /* creates tokens[3] array, with tokens read from the file line */
        char** tokens = splitString(tmp, 3, ",");
        
        int vbucks = atoi(tokens[2]);
        FortniteItem item = fortniteItemCreate(tokens[0], tokens[1], vbucks);

        listAdd(list, count++, item);

	    free(tokens);
        free(tmp);
    }

    fclose(stream);

    return list;
}

