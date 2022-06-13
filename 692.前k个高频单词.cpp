/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:

    struct cmp{
        bool operator()(const std::pair<string, int>& a, 
                        const std::pair<string, int>& b){
            if(a.second > b.second){
                return true;
            }else if (a.second == b.second) {
                return a.first < b.first;
            }else{
                return false;
            }
        }
    };


    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string , int> hashmap;
        for(auto i : words){
            hashmap[i]++;
        }

        vector<std::pair<string, int>> ans;
        for(auto i : hashmap){
            ans.emplace_back(i);
        }

        vector<string> res;
        int n = 0;
 
        sort(ans.begin(), ans.end(), cmp());
        while(k){
            res.emplace_back(ans[n++].first);
            k--;
        }
        return res;
    }
};
// @lc code=end

