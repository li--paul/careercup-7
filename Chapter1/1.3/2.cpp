#include <string>
#include <iostream>

using namespace std;

string uniq(string ss){
    bool c[256];
    for(int i=0;i<256;i++)
        c[i] = false;

    string result;

    for(int i=0;i<ss.size();i++){
        if(c[ss[i]] != true){
            c[ss[i]] = true;
            result+=ss[i];
        }
    }
    return result;
}

int main(){

    cout<<uniq("aaaaaa")<<endl;
    cout<<uniq("aaaaaabbbbbb")<<endl;
    cout<<uniq("")<<endl;
    cout<<uniq("abababababa")<<endl;
    return 0;
}
