/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    void backtracking(int n , int k , int index ,vector<int>& ve, vector<vector<int>>& res){
        if(index > k){
            res.emplace_back(ve);
            return;
        }
        for(int i = index ; i <= n ; ++i){
            if(ve.size()){
                if(i == ve.back() || i < ve.back())
                    continue;
            }
                
            ve.emplace_back(i);
            backtracking(n , k , index + 1, ve, res);
            ve.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> ve;
        vector<vector<int>> res;
        backtracking(n ,k , 1, ve , res);
        return res;
    }
};
// @lc code=end

int main(){
    Solution sl;
    sl.combine(4, 2);
}