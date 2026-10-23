class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1); // points to its ascii value and check the value there 
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxLen = 0;
        
        while(r<n){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                l = hash[s[r]]+1;
            }
            int len = r-l+1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};