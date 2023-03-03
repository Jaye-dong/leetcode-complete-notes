#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points){
        int count = 1;
        sort(points.begin(), points.end(), cmp);
        for(int i = 1; i < points.size(); i++){
            if (points[i][0] <= points[i - 1][1]){
                points[i][1] = min(points[i][1], points[i - 1][1]);
            } else{
                count++;
            }
        }

        return count;
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
        cout << Solution().findMinArrowShots(points) << endl;
    }
    return 0;
}