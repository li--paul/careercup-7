#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(vector<vector<int> > & vec){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

void convert(vector<vector<int> > & vec){
    set<int> m,n;
   
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            if(vec[i][j] ==0){
                m.insert(i);
                n.insert(j);
            }
        }
    }

    set<int>::iterator it = m.begin();
    for(;it!=m.end();++it){
        int i = (*it);
        for(int j=0;j<vec[i].size();j++)
            vec[i][j] = 0;
    }


    it = n.begin();
    for(;it != n.end();++it){
        int j =(*it);

        for(int i=0;i<vec.size();i++){
            vec[i][j] = 0;
        }
    }
}

int main(){

    vector<vector<int> > vec;

    // 1 0 2
    // 0 2 3
    // 1 2 3
    vector<int> v ;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    vec.push_back(v);

    v.clear();
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    vec.push_back(v);

    v.clear();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vec.push_back(v);
    print(vec);
    convert(vec);
    print(vec);
    return 0;
}
