/*

Given an array, find the max sum you can generate by picking elements subject to no two elements should be adjacent.

eg: 6 10 12 7 9 14

ans: 32

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



/***************TOP DOWN APPROACH***********************************************************************/

int adjacentSum(vector<int> arr, int n, vector<int> &dp , int i = 0) {

    if (i >= n)
        return 0;

    if (i == n - 1)
        return arr[i];

    if (dp[i])
        return dp[i];

    int ans1 = 0, ans2 = 0;
    //if included
    ans1 = adjacentSum(arr, n, dp, i + 2);
    ans1 += arr[i];

    //if not included
    ans2 = adjacentSum(arr, n, dp, i + 1);

    return dp[i] = max(ans1, ans2);

}
/******************************************************************************************************/


/********BOTTOM UP APPROACH******************************************************************************/
int adjacentSum2(vector<int> arr, int n) {

    if (n == 1) return arr[0];

    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }
    return dp[n - 1];
}




/********************************************************************************************************/

int main() {
    checkjudge();
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(n);

    cout << adjacentSum2(arr, n);


}