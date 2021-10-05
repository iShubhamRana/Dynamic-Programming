/*

Q. Given n coins select min coins to reach target value

eg: 1 3 7 10
sum: 15

ouput: 3

explaination: select 7 7 1

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

/*************************** Brute force**********************************************************/
long coinchange(vector<int> arr, int k) {

    if (k == 0)
        return 0;
    if (k < 0)
        return INT_MAX;

    long ans = LONG_MAX;

    for (size_t i = 0; i < arr.size(); i++) {
        long temp = 1 + coinchange(arr, k - arr[i]);
        if (temp  < ans)
            ans = temp;
    }

    return ans;

}

//Time: O(n^n)
//Space:O(k)
/**********************************************************************************************/

/*
    It may happen that we select on element and in next case another element . No matter which two we select
    at the end of selection of two . we will end up in same problem
    eg:1 + 4 :  find(sum-5 ) in arry
       4 + 1 :  find(sum-5)  in array

       *** overlapping subproblem

*/


/* Top down using memoization*/
int dp[100000] = {0};
int topcoinchange(vector<int> arr, int k) {
    if (k == 0)
        return 0;

    if (dp[k] != 0)
        return dp[k];
    int ans = INT_MAX;

    for (auto x : arr) {
        if (k - x >= 0) {
            dp[k - x] = coinchange(arr, k - x);
            int temp = 1 + dp[k - x];
            if (temp < ans)
                ans = temp;
        }
    }

    return ans;

}

//Time: O(n*k)
//Space: O(n)

/*Bottom up approach*/

/*
    we can make a dp array to store min coins for all sums till k and start from 1 to build soln till k

*/

int bottomcoinchange(vector<int> arr , int k) {
    int dp[k + 1] = {0};

    for (int i = 1; i < k + 1; i++) {

        int mincoins = INT_MAX;
        for (auto x : arr) {

            if (i - x >= 0) {
                mincoins = min(mincoins, dp[i - x]);
            }
        }
        dp[i] = 1 + mincoins;
    }

    return dp[k ];
}

//Time: O(k * n)
//Space: O(k)

/***********************************************************************************************/
int main() {
    checkjudge();

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    cout << bottomcoinchange(arr, sum);

    return 0;
}