#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

/*
 * ���������ź��������A��B, �����鳤�ȶ�ΪN, ���Ǵ����������ȡһ��Ԫ�����, �����͵õ���N^2����
 * Ҫ�����N^2���Ͱ���������ռ䲻�ܳ���O(N)��
 *
 */

using namespace std;

const int NUMBER = 100;

struct node{
    int value;
    int a;
    int b;
};

class cmp{
    public:
        bool operator()(const node & n1, const node &n2){
            return n1.value>n2.value;
        }
};

void output(const vector<int> &v1, const vector<int> &v2){

    priority_queue<node, vector<node>, cmp> q;
    for(int i=0;i<v2.size();i++){
        node n;
        n.value = v1[0] + v2[i];
        n.a = 0;
        n.b = i;
        q.push(n);
    }

    while(q.size()>0){
        node n = q.top();
        q.pop();
        cout<<n.value<<"\t" << v1[n.a]<<"\t"<<v2[n.b]<<endl;
        if(n.a < v1.size()-1){
            n.a++;
            n.value = v1[n.a] + v2[n.b];
            q.push(n);
        }
    }
}


int main(){
    vector<int> v1;
    vector<int> v2;

    srandom(time(NULL));
    for(int i=0;i<NUMBER;i++){
        v1.push_back(random() % 10000);
        v2.push_back(random() % 10000);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    output(v1,v2);

    return 0;
}
