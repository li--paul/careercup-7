#include <iostream>

long long f(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(n<0)
        return -1;
    else{
        return f(n-1)+f(n-2);
    }
}

int main(){
    return 0;
}
