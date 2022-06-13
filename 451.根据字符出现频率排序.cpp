/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:

    struct cmp{
        bool operator()(pair<char , int> a, pair<char , int> b){
            return a.second > b.second;
        }
    };

    string frequencySort(string s) {
        string res;
        map<char , int> hashmap;
        for(auto i : s){
            hashmap[i]++;       /// hashmap[i] 查找到的char元素 ++；
        }
        vector<pair<char , int>> ans;
        for(auto i : hashmap){
            ans.emplace_back(i);
        }

        sort(ans.begin(), ans.end(), cmp());
        for(auto& i : ans){
            for(int n = 0 ; n < i.second; ++n){
                res += i.first;
            }
        }
        return res;
    }
};
// @lc code=end

