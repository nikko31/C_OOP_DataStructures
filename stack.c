#include <stdio.h> 
#include <stdlib.h> 
#include "stack.h"

void Stack_Init(Stack* const me,
                int elementSize,
                int (*isFullfunction)(Stack* const me), 
                int (*isEmptyfunction)(Stack* const me),
                int (*getSizefunction)(Stack* const me),
                void (*pushfunction)(Stack* const me, void * k), 
                void * (*popfunction)(Stack* const me),
                void * (*peekfunction)(Stack* const me)){
    /* initialize attributes */ me->top = 0;
    me->size = 0;
    me->elementSize = elementSize;
    /* initialize member function pointers */ 
    me->isFull = isFullfunction;
    me->isEmpty = isEmptyfunction; 
    me->getSize = getSizefunction; 
    me->push = pushfunction;
    me->pop = popfunction;
    me->peek = peekfunction;
}

/* operation Cleanup() */
void Stack_Cleanup(Stack* const me) { 
    free(me->buffer);
}

/* operation isFull() */
int Stack_isFull(Stack* const me){
    return STACK_SIZE == me->size; 
}

/* operation isEmpty() */
int Stack_isEmpty(Stack* const me){
    return (me->size <= 0); 

}
/* operation getSize() */
int Stack_getSize(Stack* const me) {
    return me->size; 
}

/* operation insert(int) */
void Stack_push(Stack* const me, void * k){
    
    if (me->isFull(me)) {
        exit(1);
    }
    int start = me->top * me->elementSize, i;
    for(i = 0; i < me->elementSize; i++) {
        *(me->buffer + start + i) = *((byte *)(k + i));
    }
    
    me->top = me->top + 1;
    //printf("top2%d\n",me->top);
    ++me->size;
}

/* operation remove */
void * Stack_pop(Stack* const me) {
    
    /* sentinel value */ 
    if (me->isEmpty(me)) {
        exit(1);
    }
    void *elem = me->peek(me);
    me->top = (me->top-1); 
    --me->size;
    
    return elem;
}

void * Stack_peek(Stack* const me) {
    if(me->isEmpty(me)) {
        exit(1);
    }
    int start = (me->top - 1) * me->elementSize, i;
    byte *elem;
    elem = (byte *)malloc(me->elementSize);
    for(i = 0; i < me->elementSize; i++) {
        *(elem + i) = *(me->buffer + start + i);
    }
    return (void *)elem;
}

Stack * Stack_Create(int size, int elementSize) {
    Stack* me = (Stack *) malloc(sizeof(Stack)); 
    me->buffer = (byte *)malloc(elementSize * STACK_SIZE);
  if(me->buffer == NULL) {
    exit(1);
  }
    if(me!=NULL)
    {
        Stack_Init(me, 
            elementSize,
            Stack_isFull, 
            Stack_isEmpty, 
            Stack_getSize, 
            Stack_push, 
            Stack_pop,
            Stack_peek);
    } 
    return me;
}

void Stack_Destroy(Stack* const me) { 
    if(me!=NULL)
    {
        Stack_Cleanup(me);
    } 
    free(me);
}
