/*
Since in 0-1 knapsack 2 rows are only used at a time , we can reduce the space compexity to O(N) . For that we have to fill the row form the right side as the row
on the left side represents the previous row and the row on the right side represents the current row we are filling.
Time: O(n*n)
Space: O(n)
*/


int knapSack(int W, int wt[] , int val[] , int n) {
	vector<int> dp(n + 1, 0);
	for (int i = 1; i < n + 1; i++) {
		for (int w = W; w >= 0; w--) {

			if (wt[i - 1] <= w)
				// finding the maximum value
				dp[w] = max(dp[w],
				            dp[w - wt[i - 1]] + val[i - 1]);
		}
	}
	return dp[W];
}
