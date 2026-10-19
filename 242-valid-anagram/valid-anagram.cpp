class Solution {
public:
    bool isAnagram(string s, string t) {
        // check wheter the size of the strings is equal or not 
        if(s.size()!=t.size()){
            return false;
        }

        vector<int> freq(26, 0);

        // all the alphabets in that string will have a frequency of 1
        for(char ch: s){
            freq[ch-'a']++; // this will get the index of that alphabet
        }

        // this will make the frequecy of all the elements common in both the strings as 0 but the one alphabet which is not in the other string has a frequency of 1 if it exists then print false other wise all the alphbets should have the frequency of 0;
        for(char ch: t){
            freq[ch-'a']--;
        }

        for(int x: freq){
            if(x!=0){
                return false;
            }
        }

        return true;
    }
};