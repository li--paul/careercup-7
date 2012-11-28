#include <iostream>
#include <stack>

using namespace std;

class MyQueue{
    public:
        void push(int i){
            m_push.push(i);
        }

        void pop(){
            if(m_pop.empty()){
                while(!m_push.empty()){
                    m_pop.push(m_push.top());
                    m_push.pop();
                }

            }

            m_pop.pop();

        }

        int top(){
            if(m_pop.empty()){
                while(!m_push.empty()){
                    m_pop.push(m_push.top());
                    m_push.pop();
                }

            }
            return m_pop.top();
        }

        bool empty(){
            if(m_pop.empty() && m_push.empty())
                return true;
            return false;
        }

    private:
        stack<int> m_pop;
        stack<int> m_push;
};

int main(){
    MyQueue q;
    for(int i=0;i<10;i++){
        q.push(i);
    }


    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;


    for(int i=0;i<10;i++)
        q.push(i);

    for(int i=0;i<5;i++)
    {
        cout<<q.top()<<" ";
        q.pop();
    }

    for(int i=10;i<15;i++)
        q.push(i);
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;


    return 0;
}
