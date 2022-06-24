/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */
#include <cctype>
#include <vector>
#include <string>
using namespace std;


// @lc code=start
class Solution {
public:

    void backtracking(string s,int i , vector<string> &res)
    {
        if(i==s.size())
        {
            res.push_back(s);
            return;
        }
        if(!isalpha(s[i]))
            backtracking(s,i+1,res);
        else
        {
            s[i]=tolower(s[i]);
            backtracking(s,i+1,res);
            s[i]=toupper(s[i]);
            backtracking(s,i+1,res);
        }
    }


    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtracking(s, 0, res);
        return res;
    }
};
// @lc code=end

