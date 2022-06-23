/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-13 14:41:26
 */
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include <vector>
using namespace std;

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    
    int numTrees(int n) {
        vector<int>dp(n + 1,0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i ; ++j){
                dp[i] += dp[j-1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

