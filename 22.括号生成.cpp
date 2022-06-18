/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void Parenthesis(vector<string>& res, string s ,int l , int r, int n){
        if(l > n || r > n || r > l)     return;
        if(l == n && r == n){
            res.emplace_back(s);
        }
        Parenthesis(res , s + '(', l + 1 , r, n);
        Parenthesis(res , s + ')' , l , r + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        Parenthesis(res,"", 0 , 0 , n);
        return res;
    }
};
// @lc code=end

int main(){
    Solution sl;
    sl.generateParenthesis(3);
}
