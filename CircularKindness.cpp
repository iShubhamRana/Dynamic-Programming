/*

If n members are sitting in a circular table and array[i] indicates the kindness of each member. Make a team of
max kindness such that no two members are adjacent

eg: 3 7 2 5 9 1
    ans: 16

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


int maxProsp(vector<int> arr , int n, vector<pair<int, int> > &dp, int i = 0, bool first = false) {

    if (i >= n)
        return 0;

    if (i == n - 1) {
        if (first == false)
            return arr[i];
        else
            return 0;
    }

    //dp will store pair of values if 1 was included or 1 was not included

    if (first == true and dp[i].first != 0)
        return dp[i].first;
    if (first == false and dp[i].second != 0)
        return dp[i].second;


    int ans1 = 0, ans2 = 0;

    //if included
    if (i != 0)
        ans1 = arr[i] + maxProsp(arr, n, dp, i + 2, false);
    else
        ans1 = arr[i] + maxProsp(arr, n, dp, i + 2, true);



    //if not included
    ans2 += maxProsp(arr, n , dp, i + 1, false);

    if (first) {
        dp[i].first = max(ans1, ans2);
    }
    else
        dp[i].second = max(ans1, ans2);

    return max(ans1, ans2);



}


int main() {
    checkjudge();
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<pair<int, int> > dp(n);
    cout << maxProsp(arr, n, dp);


}