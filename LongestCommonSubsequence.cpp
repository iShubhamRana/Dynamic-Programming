/*

Given 2 strings find the longest common subequence

eg:
string 1= "ABCD"
string 2= "ABEDG"

output: 3

ABD  //you can also try printing the subsequence also

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

/**********************TOP DOWN APPROACH*********************************************************/

int longestSubsequence(string s1, string s2, vector <vector<int>  > &dp  , int i = 0, int j = 0) {


    if (i == int(s1.length()) or j == int(s2.length()))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return  dp[i][j] = 1 + longestSubsequence(s1, s2, dp, i + 1, j + 1);

    int op1 = longestSubsequence(s1, s2, dp, i + 1, j);
    int op2 = longestSubsequence(s1, s2, dp, i, j + 1);
    return dp[i][j] = max(op1, op2);

}





/***********************************************************************************************/

/********************BOTTOM UP APPROACH******************************************************************/

/*
we will make a 2-d dp table ansstore results what if we take n chars from string 1 and m chars from sting 2 and keep
building our soln till the end.

*/

int longestSubsequence2(string s1, string s2) {

    int l1 = s1.length();
    int l2 = s2.length();

    vector< vector<int> > dp(l1 + 1, vector<int> (l2 + 1, 0) );

    for (int i = 1; i <= l1; i++) {

        for (int j = 1; j <= l2; j++) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }


        }

    }

    return dp[l1][l2];
}





/******************************************************************************************************/
int main() {

    checkjudge();


    string s1, s2;
    cin >> s1 >> s2;

    int l1 = s1.length();
    int l2 = s2.length();

    vector<vector<int> > dp(l1, vector<int> (l2, -1));




    cout << longestSubsequence2(s1, s2);



    return 0;

}


