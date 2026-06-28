class Solution {
public:
    void bfs(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &grid,queue<pair<int,int>> &q,vector<vector<int>> &distance)
    {
        int count=0;
        visited[i][j]=true;
        
        q.push({i,j});
        while(!q.empty())
        {
            int m=q.front().first;
            int n=q.front().second;
            q.pop();
            if(m+1<grid.size() && !visited[m+1][n] && grid[m+1][n]>0)
            {
                q.push({m+1,n});distance[m+1][n]=distance[m][n]+1;
                visited[m+1][n]=true;
            }
            if(m-1>=0 && !visited[m-1][n] && grid[m-1][n]>0)
            {
                q.push({m-1,n});distance[m-1][n]=distance[m][n]+1;
                visited[m-1][n]=true;
            }
            if(n-1>=0 && !visited[m][n-1] && grid[m][n-1]>0)
            {
                q.push({m,n-1});distance[m][n-1]=distance[m][n]+1;
                visited[m][n-1]=true;
            }
            if(n+1<grid[0].size() && !visited[m][n+1] && grid[m][n+1]>0)
            {
                q.push({m,n+1});distance[m][n+1]=distance[m][n]+1;
                visited[m][n+1]=true;
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<int>> distance(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        bfs(q.front().first,q.front().second,visited,grid,q,distance);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(distance[i][j]>0 && grid[i][j]>0)
                {
                    grid[i][j]=distance[i][j];
                    
                }
            }
        }


        
    }
};
