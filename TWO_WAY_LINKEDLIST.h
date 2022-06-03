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
                ptr->next = srt->next;
                srt->next->prev =ptr;
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



/*
 * @ Creating the delete functions
 * Five delete function to be created.
 *
 * 1. First delete
 * 2. Last delete
 * 3. Before item delete
 * 4. After delete
 * 5. Item delete
 * */


void first_delete(){
    head->next->prev = NULL;
    head = head->next;
}

void last_delete(){
    tail = tail->prev;
    tail->next = NULL;
}

void before_delete(int sitem){
    node *srt = head;
    for(;;){
        if(srt->info == sitem){
            if(srt->prev==head){
                first_delete();
                break;
            }else if(srt == head){
                cout << "No before element exist" << endl;
                break;
            }else{
                srt->prev->prev->next = srt;
                srt->prev = srt->prev->prev;
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

void after_delete(int sitem){
    node *srt = head;
    for(;;){
        if(srt->info == sitem){
            if(srt->next == tail){
                last_delete();
                break;
            }else if(srt == tail){
                cout << "No last node exist" << endl;
                break;
            }else{
                srt->next->next->prev = srt;
                srt->next = srt->next->next;
                break;
            }
        }else{
            srt = srt->next;
        }

        if(srt==NULL){
            cout << "Item not found";
            break;
        }
    }
}


void given_delete(int sitem){
    node *srt = head;
    for(;;){
        if(srt->info==sitem){
            if(srt == head){
                first_delete();
            }
            else if(srt == tail){
                last_delete();
            }else{
                srt->next->prev = srt->prev;
                srt->prev->next = srt->next;
                break;
            }
        }else{
            srt = srt->next;
        }

        if(srt==NULL){
            cout << "Element not found"<<endl;
            break;
        }
    }
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_TWO_WAY_LINKEDLIST_H
