class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);

        for(char task: tasks)
        {
            count[task-'A']++;
        }
        priority_queue<int> maxHeap;

        for(int x:count)
        {
            if(x)
            {maxHeap.push(x);
            }
        }
        int time=0;
        queue<pair<int,int>> q;
        while(!maxHeap.empty()||!q.empty())
        {
            time++;

            if(!maxHeap.empty())
            {
                int cnt=maxHeap.top()-1;
                maxHeap.pop();
                if(cnt>0)
                {
                    q.push({cnt,time+n});
                }
            }
            else{
                time=q.front().second;
            }

            if(!q.empty() && q.front().second==time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }

        }
        return time;
        
    }
};
