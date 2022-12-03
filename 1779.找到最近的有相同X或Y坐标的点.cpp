#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_abs = INT_MAX;
        int min_index = -1;
        for(size_t i = 0; i < points.size(); i++){
            if(points[i][0] == x || points[i][1] == y){
                int distance = abs(points[i][0]-x) + abs(points[i][1] - y);
                if(min_abs > distance){
                    min_index = i;
                    min_abs = min(min_abs, distance);
                }
            }
        }
        return min_index;
    }
};

int main(){
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    vector<vector<int>> points(n);
    for(int i= 0; i < n; i++){
        int xi, yi;
        cin >> xi >> yi;
        points[i].push_back(xi);
        points[i].push_back(yi);
    }

    Solution solution;
    cout << solution.nearestValidPoint(x, y, points) << endl;
    

    return 0;
}