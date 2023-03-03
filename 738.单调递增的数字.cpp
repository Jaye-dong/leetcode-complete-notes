#include <iostream>
#include <string>


using namespace std;



class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        /* 转化为字符串 */
        string num = to_string(n);

        /* 记录开始赋值为9的位置，等于size()是为了兼容原本就有序的情况 */
        int flag = num.size();

        /* 从后向前遍历，贪心经常是这样，记住 */
        for(int i = num.size() - 1; i > 0; i--){
            /* 如果前面的比后面的要大,前面的减一，后面的置为9 */
            if(num[i-1] > num[i]){
                flag = i;
                num[i-1]--;
            }
        }

        /* 从flag开始置为9 */
        for(int i = flag; i < num.size(); i++){
            num[i] = '9';
        }
        /* 字符串转换为数字 */
        return stoi(num);
    }
};


int main(){
    int n;
    while(cin >> n){
        cout << Solution().monotoneIncreasingDigits(n) << endl;
    }
    
    
    return 0;
}