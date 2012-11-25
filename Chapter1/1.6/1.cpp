#include <iostream>

using namespace std;

void print(int **a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void exchange(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q =temp;
}

void rotate(int **a, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            exchange(&a[i][j],&a[j][i]);
        }
    }
}

int main(){
    int **A = new int *[10];
    for(int i=0;i<10;i++){
        A[i] = new int [10];
    }
    int total = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            A[i][j] = total++;
    }

    print(A,10);
    rotate(A, 10);
    print(A,10);
    return 0;
}
