/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:

    bool isPalindrome(const string& s , int start  , int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end --;
        }
        return true;
    }

    void backtracking(string s , int startindex, vector<string>& ve,  vector<vector<string>>& res ){
        if(startindex >= s.size()){
            res.emplace_back(ve);
            return;
        }

        for(int i = startindex ; i < s.size() ; ++i){
            if(isPalindrome(s, startindex, i)){
                string str = s.substr(startindex, i - startindex + 1);
                ve.emplace_back(str);
            }else{
                continue;
            }
            backtracking(s , i + 1 , ve , res);
            ve.pop_back();
        }
        return ;
    }

    vector<vector<string>> partition(string s) {
        vector<string> ve; vector<vector<string>> res;
        backtracking(s, 0, ve, res);
        return res;
    }
};
// @lc code=end

