#include <string>
#include <iostream>

using namespace std;

bool isUnique(const string & ss){
    bool c[256];
    for(int i=0;i<256;i++){
        c[i] = false;
    }

    for(int i=0; i<ss.size(); i++){
        if(c[ss[i]] == true)
            return false;
        else
            c[ss[i]] = true;

    }

    return true;
}

#define TestTrue(a,b) do\
    { \
        if((a)!=(b)) \
        {cout<<__FILE__<<":"<<__LINE__<<" error"<<endl;}\
    }while(0)


int main(){

    TestTrue(true,isUnique("abcdefg"));
    TestTrue(false,isUnique("aaaa"));
    TestTrue(false,isUnique("aaaabbbb"));
    return 0;
}
