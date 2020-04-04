class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        set<int> seen;
        for (int num : nums)
        {
            if (seen.count(num) == 1)
            {
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};