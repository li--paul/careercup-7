#include <stack>
#include <iostream>
#include <vector>

using namespace std;

vector<stack<int> > vec;

// move i disks from a to b
void move(int i, int a, int b, int c){
    if(i == 1){
        int i = vec[a].top();
        vec[a].pop();
        cout<<"move " << i << " from "<<a <<" to "<<b<<endl;
        vec[b].push(i);
        return ;
    }

    move(i-1,a,c,b);
    move(1,a,b,c);
    move(i-1,c,b,a);
}

int main(){

    vec.push_back(stack<int>());
    vec.push_back(stack<int>());
    vec.push_back(stack<int>());

    for(int i=3;i>0;i--)
        vec[0].push(i);

    move(3,0,1,2);
    while(!vec[1].empty()){
        cout<<vec[1].top()<<" ";
        vec[1].pop();
    }
    cout<<endl;
    return 0;
}

