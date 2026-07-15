class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        vector<pair<int, char>> v;

        for (auto x : mp) {
            v.push_back({x.second, x.first});
        }

        sort(v.rbegin(), v.rend());

        string ans = "";

        for (auto x : v) {
            ans += string(x.first, x.second);
        }

        return ans;
    }
};