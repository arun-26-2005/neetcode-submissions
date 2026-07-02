class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(auto x: stones)
        {
            pq.push(x);
        }
        cout<<pq.size();
        while(pq.size()>1)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y)
            {
                pq.push(abs(y-x));
            }
        }
        if(pq.size())
        return pq.top();

    return 0;
    }
};