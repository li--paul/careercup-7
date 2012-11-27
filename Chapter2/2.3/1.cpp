#include <iostream>

struct node{
    int value;
    node * next;
};

void remove(node *p){
    if(p == NULL)
        return ;
    node *q = p->next;
    if(q == NULL){
        delete p;
    }
    else{
        p->value = q->value;
        p->next = q->next;
        delete q;
    }
}

int main(){
}
