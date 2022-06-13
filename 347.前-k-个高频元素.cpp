#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    struct cmp{
        bool operator() (const std::pair<int , int>& a , const std::pair<int , int>& b){
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>  res;
        vector<std::pair<int , int>> ans;
        int n = 0;
        map<int , int> hashmap;
        for(auto i : nums){
            hashmap[i]++;
        }

        for(auto i : hashmap){
            ans.emplace_back(i);
        }

        sort(ans.begin(), ans.end(), cmp());
        while(k--){
            res.emplace_back(ans[n++].first);
        }
        return res;
    }
};


// @lc code=end
