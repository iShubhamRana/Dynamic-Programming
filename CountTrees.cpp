/*

Count the number of binary searh trees that cna be formed using N nodes, numbered from 1 to N.

eg:
input:
3
4

output:
5
14

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



int countTrees(int n) {

    vector<int>dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {

        int ans = 0;
        for (int j = 1; j <= i; j++) {
            ans = ans + (dp[j - 1] * dp[i - j]);
        }

        dp[i] = ans;

    }

    return dp[n];


}


/*******************************************************************************************/

int main() {

    checkjudge();


    int n;
    cin >> n;

    cout << countTrees(n);

    return 0;

}


