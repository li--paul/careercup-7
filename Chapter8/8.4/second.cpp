#include <string>
#include <iostream>

using namespace std;

string ss= "abcd";

void exchange(int i, int j){
    char c = ss[i];
    ss[i] = ss[j];
    ss[j] = c;
}

void permute(int size){
    if(size == 0)
        cout<<ss<<endl;
    else{

        for(int i=size-1;i>=0;i--){
            exchange(i,size-1);
            permute(size-1);
            exchange(i,size-1);
        }
    }
}

int main(){
    permute(4);
    return 0;
}
