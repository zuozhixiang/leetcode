// 最小的k个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0) return {};
        if (k >= arr.size()) return arr;
        int left = 0, right = arr.size() - 1;
        do {
            int pivot = find(arr, left, right);
            if (pivot == k) break;
            else if (pivot > k) {
                right = pivot - 1;
            }
            else {
                left = pivot + 1;
            }
        } while (true);
        vector<int> res(arr.begin(),arr.begin()+k);
        return res;
    }
    int find(vector<int>& a,int left,int right)
    {
        int i = left, j = right+1;
        int tmp = a[left];
        while (true) {
            while (i < right && a[++i] < tmp);
            while (j > left && a[--j] > tmp);
            if (i >= j) break;
            swap(a[i], a[j]);
        }
        swap(a[j], a[left]);
        return j;
    }
};
int main()
{
    vector<int> a = { 1,3,5,7,2,4,6,8 };
    Solution s;
    vector<int> res=s.smallestK(a, 6);
    for (int& i : res) cout << " " << i;
}

