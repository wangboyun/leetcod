/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        // 特殊输入
        if(n < 7) 
            return n;
   
        // 辅助容器
        vector<int> res(n);
        for(int i = 0; i < 6; ++i)
            res[i] = i + 1;

        // 辅助变量
        int t2 = 3;
        int t3 = 2;
        int t5 = 1;
 
        // 按序计算丑数
        for(int i = 6; i < n; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if(res[i] == res[t2] * 2 ) 
                t2++;
            if(res[i] == res[t3] * 3 ) 
                t3++;
            if(res[i] == res[t5] * 5 ) 
                t5++;
        }
        return res[n-1];
    }
};
// @lc code=end

