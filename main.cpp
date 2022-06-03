#include "TWO_WAY_LINKEDLIST.h"

int main(){
    int inp;
    for(int i=0;i<5;i++){
        cin >> inp;
        creation(inp);
    }

    cout << "The list is: " << endl;
    traverse();

    cout << endl << "before delete" << endl;
    given_delete(3);
    traverse();
}