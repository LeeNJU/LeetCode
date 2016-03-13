#include<vector>
#include<algorithm>
#include<limits.h>
#include<numeric>

int copyBooks(std::vector<int>& pages, int k) 
{
	int n = pages.size();
	k = std::min(n, k);
	std::vector<int> sum_from_start(n, 0);
	partial_sum(pages.begin(), pages.end(), sum_from_start.begin());
	std::vector<std::vector<int> > minutes(k + 1, std::vector<int>(n, INT_MAX));
	for (int j = 0; j < n; ++j) 
		minutes[1][j] = sum_from_start[j];
	
	for (int i = 2; i <= k; i++) 
	{
		minutes[i][0] = sum_from_start[1];
		int left = 0, right = 1;
		while (right < n) 
		{
			int curr = sum_from_start[right] - sum_from_start[left];
			minutes[i][right] = std::min(std::max(curr, minutes[i - 1][left]), minutes[i][right]);
			if (left < right && minutes[i - 1][left] < curr) 
				++left;
			else 
			{
				++right;
				if (left > 0) 
					--left;
			}
		}
	}
	return minutes[k][n - 1];
}
