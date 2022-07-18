/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    void infact(int x , int y ,vector<vector<char>>& grid){
        if(x < 0 || x >= grid.size() || 
            y < 0 || y >= grid[0].size() || grid[x][y] != '1'){
            return;
        }
        grid[x][y] = '2';
        infact(x + 1 , y , grid);
        infact(x - 1, y , grid);
        infact(x , y + 1, grid);
        infact(x, y - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0 ; i < grid.size(); ++i){
            for(int j = 0 ; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    infact(i , j , grid);
                    res++;
                }
            }
        }
        return res;     
    }
};
// @lc code=end

class Solution1 {
public:
    bool isIsland(int x, int y , vector<vector<char>>& grid){
        return 0 <= x && x < grid.size() 
            && 0 <= y && y < grid[0].size() 
            && grid[x][y] == '1';
    }

    void checkAndEnqueue(int x, int y, vector<vector<char>>& grid, queue<pair<int , int>>& que) {
        if (isIsland(x - 1, y, grid)) que.push(make_pair(x - 1, y));
        if (isIsland(x + 1, y, grid)) que.push(make_pair(x + 1, y));
        if (isIsland(x, y - 1, grid)) que.push(make_pair(x, y - 1));
        if (isIsland(x, y + 1, grid)) que.push(make_pair(x, y + 1));
    }

    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int , int>> que;
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), ans = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            	// 第一次碰到陆地
                if (grid[i][j] == '1') {
                    que.push(make_pair(i, j));
                    ans++;
                    // 探索这块岛屿所有相连的陆地
                    while (!que.empty()) {
                        pair<int, int> root = que.front();
                        que.pop();
                        int x = root.first, y = root.second;
                        if (grid[x][y] == '0') continue;
                        // 标记为已探索
                        grid[x][y] = '0';
                        // 将相连的陆地放入探险队列
                        checkAndEnqueue(x, y,grid ,que);
                    }
                }
            }
        }
        return ans;
    }
};