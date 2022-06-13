/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())
            return false;
        for(int i = 0 ; i < ransomNote.size() ; ++i){
            auto it = magazine.find(ransomNote[i]);
            if(it == magazine.npos){
                return false;
            }else{
                magazine.erase(it , 1);
            }
        }
        return true;
    }
};
// @lc code=end

