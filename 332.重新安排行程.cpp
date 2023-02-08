#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>


using namespace std;

class Solution {
public:
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result){
        if (result.size() == ticketNum + 1){
            return true;
        }
        for(pair<const string, int>& target : targets[result[result.size() - 1]]){
            if (target.second > 0){
                result.push_back(target.first);
                target.second--;
                if(backtracking(ticketNum, result)) return true;    
                target.second++;
                result.pop_back();
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> result;
        for(const vector<string>& vec : tickets){
            targets[vec[0]][vec[1]]++;
        }
        result.push_back("JFK");
        backtracking(tickets.size(), result);
        return result;
    }
};



int main(){
    int n;
    cin >> n;
    vector<vector<string>> tickets(n, vector<string>(2));
    for(int i = 0; i < n; i++){
        cin >> tickets[i][0];
        cin >> tickets[i][1];
    }
    Solution solution;
    vector<string> res = solution.findItinerary(tickets);
    for( string loc : res){
        cout << loc << " ";
    }
    cout << endl;
    return 0;
}