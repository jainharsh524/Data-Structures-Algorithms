class Solution {
public:
    vector<long long> findNSE(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> nse(n);
        stack<long long> st;

        for (long long i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<long long> findPSEE(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> pse(n);
        stack<long long> st;

        for (long long i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    vector<long long> findNGE(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> nse(n);
        stack<long long> st;

        for (long long i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()]<=arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<long long> findPGEE(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> pse(n);
        stack<long long> st;

        for (long long i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<long long> nse = findNSE(arr);
        vector<long long> psee = findPSEE(arr);
        long long total = 0;
        for (long long i = 0; i < arr.size(); i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total = total + (right * left * 1LL * arr[i]);
        }
        return total;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<long long> nse = findNGE(arr);
        vector<long long> psee = findPGEE(arr);
        long long total = 0;
        for (long long i = 0; i < arr.size(); i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total = total + right * left * 1LL * arr[i];
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};
