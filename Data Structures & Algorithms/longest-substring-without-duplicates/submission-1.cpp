class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> k;
        int low=0;
        int high=0;
        int max_count=0;
       while(high<s.length())
       {
        if(k.find(s[high])!=k.end()){
            max_count=max(max_count,high-low);
            k.erase(s[low]);
            low++;
            

        }
        else{
            k.insert(s[high]);
            high++;
           
        }
       }
       max_count=max(max_count,high-low);
       return max_count;

        
    }
};
