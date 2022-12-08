
#ifndef STACK_H_
#define STACK_H_



typedef struct {
    void * elems;
    int elem_size;
    void (*free_fn)(void*);
    void (*pop_fn)(void*); 
    int log_len;
    int alloc_len;
    
} Stack;



void StackInit(Stack * obj,int elem_size,void (*free_fn)(void*),void (*pop_fn)(void*));

void StackDispose(Stack* obj);

void StackPush(Stack * obj,void * key);

void StackPop(Stack * obj,void * store);

void StackPrint(Stack * obj,void (*print_fun)(void *));



#endif