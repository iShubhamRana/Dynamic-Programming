/*

Given an array, a frog has to jump from 1 box to last box. arr[i] represent the height of each box and abs diff
of heights of stones gives cost to jump to that stone. Frog can oly jump from i to i+1 th or i to i+2th stone.
find the min cost to reahc the end stone.


eg:
6
30 10 60 10 60 50

ans: 50

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

int frogJump(vector<int> arr, int n , vector<int>  &dp , int i = 0) {

    if (i == n - 1)
        return 0;

    if (dp[i])
        return dp[i];

    int ans1 = 0, ans2 = INT_MAX;

    ans1 = frogJump(arr, n, dp, i + 1);
    ans1 += abs(arr[i] - arr[i + 1]);

    if (i + 2 < n) {
        ans2 = frogJump(arr, n, dp, i + 2);
        ans2 += abs(arr[i] - arr[i + 2]);
    }

    dp[i] = min(ans1, ans2);
    return dp[i];
}
/******************************************************************************************************/


/********BOTTOM UP APPROACH******************************************************************************/


int frogJump2(vector<int> arr, int n, vector<int> dp) {


    for (int i = 1; i < n; i++) {

        int j = i - 1;
        dp[i] = INT_MAX;
        while (j >= i - 2 and j >= 0) {
            dp[i] = min(abs(arr[i] - arr[j]) + dp[j], dp[i]);
            j--;
        }

    }

    return dp[n - 1];


}

//find min cost to reach till each step and start building soln till n.

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

    cout << frogJump2(arr, n, dp);


}