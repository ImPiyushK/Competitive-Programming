class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {

        int x = 0, y = 0;
        int xo = nums[0], set;
        for (int i = 1; i < nums.size(); i++)
            xo ^= nums[i];

        set = xo & ~(xo - 1);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & set)
                x = x ^ nums[i];
            else
                y = y ^ nums[i];
        }
        vector<int> v;
        v.push_back(x);
        v.push_back(y);

        return v;
    }
};