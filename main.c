#include <stdio.h> 
#include <stdlib.h>
#include "input.h"
#include "operations.h" //already includes fornite and list modules

int main() {
    
    PtList shop = fortniteLoadShop();
    listPrint(shop);

    //-----------

    listDestroy(&shop);
    
    return EXIT_SUCCESS;
}
