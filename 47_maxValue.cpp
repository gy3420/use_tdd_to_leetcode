/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector <int> > ans(row ,vector<int>(col,0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i != 0 && j != 0)
                {
                     ans[i][j] = grid[i][j] + max(ans[i-1][j], ans[i][j-1]);
                }
                else if (i == 0 && j != 0)
                {
                     ans[i][j] = grid[i][j] + ans[i][j-1];
                }
                else if (i != 0 && j == 0)
                {
                     ans[i][j] = grid[i][j] + ans[i-1][j];
                }
                else
                {
                    ans[i][j] = grid[i][j];
                }
            }
            
        }
        return ans[row-1][col-1];
        
    }
};

