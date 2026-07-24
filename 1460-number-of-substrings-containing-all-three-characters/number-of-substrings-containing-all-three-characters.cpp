class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        vector<int> freq(3, 0);
        int total = 0;

        while (right < s.length()) {
            char curr = s[right];
            ++freq[curr - 'a'];

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                total += s.length() - right;

                char leftChar = s[left];
                --freq[leftChar - 'a'];
                ++left;
            }

            ++right;
        }

        return total;
    }
};