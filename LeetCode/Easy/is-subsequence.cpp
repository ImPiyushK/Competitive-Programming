class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int k = 0;
        if (s.length() == 0)
            return true;
        for (int i = 0 ; i < t.length() ; i++)
        {
            if (t[i] == s[k])
                k++;

            if (k == s.length())
                return true;
        }
        return false;

    }
};