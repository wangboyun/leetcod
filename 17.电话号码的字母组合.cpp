/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    }; 
    
    void backtracking(const string& digits, int index ,vector<string>& result , string& s){
        if(index == digits.size()){
            result.emplace_back(s);
            return ; 
        }
        int digit = digits[index] - '0';        // 将index指向的数字转为int
        string letters = letterMap[digit];      // 取数字对应的字符集
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            // 处理
            backtracking(digits, index + 1, result, s);    // 递归，注意index+1，一下层要处理下一个数字了
            s.pop_back();                       // 回溯
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        res.clear();
        string s;
        s.clear();
        if(digits == ""){
            return res;
        }
        backtracking(digits , 0 , res, s);
        return res;
    }
};
// @lc code=end

int main(){
    Solution sl;
    sl.letterCombinations("23");
}