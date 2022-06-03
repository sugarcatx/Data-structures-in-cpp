#ifndef DATA_STRUCTURE_AND_ALGORITHM_TWO_WAY_LINKEDLIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_TWO_WAY_LINKEDLIST_H
#include <iostream>
using namespace  std;


class node{
public:
    int info;
    node * prev, * next;

    node(int x){
        info = x;
        prev = NULL;
        next = NULL;
    }
};

node *head= NULL , * tail =NULL;

void creation(int x){
    node *ptr = new node(x);

    if(head == NULL){
        head = ptr;
        tail = ptr;
    }else{
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}

void traverse(){
    node *srt = head;
    for(;;){
        cout << srt->info << " ";

        if(srt->next == NULL) return;
        srt = srt->next;
    }
}

void backward_traverse(){
    node *srt = tail;
    for(;;){
        cout << srt->info << " ";

        if(srt->prev == NULL) return;
        srt = srt->prev;
    }
}


/*
 * @ Insertion operations.
 * 4 types of insert:
 * 1. First insert
 * 2. Last insert
 * 3. Insert before any given element.
 * 4. Insert after any given element.
 * */

void first_insert(int x){
    node *ptr = new node(x);

    head->prev = ptr;
    ptr->next = head;
    head = ptr;
}

void last_insert(int x){
    node *ptr = new node(x);

    ptr->prev = tail;
    tail->next = ptr;
    tail = ptr;
}


void before_insert(int s_item, int x){
    node *srt = head, *ptr = new node(x);
    for(;;){
        if(srt->info == s_item){
            //check if srt is head     --- YES---> First insert ,   ---NO---> Insert at given index.
            if(srt == head){
                first_insert(x);
                break;
            }else{
                srt->prev->next = ptr;
                ptr->prev = srt->prev;
                ptr->next = srt;
                srt->prev = ptr;

                break;
            }
        }else{
            srt = srt->next;
        }

        if(srt==NULL){
            cout << "Element not found";
            return;
        }
    }
}


void after_insert(int s_item, int x){
    node *srt = head,  *ptr = new node(x);
    for(;;){
        if(srt->info == s_item){
            if(srt->next == NULL){
                //last insert
                last_insert(x);
                break;
            }else{
                srt->next->prev =ptr;
                ptr->next = srt->next;
                ptr->prev = srt;
                srt->next = ptr;
                return;
            }
        }else{
            srt = srt->next;
        }

        if(srt==NULL){
            cout << "Element not found";
            return;
        }
    }
}



#endif //DATA_STRUCTURE_AND_ALGORITHM_TWO_WAY_LINKEDLIST_H
