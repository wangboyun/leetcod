/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

/// 利用
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int has[26] = {0};
        for(int i = 0 ; i < s.size() ; ++i){
            has[s[i] - 'a']++;
        }
        for(int i = 0 ; i < t.size(); ++i){
            has[t[i] - 'a']--;
        }

        for(int i = 0 ; i < 26; ++i){
            if(has[i] != 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
/*
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t ;
    }
*/

/*
    bool isAnagram(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        if(s_len != t_len)      return false;
        map<char, int> s_map;
        map<char, int> t_map;
        for(int i = 0 ; i < s_len; ++i){
            s_map[s[i]]++;
            t_map[t[i]]++;
        }
        for(auto i : s_map){
            if(i.second != t_map.find(i.first)->second){
                return false;
            }
        }
        return true;
    }
*/