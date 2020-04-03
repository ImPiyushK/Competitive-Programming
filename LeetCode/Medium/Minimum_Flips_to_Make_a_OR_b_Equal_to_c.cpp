class Solution {
public:
	int minFlips(int a, int b, int c) {
		return __builtin_popcountll(c ^= a | b) + __builtin_popcountll(a & b & c);
	}
};