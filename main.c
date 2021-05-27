#include <stdio.h> 
#include <stdlib.h> 
#include "stack.h"
#define STACK_SIZE 10
int main(void) { 
    int j,k, h, t;
    /* test normal queue */ 
    Stack * myQ;
    myQ = Stack_Create(10, sizeof(int)); 
    k = 10000;
    for (j=0;j<STACK_SIZE;j++) { 
        h = (int)myQ->top;
        myQ->push(myQ,(void *)&k);
        printf("inserting %d at position %d, size =%d\n",k--,h, myQ->getSize(myQ)); 
    };
    printf("Inserted %d elements\n",myQ->getSize(myQ)); 
    for (j=0;j<STACK_SIZE;j++) {
        t = (int)myQ->top;
        //k = *((int*)myQ->peek(myQ));
        k = *((int*)myQ->pop(myQ));
        printf("REMOVING %d at position %d, size =%d\n",k,t, myQ->getSize(myQ));
    };
    printf("Last item removed = %d\n", k);
    printf("Current queue size %d\n", myQ->getSize(myQ)); 
    puts("Queue test program");
    return EXIT_SUCCESS; 
}
