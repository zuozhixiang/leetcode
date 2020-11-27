#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;



class Solution {
public:
    int longestSubstring(string s, int k) {
        //统计每个字符出现的次数
        int cnt[150] = {0};
        vector<int> split;
        for (int i = 0; i < s.length(); i++) cnt[s[i]]++;
        for (int i = 0; i < s.length(); i++) {
            if (cnt[s[i]] > 0 && cnt[s[i]] < k) split.push_back(i);
        }
        if (split.size() == 0) return s.length();
        int left = 0;
        split.push_back(s.length());
        int res = 0;
        for (int i = 0; i < split.size(); i++) {
            int len = split[i] - left + 1;
            if(len>res) 
            res = max(res, longestSubstring(s.substr(left, len), k));
            left = split[i] + 1;
        }
        return res;
    }
};
int main()
{
    Solution s;
    s.longestSubstring("aaaaaaaaabbbcccccddddd" ,5);
	return 0;
}
