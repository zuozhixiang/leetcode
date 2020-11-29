#include <iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;



class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        //贪心,只要剩余的长度大于k,就选择最小的
        int rest = k;
        int start = 0,sz=nums.size();
        vector<int> res(k);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] < s.top() && k - s.size() + 1 < sz - i) {
                s.pop();
            }
            if (s.size() < k + 1) {
                s.push(nums[i]);
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            res[i] = s.top(); s.pop();
        }
        return res;
    }
};
