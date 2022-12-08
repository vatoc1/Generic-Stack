#include "stck.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void StackInit(Stack * obj,int elem_size,void (*free_fn)(void * ),void (*pop_fn)(void*)) {
    obj->free_fn = free_fn;
    obj->pop_fn=pop_fn;

    obj->elem_size=elem_size;
    obj->log_len=0;
    obj->alloc_len=4;
    obj->elems=malloc(elem_size*obj->alloc_len);
    assert(obj->elems!=NULL);



}


void StackDispose(Stack * obj) {
    for(int i = 0;i<obj->log_len;i++) {
        void * temp = (char*)obj->elems+i*obj->elem_size;
        obj->free_fn(temp);

    }
}

void StackPush(Stack * obj,void * key) {

    if(obj->alloc_len==obj->log_len) {
        obj->alloc_len*=2;
        obj->elems=realloc(obj->elems,obj->alloc_len);
        assert(obj->elems!=NULL);


    } 
    void * elem_ptr=(char*)obj->elems + obj->log_len*obj->elem_size;
    memcpy(elem_ptr,key,obj->elem_size);

    obj->log_len++;




}

void  StackPop(Stack * obj,void * store) {
    assert(obj->log_len>0);
    obj->log_len--;
    void * temp = (char*)obj->elems + obj->log_len*obj->elem_size;
    

    memcpy(store,temp,obj->elem_size);
    obj->pop_fn(temp);

    

}


void StackPrint(Stack * obj,void (*print_fun)(void *)) {
    assert(print_fun!=NULL);    
    for(int i = 0;i<obj->log_len;i++) {
        void * temp = (char*)obj->elems + obj->elem_size*i;
        print_fun(temp);

    }

}
















