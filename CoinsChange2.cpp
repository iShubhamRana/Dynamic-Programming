/*

Coin Change 2

Give an value N and an integer vector COINS representing coins of different denominations.Considering you have
infinte supply of each coin, Find the total number of combination of these coins that make a sum of N

eg:
4
1 2 3

output: 4

{1,1,1,1}, {1,1,2},{1,3},{2,2}

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

//if we choose 1 from all every time ,we will get repeated answers .therefore we will choose the elements which are above that index

long long findCombinations(int n, vector<int> coins, vector<vector<int> > &dp, size_t r = 0) {

    if (n < 0 or  r >= coins.size())
        return 0;
    if (n == 0)
        return 1;

    long long ans = 0;

    for (size_t i = r; i < coins.size(); i++)
    {
        ans = ans + findCombinations(n - coins[i], coins, dp, i);
    }

    return dp[r][n] = ans;

}


/*******************BOTTOM UP APPROACH*****************************************************************************/

/*

LOGIC:
if n is the index at which we are now and s be the sum we are looking for,then

recurrence relation:

f(n,s)= f(n-1,s) + f(n, s-arr[n]);

2 cases:
1. If  the sum was already completed in past then we will simply add it to the new reult we are forming.
2. Second case in this,we will include the current index also, means if this element was included earlier also then we need to find
    reqSum - current value. This way we can cover cases where same element repeatedly adds to the target sum alsoo.
*/

long long findCombinations2(int sum, vector<int> arr) {

    int n = arr.size();

    vector<vector<long long> > dp(n + 1, vector<long long> (sum + 1));

    //first colum will be 1
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum ; j++) {
            long long ans = 0;
            ans += dp[i - 1][j];
            if (j - arr[i - 1] >= 0)
                ans += dp[i][j - arr[i - 1]];
            dp[i][j] = ans;
        }
    }

    return dp[n][sum];

}


int main() {
    checkjudge();

    int n; int sum;
    cin >> n >> sum;

    vector<int> arr;

    while (n--) {
        int x; cin >> x;
        arr.push_back(x);
    }

    vector<vector<int> > dp(arr.size() , vector<int> (sum + 1));

    cout << findCombinations2(sum, arr);

    return 0;

}


