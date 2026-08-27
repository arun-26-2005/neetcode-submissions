class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void init(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }   
    }
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }
    bool DSU(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a==b)
            return false;
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int components=n;
        init(n);
        for(auto edge:edges)
        {
            if(DSU(edge[0],edge[1]))
                components--;
        }
        return components;

    }
};
