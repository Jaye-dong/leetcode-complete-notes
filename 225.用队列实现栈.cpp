#include <queue>
#include <iostream>

using namespace std;

class MyStack{
public:
    MyStack(){
        
    }

    void push(int i){
        q1.push(i);
    }

    int pop(){
        int ret;
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        ret = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ret;
    }

    int top(){
        int ret = pop();
        q1.push(ret);
        return ret;
    }

    bool empty(){
        return q1.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};

int main(){
    MyStack st;
    st.push(1);
    st.push(2);
    st.pop();
    cout << st.top();
    return 0;
}