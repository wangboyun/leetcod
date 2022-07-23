/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    void reverseStr(string& s, int start, int end){
        while(start < end){
            swap(s[start++], s[end--]);
        }
    }

    string reverseStr(string s, int k) {
        string res = s;
        int len = s.size(); int i = 0;
        for(i = 0 ; i < len - 2 * k; i += 2*k){
            reverseStr(res,i,i + k - 1);
        }
        if(len - i < k){
            reverseStr(res, i , len - 1);
        }else{
            reverseStr(res,i , i + k - 1);
        }
        return res;
    }
};
// @lc code=end

int main(){
    string s = "abcdefgh";
    Solution sl;
    sl.reverseStr(s, 3);
}
