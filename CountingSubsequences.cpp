/*

Given 2 strings,Find the number of times the second string occurs as subsequence in the first ring

eg:
"ABCDCE"
"ABC"

o/p: 2
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

/**********************************************************************************/

//O(n*n) without DP
int numOfSubsequence(string s1, string s2, int i = 0, int j = 0) {


    if ( j >= int(s2.length()) )
        return 1;

    if ( i >= int(s1.length())  )
        return 0;



    int ans = 0;
    for (int k = i; k < int(s1.length()); k++) {
        if (s1[k] == s2[j]) {
            ans += numOfSubsequence(s1, s2, k + 1, j + 1);
        }

    }

    return ans;

}
/***************************TOP DOWN APPROACH****************/

//Simply memoize this for topdown approach
int countSub(string s1, string  s2, int m , int n) {

    if ((m == -1 and n == -1) or n == -1)
        return 1;
    if (m == -1)
        return 0;

    if (s1[m] == s2[n]) {
        return countSub(s1, s2, m - 1, n - 1) + countSub(s1, s2, m - 1, n);
    }

    return countSub(s1, s2, m - 1, n);

}
/*************************BOTTOM UP APPROACH***************************************/
/**
  f(m,n) if (s1[m]==s2[n]) return f(m-1,n-1) + f(m,n-1);
         return f(m-1,n-1);

  */

int countSub2(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<int> > dp(m + 1, vector<int> (n + 1));


    //fill table

    //first column is 1

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n ; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] =  dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];

        }


    }

    return dp[m][n];


}


/*********************************************************************************/
int main() {
    checkjudge();

    string s1, s2;
    cin >> s1 >> s2;

    cout << countSub2(s1, s2);


    return 0;

}
