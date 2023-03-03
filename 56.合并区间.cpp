#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        if(intervals.size() <= 1) return intervals; 
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }else{
                result.push_back(intervals[i]);
            }

        }
        return result;
    }
};

vector<int> transStr2Nums(string& s){
    int i = 0;
    int start = 0;
    vector<int> nums;
    while(i < s.size()){
        i++;
        if(i == s.size() || s[i] == ','){
            string temp = s.substr(start, i - start);
            
            if(temp[0] == '['){
                temp.erase(temp.begin());
            }
            if(temp[temp.size()-1] == ']'){
                temp.erase(temp.begin() + temp.size()-1);
            }
            nums.push_back(atoi(temp.c_str()));
            start = i + 1;
        }
    }
    return nums;
}

int main(){
    string s;
    while(cin >> s){
    
        vector<int> nums = transStr2Nums(s);
        vector<vector<int>> points;
        for(int i = 0; i < nums.size(); i+=2){
            points.push_back(vector<int>{nums[i], nums[i+1]});
        }
        vector<vector<int>> res =  Solution().merge(points);
        for(auto v : res){
            for(int num : v){
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}