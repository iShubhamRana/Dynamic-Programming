


int solveWordWrap(vector<int>nums, int k)
{
  
  /*Generate cost matrix*/
	int n = nums.size();
	vector<vector<int> > cost(n, vector<int> (n, 0));

	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = i; j < n; j++) {
			count += nums[j];

			cost[i][j] = (count > k) ? -1 : (k - count) * (k - count);
			count++;
		}
	}

	vector<int> dp(n, INT_MAX);

	int i = n - 1;
	while (i >= 0) {
		int j = n - 1;
		while (j >= i) {
			if (j == n - 1 and cost[i][n - 1] != -1) {
				dp[i] = 0;
			} else {
				if (cost[i][j] != -1) {
					dp[i] = min(dp[i], cost[i][j] + dp[j + 1]);
				}
			}
			j--;
		}
		i--;
	}

	print(dp);

	return dp[0];
}
