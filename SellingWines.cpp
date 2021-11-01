/*

There is a collection of N wines placed linearly in shelf ,the price of the ith wine is pi.
Since wines get better every year, suppose today is the year 1,on the year y the price of the i the wine be y*pi
t.e  y times the value that current year.
You want to sell all the wines you have and sell exactly one wine per year.
You can sell either the leftmost or the rightmost wine without reordering.
Find the max profit.

eg: [2,3,5,1,4]

output= 50

Explaination:
2*1 + 4*2 + 1*3 + 3*4 + 5*5 = 50




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

/***************************** Top Down Approach*****************************************************/


int sellingWines(vector<int> arr, vector<vector<int> > dp, int i, int j) {

    if (i == j) {
        return arr.size() * arr[i];
    }

    if (dp[i][j] != 0)
        return dp[i][j];

    int year = int(arr.size()) - (j - i );

    int ans1 = year * arr[i];
    int ans2 = year * arr[j];

    ans1 += sellingWines(arr, dp, i + 1, j);
    ans2 +=  sellingWines(arr, dp, i, j - 1);

    return dp[i][j] = max(ans1, ans2);


}

/******************************************************************************************************/


/**************************BottomUp Approach*******************************************************************/

/* EXAMPLE OF DIAGONAL DP*/

int sellingWines2(vector<int> arr) {

    int n = arr.size();

    vector< vector<int>  > dp(n + 1, vector<int> (n + 1, 0));

    //we have taken n+1 dp to avoid corner check as  i+1 an j-1 will overflow in corners

    for (int i = n - 1; i >= 0 ; i--) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                int year = n - (j - i);
                int left = year * arr[i] + dp[i + 1][j];
                int right = year * arr[j] + dp[i][j - 1];

                dp[i][j] = max(left, right);
            }
        }
    }

    return dp[0][n - 1];
}


/*************************************************************************************************************/


int main() {

    checkjudge();

    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector< vector<int>  > dp(n, vector<int> (n, 0));

    cout << sellingWines2(arr);

    return 0;

}


