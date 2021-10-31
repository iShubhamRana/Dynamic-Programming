/*

Given an array of boxes .Box  is represented by 3 integers height,width and depth. Our goal is to
stack up the boxes and maximise the total height of the stack.
You can't rotate any box i.3  change the order of integers in the box.

A box must have strictly smaller width,depth and height than any other box below it.

eg:
Boxes=[
    [2,1,2],
    [3,2,3],
    [2,2,8],
    [2,3,4],
    [2,2,1],
    [4,4,5]]

output:10


    [2,1,2],
    [3,2,3],
    [4,4,5]

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



/*
    we are clueless in the starting of the question and therefore we will sort boxes first according
    to the height because their  has to be condition that lower box should have greater dimensions than top box
    Then we will assume the boxes to be at lowermost pos and then do the stacking for max height

*/

bool compare(vector<int>a, vector<int> b) {
    return a[2] < b[2];
}

bool isvalid(vector<int>a , vector<int> b) {
    if (a[0] < b[0] and a[1] < b[1]  and a[2] < b[2])
        return true;
    else
        return false;
}

int stackboxes(vector<vector<int>> v, int n) {

    sort(v.begin(), v.end(), compare);


    vector<int> dp(n);
    for (int i = 0; i < n; i++) {

        int height = 0;

        for (int j = 0; j < i; j++) {
            if (isvalid(v[j], v[i])) {
                height = max(height, dp[j]);
            }
        }

        dp[i] = height + v[i][2];

    }

    int ans = 0;
    for (auto x : dp) {
        ans = max(ans, x);
    }
    return ans;

}
//Time: O(n*n)
//Space:O(n)
/*************************************************************************************/

int main() {

    checkjudge();


    int n;
    cin >> n;
    vector<vector<int> > boxes(n);
    int i = 0;
    while (i < n) {

        for (int j = 0; j < 3; j++) {
            int x; cin >> x;
            boxes[i].push_back(x);
        }
        i++;

    }

    cout << stackboxes(boxes, n);

    return 0;

}


