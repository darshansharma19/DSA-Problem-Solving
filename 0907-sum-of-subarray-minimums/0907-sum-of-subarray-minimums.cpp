class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        stack<pair<int, int>> s; 
        vector<int> left(n), right(n);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top().first > arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top().second;
            s.push({arr[i], i});
        }

        while (!s.empty()) {
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top().first >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top().second - i;
            s.push({arr[i], i});
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return result;
    }
};
