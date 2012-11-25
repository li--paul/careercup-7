#include <string>
#include <iostream>
#include <algorithm>

// sort it , then remove the duplicate character

using namespace std;


string unique(string  ss){
    string result;

    sort(ss.begin(), ss.end());

    for(int i=0;i<ss.size();i++){
        if(i == 0 || ss[i] != result[result.size()-1])
            result+=ss[i];
    }

    return result;
}

int main(){

    cout<<unique("aaaaaa")<<endl;
    cout<<unique("aaaaaabbbbbb")<<endl;
    cout<<unique("")<<endl;
    cout<<unique("ababababa")<<endl;
    cout<<unique("ababbbaa")<<endl;

    return 0;
}
