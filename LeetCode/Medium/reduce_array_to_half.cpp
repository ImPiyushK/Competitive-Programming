class Solution {
public:
    int minSetSize(vector<int>& A) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int max = 0;
        int n = A.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] > max) max = A[i];
        }

        int hash[max + 1];

        for (int i = 0; i < max + 1; i++) {
            hash[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            hash[A[i]]++;
        }

        sort(hash, hash + max + 1, greater<int>());

        int i;
        for (i = 0; i < max + 1; i++) {
            sum = sum + hash[i];
            if (sum >= n / 2) break;
        }

        return i + 1;

    }
};