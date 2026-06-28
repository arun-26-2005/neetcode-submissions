class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int low=0;
        int max_freq=0;
        int result=0;
        for(int high=0;high<s.length();high++){
            count[s[high]]++;
            max_freq=max(max_freq,count[s[high]]);

            while((high-low+1)-max_freq>k){
                count[s[low]]--;
                low++;
            }
            result=max(result,high-low+1);
        }
        return result;
        
    }
};
