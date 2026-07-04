class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left_shorter(heights.size(),-1);
        vector<int> right_shorter(heights.size(),n);
        stack<int> st;
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty() || heights[st.top()]<=heights[i])
            {
                st.push(i);
            }
            else 
            {
                if(!st.empty())
                {
                    while(!st.empty() && heights[st.top()]>heights[i])
                    {
                        int index=st.top();
                        st.pop();
                        right_shorter[index]=i;
                    }
                    st.push(i);
                }
            }

        }
        while(!st.empty()) {
    st.pop();
}
        for(int i=heights.size()-1;i>=0;i--)
        {
            if(st.empty() || heights[st.top()]<=heights[i])
            {
                st.push(i);
            }
            else 
            {
                if(!st.empty())
                {
                    while(!st.empty() && heights[st.top()]>heights[i])
                    {
                        int index=st.top();
                        st.pop();
                        left_shorter[index]=i;
                    }
                    st.push(i);
                }
            }

        }
        int max_area=0;
        for(int i=0;i<heights.size();i++)
        {
            int low=left_shorter[i]+1;
            int high=right_shorter[i];
            
            
            int area=(high-low)*heights[i];
            
            if(area>max_area)
            {
                max_area=area;
            }

        }

        return max_area;
    }
};