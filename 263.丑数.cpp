/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */
#include <set>

using namespace std;
// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        if(n == 1){
            return true;
        }
        if(n < 0){
            if(n == -2147483648){
                return false;
            }else {
                n = -n;
            }
        }
        set<int> se = Qualitative_factors(n);
        for(auto i : se){
            // 判断是否质因数是2 3 5
            if(i != 2 && i != 3){
                if(i != 5){
                    return false;
                }
                continue;
            }
        }
        return true;
    }
    /*求整数的质因数*/
    std::set<int> Qualitative_factors(unsigned int n){
        std::set<int> set;
        for(int i = 2; i <= n ;++i){
           while(n % i == 0)
            {
			    set.insert(i);
			    n /= i;
            }
		} 
        return set;
    }
};
// @lc code=end

