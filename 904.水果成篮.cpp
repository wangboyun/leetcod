/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int len = fruits.size();
        if(len <= 2) return len;
        int start = 0 ; int end = 0;
        int res =  -1;
        map<int, int> map;
        for(end = 0; end < len; ++end){
            map[fruits[end]]++;
            while(map.size() > 2){
                res = max(res, end - start);
                auto iter = map.find(fruits[start]);
                if(--iter->second == 0){
                    map.erase(iter);
                }
                start++;
            }
        }
        res = max(res, end - start);
        return res ;
    }
};
// @lc code=end

int main(){
    vector<int> fruits = {1,2,1};
    Solution sl;
    sl.totalFruit(fruits);
}
