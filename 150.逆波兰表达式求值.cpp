#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
class Solution{
public:
    int evalRPN(vector<string> &tokens){
        stack<int> st;
        for(int i = 0; i < (int)tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                long num1 = st.top();
                st.pop();
                long num2 = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(num2 + num1);
                if(tokens[i] == "-") st.push(num2 - num1);
                if(tokens[i] == "*") st.push(num2 * num1);
                if(tokens[i] == "/") st.push(num2 / num1);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
int main(){
    int n;
    cin >> n;
    vector<string> tokens(n);
    for(int i = 0; i < n; i++){
        cin >> tokens[i];
    }
    Solution solution;
    cout << solution.evalRPN(tokens);
    return 0;
}