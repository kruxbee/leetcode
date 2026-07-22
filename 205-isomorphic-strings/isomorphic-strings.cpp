class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_map<char,char>np;
        int n = s.size();
        int m = t.size();
        if(m == n){
            for(int i =0; i < n; i++){
                char c1 = s[i];
                char c2 = t[i];
                if(mp.count(c1)&& mp[c1] != c2){
                    return false;
                }
                if(np.count(c2) && np[c2] != c1){
                    return false;
                }
                mp[c1] = c2;
                np[c2] = c1;
            }
            return true;
        }
        return false;
    }
};