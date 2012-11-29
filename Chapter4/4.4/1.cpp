#include <vector>
#include <iostream>
#include <list>

using namespace std;

struct node{
    int value;
    node * left, *right;
};

void addNode(node ** root, int value){
    if(*root == NULL){
        *root = new node;
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return ;
    }

    if((*root)->value > value){
        addNode(&(*root)->left, value);
    }
    else 
        addNode(&(*root)->right, value);
}

void print(node *root){
    if(root == NULL)
        return;
    print(root->left);
    cout<<root->value<<endl;
    print(root->right);
}

vector<list<int> > vec; 

void genList(node * root, int level){
    if(root == NULL)
        return;

    while(vec.size()<level+1){
        vec.push_back(list<int>());
    }

    vec[level].push_back(root->value);

    genList(root->left, level+1);
    genList(root->right, level+1);
}

void printList(){
    for(int i=0;i<vec.size();i++){
        cout<<"level "<<i<<endl;

        list<int>::iterator it = vec[i].begin();
        for(;it!=vec[i].end();++it){
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    node * root = NULL;
    while(cin>>n){
        addNode(&root,n);
    }
    cout<<"tree :"<<endl;
    print(root);

    genList(root,0);
    printList();

    return 0;
}

