#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, k = 0, r = 0 , c = 0;
	cin >> t;
	set<int> str;
	set<int> stc;
	while (t--)
	{
		cin >> n;
		int ar[n][n];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> ar[i][j];

				if (i == j)
					k += ar[i][j];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				str.insert(ar[i][j]);
				stc.insert(ar[j][i]);
			}
			if (str.size() != n)
				r++;
			if (stc.size() != n)
				c++;
			str.clear();
			stc.clear();
		}

		cout << k << " " << r << " " << c << endl;
		k = r = c = 0;
	}
}