#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Stack{
    public:
        Stack(){
            m_vec.push_back(stack<int>());
            m_push= 0;
            m_size = 100;
        }

        void push(int i){
            if(m_vec[m_push].size() >= m_size){
                m_vec.push_back(stack<int>());
                m_push++;
            }
            m_vec[m_push].push(i);
        }

        void pop(){
            if(m_vec[m_push].empty())
                m_push--;

            m_vec[m_push].pop();
        }

        int top(){
            if(m_vec[m_push].empty())
                m_push--;

            return m_vec[m_push].top();
        }

        bool empty(){
            if(m_push == 0 && m_vec[0].empty())
                return true;
            return false;
        }

    private:
        vector<stack<int> > m_vec;
        int m_push;
        int m_size;


};

int main(){
    Stack s; 

    for(int i=0;i<10;i++){
        s.push(i);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    for(int i=0;i<20;i++){
        s.push(i);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    for(int i=0;i<15;i++){
        s.push(i);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
