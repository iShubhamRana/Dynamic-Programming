/*

Given a string s your task is to partition s in such a way that every sustring of the partition is a
palindrome.
return minimum cuts needed
eg:

str="geek"  o/p:2

str ="aaaa"o/p:0

str = "abcde" o/p: 4

str = "abbac" o/p:1


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


bool ispalindrome(string s, int l, int k) {
    int i = l;
    int j = k;

    bool flag = true;
    while (i <= j) {
        if (s[i] != s[j]) {
            flag = false;
            break;
        }
        i++;
        j--;
    }

    return flag;

}

/******************************Recursive ~> Top down *********************************/
int partitionstring(string s, int i, int j, vector< vector<int> > &dp) {

    if (dp[i][j] != -1)
        return  dp[i][j];

    if (ispalindrome(s, i, j) or i == j) {
        return dp[i][j] = 0;
    }


    int ans = INT_MAX;

    for (int k = i; k < j; k++) {
        int temp = 1 + partitionstring(s, i, k, dp) + partitionstring(s, k + 1, j, dp);
        ans = min(ans, temp);
    }

    return dp[i][j] = ans;

}

//O(n^3)


/*******************BOTTOM UP APPROACH*****************************************************************************/

//we will use 2 arrays one to store min cuts and other to store isstring is palindrome

int partitionstring2(string s) {
    int n = int(s.length());
    int c[n][n];
    int p[n][n];

    for (int i = 0; i < n; i++) {
        p[i][i] = true;
        c[i][i] = 0;
    }

    //check if palindrome


    for (int i = n - 1; i >= 0; i--) {

        for (int j = i + 1; j < n; j++) {
            if (j - i + 1 == 2)
                p[i][j] = (s[i] == s[j]);
            else
                p[i][j] = (s[i] == s[j]) and (p[i + 1][j - 1]);


            if (p[i][j] == true)
                c[i][j] = 0;

            else {
                c[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    c[i][j] = min(c[i][j], c[i][k] + c[k + 1][j] + 1);
                }

            }

        }

    }
    return c[0][n - 1];
}

//O(n^3)
/********************************************************************************************/



/**********************Optimised solution******************************/
//the cuts will be minimum only if we choose palindromic strings . so check if there are prefix or suffix whichever you want as palindromic


/*

For the given string check all the palindroic prefix and check cuts required if we tak that out. FInd the min using this
*/

int optimalpartition(string s) {
    int l = int(s.length());
    bool palindrome[l][l] ;

    int cut[l] ;
    memset(palindrome, false, sizeof(palindrome));

    for (int i = 0; i < l; i++) {
        int mincut = INT_MAX;

        for (int j = 0; j <= i; j++) {

            if (s[i] == s[j] and (i - j < 2 or palindrome[j + 1][i - 1] )) {
                palindrome[j][i] = true;
                mincut = min(mincut , j == 0 ? 0 : cut[j - 1] + 1);
            }
        }

        cut[i] = mincut;

    }


    return cut[l - 1];

}

//O(n^2)
/********************************************************************/

int main() {
    checkjudge();

    string s;
    cin >> s;
    int l = int(s.length());

    vector<vector<int> > dp(l, vector<int>(l, -1));

    cout << optimalpartition(s);

    return 0;

}


