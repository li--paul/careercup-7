#include <string>
#include <iostream>

using namespace std;

bool isRotate(const string &s1, const string & s2){
    if(s1.size() != s2.size())
        return false;


    string ss = s2+s2;
    if(ss.find(s1) != string::npos)
        return true;
    else
        return false;
            
}

int main(){

    cout<<boolalpha << isRotate("apple", "pplea") <<endl;
    cout<<boolalpha << isRotate("waterbottle", "erbottlewat")<<endl;
    cout<<boolalpha << isRotate("waterbottle", "rebottlewat")<<endl;
    return 0;
}
