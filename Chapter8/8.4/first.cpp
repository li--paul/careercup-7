#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> gen(const string &ss){
    vector<string> vec;
    if(ss.length() == 1){
        vec.push_back(ss);
        return vec;
    }
    else{
        vector<string> result = gen(ss.substr(1));
        for(int i=0;i<result.size();i++){
            for(int j=0;j<=result[i].length();j++){
                vec.push_back(result[i].substr(0,j) + ss[0] + result[i].substr(j));
            }
        }
        return vec;
    }

}

int main(){

    string ss = "abcd";
    vector<string> result = gen(ss);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
