class Solution {
public:
	vector<int> give(vector<int> &nums , int k) {
		vector<int> v;
		int i = 0;
		while (k > 0) {
			if (k & 1) {
				v.push_back(nums[i]);
			}
			k = k >> 1;
			i++;
		}
		return v;
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		int sub = 1 << n;
		sub = sub - 1;
		vector<vector<int>> res;
		for (int i = 0; i <= sub; i++) {
			res.push_back(give(nums, i));
		}
		return res;
	}
};