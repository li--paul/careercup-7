#include <iostream>
#include <string>

using namespace std;

bool isAnagram(const string & s1, const string &s2){
    if(s1.size() != s2.size())
        return false;

    int count[256];
    for(int i=0;i<256;i++)
        count[i]=0;


    for(int i=0;i<s1.size();i++){
        count[s1[i]]++;
    }

    for(int i=0;i<s2.size();i++){
        if(--count[s2[i]] <0){
            return false;
        }
    }

    return true;
}

int main(){

    cout<<boolalpha <<isAnagram("abcde","deabc")<<endl;
    cout<<boolalpha <<isAnagram("abcd","deabc")<<endl;
    cout<<boolalpha <<isAnagram("abcde","akcde")<<endl;
    return 0;
}
