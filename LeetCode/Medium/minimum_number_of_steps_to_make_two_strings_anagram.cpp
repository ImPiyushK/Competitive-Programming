class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> scount(26);
        vector<int> tcount(26);
        int n = s.length(), m = t.length();
        for (int i = 0; i < n; i++) scount[s[i] - 'a']++;
        for (int i = 0; i < m; i++) tcount[t[i] - 'a']++;

        // for(int i=0;i<26; i++) cout<<scount[i]<<" "; cout<<endl;
        // for(int i=0;i<26; i++) cout<<tcount[i]<<" "; cout<<endl;
        int ans = 0;
        for (int i = 0; i < 26; i++)
            ans += (scount[i] < tcount[i] ? abs(tcount[i] - scount[i]) : 0);
        return ans;
    }
};