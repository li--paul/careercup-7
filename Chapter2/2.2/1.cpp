#include <iostream>

using namespace std;

struct node{
    int value;
    node * next;
};

node * nth(node * head,int n){
    if(head == NULL || n < 0)
        return NULL;

    node * current = head;
    node * nth = NULL;

    while(n>0 && current != NULL){
        current = current->next;
        n--;
    }
    
    if(current == NULL)
        return NULL;

    nth = head;
    while(current != NULL){
        current = current->next;
        nth = nth->next;
    }

    return nth;
}


void addNode(node **head, int value){
    if(*head == NULL){
        *head = new node;
        (*head)->value = value;
        (*head)->next = NULL;
    }
    else{
        node * p = new node;
        p->value = value;
        p->next = (*head)->next;
        (*head)->next = p;
    }
}

void print(node *head){
    while(head != NULL){
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;
} 

int main(){
    node *head = NULL;

    addNode(&head,1);
    addNode(&head,2);
    addNode(&head,3);
    addNode(&head,4);
    addNode(&head,5);
    addNode(&head,6);

    print(head);

    node *p = nth(head, 2);
    if(p != NULL){
        cout<<"2th node is "<<p->value<<endl;
    }
    else{
        cout<<"2th node is NULL"<<endl;
    }

    p = nth(head, 5);
    if(p != NULL){
        cout<<"5th node is "<<p->value<<endl;
    }
    else{
        cout<<"5th node is NULL"<<endl;
    }


    return 0;
}


