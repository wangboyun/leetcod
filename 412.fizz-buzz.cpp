/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        string s = "";
        for(int i = 1 ; i <= n ; ++i ){
            if(i % 3 == 0 && i % 5 == 0){
                s = "FizzBuzz";
            }else if(i % 3 == 0 && i % 5 != 0){
                s = "Fizz";
            }else if(i % 5 == 0 && i % 3 != 0){
                s = "Buzz";
            }else {
                s = to_string(i);
            }
            ans.emplace_back(s);
        }
        return ans;
    }
};
// @lc code=end

