#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings){

        /* 先默认给所有孩子一个糖果 */
        vector<int> vceCandy(ratings.size(), 1);

        /* 从左到右，比较右边的比左边大的情况，如果比左边大则在左边的基础上+1 */
        for(int i = 1; i < ratings.size(); i++){
            if (ratings[i] > ratings[i-1]){
                vceCandy[i] = vceCandy[i-1] + 1;
            }
        }

        /* 从右到左，比较左边的比右边大的情况，这个时候要考虑是不是已经够大了，够大了不用再加 */
        /* vecCandy 1 2 1 */
        /* ratings  7 8 7 */
        /* 这种属于够大了 */
        for(int i = ratings.size()- 2; i >= 0; i--){
            if (ratings[i] > ratings[i+1]){
                vceCandy[i] = max(vceCandy[i], vceCandy[i+1] + 1);
            }
        }

        /* 求和 */
        int sum = 0;
        for(auto a : vceCandy){
            sum += a;
        }
        return sum;
    }
};

void transStr2Nums(const string& s, vector<int>& nums, const char delim){
    int start = 0;
    int i = 0;
    while(i < s.size()){
        i++;
        if (i == s.size() || s[i] == delim){
            string temp = s.substr(start, i - start);
            nums.push_back(atoi(temp.c_str()));
            start = i + 1;
        }
    }
}


int main(){
    string s;

    getline(cin, s);
    vector<int> nums;
    transStr2Nums(s, nums, ',');

    cout << Solution().candy(nums) << endl;
    return 0;
}