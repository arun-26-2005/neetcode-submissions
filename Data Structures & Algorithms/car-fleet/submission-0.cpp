class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);

        for(int i=0;i<n;i++)
        {
            cars[i]={position[i],speed[i]};
        }
        sort(cars.rbegin(),cars.rend());

        double maxTime=0.0;
        int fleet=0;

        for(int i=0;i<n;i++)
        {
            double currentTime= (double)(target-cars[i].first)/cars[i].second;

            if(currentTime>maxTime)
            {
                maxTime=currentTime;
                fleet++;
            }

        }
        return fleet;

    }
};
