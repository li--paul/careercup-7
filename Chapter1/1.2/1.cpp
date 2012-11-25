#include <iostream>

using namespace std;

void exchange(char *p, char *q){
    char t = *p;
    *p = *q;
    *q = t;
}

void reverse(char *p){

    char * start = p;
    char * end = p+strlen(p)-1;
    while( (end-start) >=0){
        exchange(start++,end--);
    }
}

int main(){

    char *p = new char[7];
    strcpy(p,"abcdef");
    p[6] = '\0';

    reverse(p);
    cout<<p<<endl;


    strcpy(p,"abcde");
    p[5] = '\0';
    reverse(p);
    cout<<p<<endl;

    return 0;
}
