#include <stack>
#include <iostream>

using namespace std;

int main(){

    stack<int> a;
    stack<int> b;

    srandom(time(NULL));
    for(int i=0;i<10;i++){
        a.push(random());
    }

    while(!a.empty()){
        int temp = a.top();
        a.pop();
        while(!b.empty() && b.top()<temp){
            a.push(b.top());
            b.pop();
        }

        b.push(temp);
    }

    while(!b.empty()){
        cout<<b.top()<<" ";
        b.pop();
    }
    cout<<endl;

    return 0;
}
