#include <iostream>
#include <set>

using namespace std;

struct node{
    int value;
    node * next;
};


void addNode(node ** head, int value){
    if(*head == NULL){
        *head = new node();
        (*head)->value = value;
        (*head)->next = NULL;
    }

    else{
        node * n = new node;
        n->value = value;
        n->next = (*head)->next;
        (*head)->next = n;
    }
}

void uniq(node * head){
    if(head == NULL)
        return;

    set<int> s;
    s.insert(head->value);

    node * p = head;

    while(p != NULL && p->next != NULL){
        if(s.find(p->next->value) != s.end()){
            node * q = p->next;
            p->next = q->next;
            delete q;
            q = NULL;
        }
        else{
            s.insert(p->next->value);
        }

        p = p->next;
    }
}

void print(node * head){
    node * p =head;
    while(p){
        cout<<p->value<<" ";
        p = p->next;
    }

    cout<<endl;
}

int main(){

    node * head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 5);

    print(head);
    uniq(head);
    print(head);
    return 0;
}

