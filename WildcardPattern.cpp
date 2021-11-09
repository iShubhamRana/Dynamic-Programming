/*
Given an input string (s) and pattern (p),implement wildcard pattern
matching algorithm that finds if wildcard pattern is matched in the input string.

The wildcard pattern can include characters '?' and "*"
'?' matches any single character

'*' matches any sequence of characters(includeing empty spaces.

The matching should  cover the entire input string (not partial).

eg : Text ="baaabab"
Pattern: "**ba**ab"
o/p: true

patterm:"baaa?ab"
o/p true

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


bool patternMatching1(string s1, string s2, int i, int j, vector<vector<int>> &dp) {

    if (i<0 and j >= 0) {
        for (int k = j; k >= 0; k--) {
            if (s2[k] != '*')
                return  false;
        }
        return true;
    }

    if (i >= 0 and j < 0)
        return false;

    if (i < 0 and j < 0)
        return  true;

    if (dp[i][j] != -1)
        return  dp[i][j];

    if (s1[i] == s2[j] or s2[j] == '?')
        return dp[i][j] = patternMatching1(s1, s2, i - 1, j - 1, dp);

    if (s2[j] == '*') {
        return dp[i][j] = patternMatching1(s1, s2, i - 1, j - 1, dp) or patternMatching1(s1, s2, i - 1, j, dp) or patternMatching1(s1, s2, i, j - 1, dp);
    }

    return dp[i][j] = false;

}

bool patternMatching2(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false) );

    //fill first row
    dp[0][0] = true;
    bool flag = true;
    for (int i = 1; i <= n2; i++) {
        if (s2[i - 1] != '*')
            flag = false;
        dp[0][i] = flag;
    }



    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1]  or s2[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s2[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j - 1] or dp[i - 1][j] or dp[i][j - 1];
            }
            else {
                dp[i][j] = false;
            }
        }
    }





    return dp[n1][n2];

}
//O(n^2)
/********************************************************************************************/

int main() {
    checkjudge();

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = int(s1.length()) , n2 = int(s2.length());

    vector<vector<int> > dp(n1 + 1 , vector<int> (n2 + 1, -1));

    cout << patternMatching1(s1, s2 , n1 , n2, dp);
    cout << patternMatching2(s1, s2);

    return 0;

}
