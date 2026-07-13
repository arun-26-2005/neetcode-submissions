class Solution {
public:
void bfs(int i,int j,int& area,vector<vector<bool>>& visited,vector<vector<int>>& grid)
{
    queue<pair<int,int>> q;
    visited[i][j]=true;
    q.push({i,j});
    area++;
    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();

        if(a+1<grid.size() && grid[a+1][b] && !visited[a+1][b])
        {
            q.push({a+1,b});
            visited[a+1][b]=true;
            area++;
        }
        if(b+1<grid[0].size() && grid[a][b+1] && !visited[a][b+1])
        {
             q.push({a,b+1});
            visited[a][b+1]=true;
            area++;
        }
        if(a-1>=0 && grid[a-1][b] && !visited[a-1][b])
        {
            q.push({a-1,b});
            visited[a-1][b]=true;
            area++;
        }
        if(b-1>=0 && grid[a][b-1] && !visited[a][b-1])
        {
            q.push({a,b-1});
            visited[a][b-1]=true;
            area++;
        }

    }
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int area=0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                
                if(grid[i][j] && !visited[i][j])
                {
                    bfs(i,j,area,visited,grid);
                    maxArea=max(maxArea,area);
                    area=0;
                    
                }
            }
        }
        return maxArea;;

        
    }
};
