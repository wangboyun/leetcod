/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-06 10:31:51
 */
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    /// 贪心算法
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin() , intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        int len = intervals.size();
        bool last = false;
        for(int i = 1; i < len ; ++i){
            int start = intervals[i-1][0];
            int end = intervals[i-1][1];
            while( i < len && intervals[i][0] <= end){
                end = max(end , intervals[i][1]);
                if (i == len - 1){
                    last = true;
                }
                ++i;    
            }
            res.emplace_back(vector<int>{start , end});
        }
        if(last == false){
            res.emplace_back(vector<int>{intervals[len - 1][0] , intervals[len - 1][1] });
        }
        return res;
    }
};
// @lc code=end

void quicksort(vector<vector<int>>& nums,int left , int right){
        if(left >= right)
            return;
        int i = left; int j = right;
        int temp = *nums[left].begin();
        while (i != j) {
            //先在右边找小于 temp 的值
            while(*nums[j].begin() >= temp && i < j)
                j--;
            //再在左边找大于 temp 的值
            while(*nums[i].begin() <= temp && i < j)
                i++;
            // 交换两者的顺序
            if(i < j){
                vector<int> tm = nums[j];
                nums[j] = nums[i];
                nums[i] = tm;
            }  
        
        }
        vector<int> t = nums[left];
        nums[left] = nums[i] ;
        nums[i] = t;

        quicksort(nums,left,i-1);
        quicksort(nums,i+1,right);
       
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int left = 0;
        int right = intervals.size() - 1;
        // 先按照start数值从小到大排序
        quicksort(intervals, left, right);
        for(int i = 0 ; i <  right ; i++){
            if(*intervals[i+1].begin() > *(intervals[i].end()-1) ){
                ans.push_back(intervals[i]);
                continue;
            }
                
            else{
                if(*(intervals[i+1].end()-1) >= *(intervals[i].end()-1)){
                    *intervals[i+1].begin() = *intervals[i].begin();
                }
                else {
                    *intervals[i+1].begin() = *intervals[i].begin();
                    *(intervals[i+1].end()-1) = *(intervals[i].end()-1);
                }
                
            }
        }
      
        ans.push_back(intervals[right]);
        
        return ans;
    }