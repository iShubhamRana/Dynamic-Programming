/*

Knapsack problem

Given weights and prices of n items, we need to put a subset of items in a bag of capacity W such that
we get the max total value in the bag .

input: N=4 , W=11

wts=[2,7,3,4]
prices={5,20,20,10}

output:
40

*/

#include<bits/stdc++.h>
#define ll long int
#define pb push_back


using namespace std;

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt" , "w" , stdout);
#endif
}

/******************************Recursive ~> Top down *********************************/

int knapsack1(vector<int> weights, vector<int> prices, int n, int w , vector<vector<int>>&dp) {

    if (n == 0 or w == 0) {
        return 0;
    }

    if (dp[n][w] != -1)
        return dp[n][w];

    int inc = 0, exc = 0;
    if (weights[n - 1] <= w) {
        inc = prices[n - 1] + knapsack1(weights, prices, n - 1, w - weights[n - 1], dp);
    }
    exc = knapsack1(weights, prices, n - 1, w, dp);


    return dp[n][w] = max(inc, exc);
}


/**************************BOTTOM UP APPROACH****************************************************/

//Make table for n,w as case. with n+1 words and w+1 cols

int knapsack2(vector<int> weights, vector<int>prices, int N , int W) {

    vector<vector<int>> dp(N + 1, vector<int> (W + 1));


    for (int n = 1; n <= N; n++) {
        for (int w = 1; w <= W ; w++) {
            int inc = 0, exc = 0;

            if (weights[n - 1] <= w) {
                inc = prices[n - 1] + dp[n - 1][w - weights[n - 1]];
            }
            exc = dp[n - 1][w];

            dp[n][w] = max(inc, exc);
        }
    }



    return dp[N][W];


}





/************************************************************************************************/
int main() {
    checkjudge();

    int n ; int w;
    cin >> n >> w;

    vector<int> prices(n), weights(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<vector<int> > dp(n + 1, vector<int> (w + 1, -1));

    cout << knapsack1(weights, prices, n, w, dp);
    cout << knapsack2(weights, prices, n, w);

    return 0;

}

