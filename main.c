#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

int main()
{
    node_t * list = NULL;
    loadList(&list);
    print(list);
    findOldest(list);
    findYoungest(list);
    ageAvg(list);
    printLetter(list, 'A');
}
