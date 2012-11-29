#include <iostream>
#include <queue>

using namespace std;

int ** A;


bool connect(int n, int x, int y){
    queue<int> q;

    q.push(x);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i =0;i<n;i++){
            if(A[temp][i] == 1){
                if(i == y)
                    return true;
                q.push(i);
                A[x][i] = 2; // checked 
            }
        }

    }


    return false;
}


int main(){
    int n;
    cin>>n;

    A = new int *[n];
    for(int i=0;i<n;i++){
        A[i] = new int [n];
        for(int j=0;j<n;j++){
            A[i][j] = 0;
        }
    }

    int m;
    cin>>m;

    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        A[x][y] = 1;
    }


    cin>>x>>y;
    cout<<boolalpha<<connect(n,x,y)<<endl;

    return 0;
}
