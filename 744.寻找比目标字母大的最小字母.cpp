
/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 二分查找看看
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0; int right = letters.size() - 1;
        int mid = 0;   int res = 0;
        while(left <= right){
            mid = (left + right) >> 1;
            if(letters[mid] == target){
                res = mid + 1;
                break;
            }
            else if(letters[mid] > target){
                right--;
                res = mid;
            }else {
                left++;
                res = mid;
            }
        }
        if(res >= letters.size() - 1){
            if(target > letters[res])
                return letters[0];
            else{
                return letters[res];
            }
        }else{
            for(int i = res; i < letters.size() ; ++i){
                if(letters[i] > target){
                    return letters[i];
                }
            }
        }
        return  letters[0];
    }
};
// @lc code=end
