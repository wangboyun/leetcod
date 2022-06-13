/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-03 11:01:51
 */
/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
   
    int longestPalindrome(string s) {
        unordered_multimap<char, int> map;
        unordered_set<char> set;
        int ans = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            set.insert(s[i]);
            map.insert(make_pair(s[i], i));
        }
        for(auto i : set){
            int num = map.count(i);
            if(num % 2){
                ans += num - 1;
            }else {
                ans += num;
            }
        }
        if(ans < s.size())
            return ans + 1;
        return ans;
    }
};
// @lc code=end

