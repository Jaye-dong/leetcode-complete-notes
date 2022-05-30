#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 0;
        /* 这里的num看似是边界，实际上是二分查找的第一种写法 */
        long long right = num;
        while(left <= right){
            long long mid = left + ((right - left) >> 1);
            long long mid2 = mid * mid;
            if(mid2 == num){
                return true;
            }else if(mid2 < num ){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }
};

int main(){
    vector<int> a = {2, 1, 9, 9};
    Solution solution;
    
    for(int i = 0; i < (int)a.size(); i++){
        cout << solution.isPerfectSquare(a[i]) << ", ";
    }
    cout << endl;
    return 0;
}