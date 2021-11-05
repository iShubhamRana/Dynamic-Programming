/*

EDIT DISTANCE:

Given 2 strings str 1 and str2 and below operations that can be performed on sttr1. Find minimum number of edits
(operations) required to convert 'str1' into 'str2'.

Insert,
Remove,
Replace
All the operations are of equal cost.

eg: str1="geek" str2="gesek"
output:1

str2="cat" str2="cut"
output:1

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

/******************************Recursive ~> Top down ****************************************/

int editdistance(string s1, string s2, vector<vector<int>> &dp, size_t i = 0, size_t j = 0) {

    if (i == s1.length() and j == s2.length())
        return 0;
    if (i >= s1.length() or j >= s2.length()) {
        if (i < j) return j - i + 1;
        else return i - j + 1;
    }

    if (dp[i][j] != 0)
        return dp[i][j];
    if (s1[i] == s2[j])
        return editdistance(s1, s2, dp, i + 1, j + 1);

    int insert, remove, replace;
    //insert
    insert = 1 + editdistance(s1, s2, dp, i, j + 1);
    //remove
    remove = 1 + editdistance(s1, s2, dp, i + 1 , j);
    //replace
    replace = 1 + editdistance(s1, s2, dp, i + 1, j + 1);

    return dp[i][j] = min({insert, remove, replace});
}



/**********************************************************************************************/

/*******************BOTTOM UP APPROACH********************************************************/

/*

Recurrence relation:

let n1 be index in s1 and n2 be index in s2;

f(n1,n2)=   s1[n-1]==s2[n2-1]      f(n1-1,n2-1)

            else                   1 + min(f(n1-1,n2) , f(n1-1,n2-1) , f(n1,n2-1))

*/

int editdistance2(string s1, string s2) {

    size_t n1 = s1.length();
    size_t n2 = s2.length();

    vector< vector<int>  > dp(n1 + 1, vector<int> (n2 + 1));

    for (size_t i = 0; i < n1; i++) {
        dp[i][0] = i;
    }
    for (size_t i = 0; i < n2; i++) {
        dp[0][i] = i;
    }


    for (size_t i = 1; i <= n1; i++) {

        for (size_t j = 1; j <= n2; j++) {
            int ans = 0;
            if (s1[i - 1] == s2[j - 1]) {
                ans = dp[i - 1][j - 1];
            }
            else {
                ans = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
            dp[i][j] = ans;
        }
    }

    return dp[n1][n2];

}


/**********************************************************************************************/

int main() {
    checkjudge();

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int> > dp(s1.length() + 1, vector<int> (s2.length() + 1));

    cout << editdistance2(s1, s2);

    return 0;

}
