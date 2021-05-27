#ifndef STACK_H_
#define STACK_H_
typedef unsigned char byte;
#define STACK_SIZE 100
/* class Stack */
typedef struct Stack Stack; 
struct Stack {
    byte *buffer; 
    int top;
    int size;
    int elementSize;
    /* where the data things are */
    int (*isFull)(Stack* const me);
    int (*isEmpty)(Stack* const me);
    int (*getSize)(Stack* const me);
    void (*push)(Stack* const me, void * k); 
    void * (*pop)(Stack* const me);
    void * (*peek)(Stack* const me);
};

/* Constructors and destructors:*/
void Stack_Init(
    Stack* const me,
    int elementSize,
    int (*isFullfunction)(Stack* const me),
    int (*isEmptyfunction)(Stack* const me),
    int (*getSizefunction)(Stack* const me),
    void (*pushfunction)(Stack* const me, void *k), 
    void * (*popfunction)(Stack* const me),
    void * (*peekfunction)(Stack* const me)
);
void Stack_Cleanup(Stack* const me);
/* Operations */
int Stack_isFull(Stack* const me);
int Stack_isEmpty(Stack* const me);
int Stack_getSize(Stack* const me);
void Stack_push(Stack* const me, void * k); 
void * Stack_pop(Stack* const me);
void * Stack_peek(Stack* const me);
Stack * Stack_Create(int size, int elementSize);
void Stack_Destroy(Stack* const me);

#endif /*STACK_H_*/
