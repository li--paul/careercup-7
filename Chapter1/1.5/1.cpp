#include <iostream>
#include <string>

using namespace std;

string replace(const string & ss){
    string result;

    for(int i=0;i<ss.size();i++){
        if(ss[i] == ' '){
            result += "%20";
        }
        else 
            result += ss[i];
    }

    return result;
}

int main(){
    cout<<replace("hello world")<<endl;
    return 0;
}
