#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
	int dp[50005][2];
	int maxProfit(vector<int>& prices, int fee) {
		//定义状态dp[i][0]表示第i天手里没有股票的最大利润
		//dp[i][1]表示第i天手里持有股票的最大利润
		dp[0][0] = 0;   //初始条件
		dp[0][1] = -prices[0];
		int n = prices.size();
		for (int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		//最后的结果一定是卖出了股票不会是持有股票,dp[n-1][0];
		return dp[n - 1][0];
	}
};


int main()
{
	Solution s;
	vector<int> a{ 1, 3, 2, 8, 4, 9 };
	cout<<s.maxProfit(a, 2);
	return 0;
}
