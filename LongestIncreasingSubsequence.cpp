/*

Given an array subsequence, find the length of longest subsequence of such that all elements of the subsequence
are sorted in increasing order

input: 50 4 10 8 30 100
output: 4
{4,8,30,100}

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




/***************Recursive soln***********************************************************************/
int longestincreasing(vector<int> arr, int n,  int i = 0, int prev = INT_MIN) {

    if (i >= n) {
        return 0;
    }

    //if included
    if (arr[i] > prev) {
        int ans1 = 1 + longestincreasing(arr, n, i + 1, arr[i]);
        int ans2 = longestincreasing(arr, n, i + 1, prev);
        return max(ans1, ans2);
    }
    else {
        return longestincreasing(arr, n, prev);
    }

}

/******************************************************************************************************/


/********BOTTOM UP APPROACH******************************************************************************/

/*we can store the length of subsequence till now and its last element can be acceseed through array and for all
all prev subsequences we can find the subsequence after which we cna fit our element and has the largest length among them


The relation here is that:

for index i:

dp[i]=1 + max(dp[j]);

subj to:
0<= j <i and arr[j]<arr[i]


*/



int dplongestincreasign(vector<int> arr, int n) {
    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {

        int ans = 0;

        for (int j = 0; j < i; j++) {

            if (arr[j] < arr[i]) {
                ans = max(ans, dp[j]);
            }

        }

        dp[i] = 1 + ans;
    }


    //now find the longest length subsequence
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    return ans;
}


//time: O(n*n)
//space: O(n)


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

    cout << longestincreasing(arr, n);


}