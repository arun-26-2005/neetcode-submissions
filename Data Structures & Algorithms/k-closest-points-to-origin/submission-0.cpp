class Solution {
public:
    priority_queue<pair<double,vector<int>>> pq;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        if(k>=points.size())
        {
            return points;
        }
        for(auto x: points)
        {
            double dist= sqrt((x[0]*x[0]+x[1]*x[1]));
            
            pq.push({dist,x});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size())
        {
            pair<double,vector<int>> temp=pq.top();
            pq.pop();
            result.push_back(temp.second);
        }
        return result;

    }
};