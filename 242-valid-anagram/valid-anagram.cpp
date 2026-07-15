class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char, int>mp;
        
        if(n != m){
            return false;
        }
        
        else{
            for(char i :s){
                mp[i]++;
            }
            for(char i :t){
                mp[i]--;
            }
            for(auto it : mp){
                if(it.second != 0){
                    return false;
                }
            }

        }
        return true;
    }
};