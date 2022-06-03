#include "TWO_WAY_LINKEDLIST.h"

int main(){
    int inp;
    for(int i=0;i<5;i++){
        cin >> inp;
        creation(inp);
    }

    cout << "The list is: " << endl;
    traverse();

    cout << "\n\n--------------------\n\n";
    cout << "Last insert. Insert to what? " ;
    cin >> inp;
    after_insert(3,inp);
    traverse();
}