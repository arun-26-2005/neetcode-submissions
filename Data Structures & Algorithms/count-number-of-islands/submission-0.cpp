class Solution {
public:
void bfs(int i,int j,vector<vector<bool>>& visited,vector<vector<char>>& grid)
{
    queue<pair<int,int>> q;
    visited[i][j]=true;
    q.push({i,j});
    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();

        if(a+1<grid.size() && grid[a+1][b]=='1' && !visited[a+1][b])
        {
            q.push({a+1,b});
            visited[a+1][b]=true;
        }
        if(b+1<grid[0].size() && grid[a][b+1]=='1' && !visited[a][b+1])
        {
             q.push({a,b+1});
            visited[a][b+1]=true;
        }
        if(a-1>=0 && grid[a-1][b]=='1' && !visited[a-1][b])
        {
            q.push({a-1,b});
            visited[a-1][b]=true;
        }
        if(b-1>=0 && grid[a][b-1]=='1' && !visited[a][b-1])
        {
            q.push({a,b-1});
            visited[a][b-1]=true;
        }

    }
}

    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    bfs(i,j,visited,grid);
                    count++;
                    
                }
            }
        }
        return count;

    }
};
