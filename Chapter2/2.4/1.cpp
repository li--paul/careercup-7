#include <iostream>

using namespace std;

struct node{
    int value;
    node * next;
};


node * add(node *p, node *q){
    if(p == NULL && q == NULL)
    {
        return NULL;
    }

    node * header = NULL;
    node * current = NULL;

    bool carry = false;
    while(p!=NULL && q!= NULL){
        node * n = new node();
        n->value = 0;
        n->next = NULL;

        cout<<p->value<<" " << q->value<<endl;
        if(p){
            n->value += p->value; 
            p=p->next;
        }
        if(q){
            n->value += q->value;
            q=q->next;
        }


        if(carry)
            n->value++;

        if(n->value <10){
            carry = false;
        }
        else{
            carry = true;
            n->value = n->value % 10;
        }

        if(header == NULL)
            header = n;
        else{
            current->next = n; 
        }
        current = n;


    }
    return header;
}

int main(){
    node *p=new node();
    p->value = 3;
    p->next = new node();
    p->next->value = 1;
    p->next->next = new node;
    p->next->next->value = 5;

    node *q=new node;
    q->value = 5;
    q->next = new node;
    q->next->value = 9;
    q->next->next = new node;
    q->next->next->value = 2;

    node * r = add(p,q);
    while(r!=NULL){
        cout<<r->value<<" ";
        r = r->next;
    }
    cout<<endl;
    return 0;
}
