#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /* 设置一个判断是否溢出的标志 */
        int overflow = 1;
        /* 从最后一个开始+1 */
        int index = digits.size() - 1;
        while(overflow){
            
            if(index >= 0){
                
                int temp = digits[index];
                digits[index] = (temp + 1) % 10;
                /* 如果不溢出了，设置溢出标志为0 */
                if(!(temp + 1 == 10)){
                    overflow = 0;
                } 
                index--;
            }else{
                /* 如果加到第一位还溢出比如说99 + 1，在digits前面插入一个1 */
                digits.insert(digits.begin(), 1);
                break;
            }

        }
        return digits;
    }
};

int main(){
    vector<int> a = {2, 1, 9, 9};
    Solution solution;
    a = solution.plusOne(a);
    for(int i = 0; i < (int)a.size(); i++){
        cout << a[i] << ", ";
    }
    cout << endl;
    return 0;
}