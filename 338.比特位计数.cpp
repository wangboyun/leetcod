/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-01 21:23:39
 */
/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int CountBits(int n){
        int res = 0;
        for(; n ; ++res){
            n &= n - 1;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i = 0 ; i <= n ; ++i){
            v.emplace_back(CountBits(i));
        }
        return v;
    }
};
// @lc code=end

