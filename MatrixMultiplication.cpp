/*
Given a sequence of matrices, find the most efficient way to multiply these
 matrices together. The problem is not actually to perform the multiplications,
  but merely to decide in which order to perform the multiplications.
. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix.
Then,
(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.


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

/*******************recursivE**************************/

int matrixmultiplication1(vector<int> v, size_t i, size_t j) {

    if (i == j)
        return 0;

    long ans = INT_MAX;
    for (size_t k = i; k < j; k++) {
        int temp = matrixmultiplication1(v, i, k) + matrixmultiplication1(v, k + 1, j) + v[i - 1] * v[k] * v[j];

        if (temp < ans)
            ans = temp;
    }


    return ans;

}





/******************************Recursive ~> Top down ****************************************/


int matrixmultiplication2(vector<int> v, size_t i, size_t j, vector<vector<int> > &dp) {

    if (i == j)
        return 0;

    if (dp[i][j] != 0)
        return dp[i][j];

    int ans = INT_MAX;

    for (size_t k = i; k < j; k++) {
        int temp = matrixmultiplication1(v, i, k) + matrixmultiplication1(v, k + 1, j) + v[i - 1] * v[k] * v[j];

        if (temp < ans)
            ans = temp;
    }


    return dp[i][j] = ans;
}




/**********************************************************************************************/

/*******************BOTTOM UP APPROACH********************************************************/

int matrixmultiplication3(vector<int > v) {

    size_t  l = v.size();

    vector<vector<int > > dp(l + 1,  vector<int > (l + 1));

    for (size_t i = l - 1  ; i >= 1 ; i--) {

        for (size_t j = i + 1; j < l ; j++) {


            dp[i][j] = INT_MAX;
            for (size_t k = i ; k < j ; k++) {
                int temp = dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j];
                if (temp < dp[i][j])
                    dp[i][j] = temp;
            }
        }
    }

    return dp[1][l - 1];
}

/**********************************************************************************************/

int main() {
    checkjudge();

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int> > dp(n , vector<int> (n));
    cout << matrixmultiplication3(v);


    return 0;

}
