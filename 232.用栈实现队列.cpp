#include <iostream>
#include <stack>

using namespace std;
class MyQueue{

public:
    MyQueue(){

    }
    void push(int i){
        s1.push(i);
    }
    int pop(){
        int ret = -1;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }          
        }
        ret = s2.top();
        s2.pop();
        return ret;
    }

    bool empty(){
        return s1.empty() && s2.empty();
    }
    int peek(){
        int res = pop();
        s2.push(res);
        return res;
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.pop();
    cout << q.peek();
    return 0;
}