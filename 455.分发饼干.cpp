#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) const {
        /* ���ɺ�С�������մ�С�����������*/
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        /* ���ڴ�Ž���ͱ���С�� */
        int index = 0;
        /* ���ȱ������ɣ���Ϊ���ɲ���Ҫ��С�ı��ɣ��޷������κ�С���ģ��������� */
        for(int i = 0; i < s.size(); i++){
            /* ��Զ�ǵü��߽� */
            if(index < g.size() && s[i] >= g[index]){
                index++;
            }
        }
        return index;
    }
};


int main(){
    vector<int> g{1, 2, 3};
    vector<int> s{1, 1};
    Solution solu;

    cout << solu.findContentChildren(g, s) << endl;
    return 0;
}