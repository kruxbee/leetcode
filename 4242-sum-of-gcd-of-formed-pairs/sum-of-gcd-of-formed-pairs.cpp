class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd;

        long long ans = 0;
        int j = n - 1;
        int mxi = nums[0];

        for (int i = 0; i < n; i++) {
            mxi = max(mxi, nums[i]);
            prefixGcd.push_back(gcd(nums[i], mxi));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        for (int i = 0; i < n / 2; i++) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            j--;
        }

        return ans;
    }
};