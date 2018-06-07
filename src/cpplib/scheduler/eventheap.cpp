#include "eventheap.h"

CallbackItem::CallbackItem(functionPointer func, unsigned long t):
    timestamp{t},
    f{func},
    next{nullptr},
    prev{nullptr}
{

}

CallbackItem::~CallbackItem(){
}

Heap::Heap(){
    first = nullptr;
}

Heap::~Heap(){

    CallbackItem* it = first;

    while(it!=nullptr){
        CallbackItem* aux = it->next;
        delete it;
        it=aux;
    }

    first = nullptr;
}

void Heap::insert(functionPointer p, unsigned long t){
    if(first){
        //if there are already elements in the heap
        //save the address of the first
        CallbackItem *aux = first;
        //introduce the new one as first
        CallbackItem* cb = new CallbackItem(p,t);
        first = cb;
        //set the previous first as second
        first->next = aux;
        first->next->prev = first;
    }else{
        //it is the first one
        CallbackItem* cb = new CallbackItem(p,t);
        first = cb;
    }
}

void Heap::remove(CallbackItem *cb){
    cb->prev->next = cb->next;
    cb->next->prev = cb->prev;
    delete cb;
}

