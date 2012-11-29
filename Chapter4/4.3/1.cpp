#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

struct node{
    int value;
    node * left;
    node * right;
};

void addNode(node **root,int start,int end){
    if(*root == NULL){
        *root = new node;
        (*root)->left=NULL;
        (*root)->right = NULL;
    }

    int value;

    if(start >= end){
        value = vec[start];
        (*root)->value = value;
    }
    else{
        int middle = (start+end)/2;
        value = vec[middle];
        (*root)->value = value;
        if(middle -start > 0)
            addNode(&(*root)->left, start,middle-1);
        if(end - middle > 0)
            addNode(&(*root)->right, middle+1,end);
    }

}

void print(node *n){
    if(n == NULL)
        return;
    print(n->left);
    cout<<n->value<<endl;
    print(n->right);
}

int main(){

    for(int i=0;i<10;i++){
        vec.push_back(i);
    }

    node * root = NULL;
    addNode(&root, 0, vec.size()-1);

    print(root);
    return 0;
}

