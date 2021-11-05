/*
Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.


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


/**************************************RECURSION*************************************************/

struct mix {
    long long smoke;
    long long  mixture;
};

mix helper1(vector<int> v , size_t i, size_t j) {

    if (i == j) {
        mix temp;
        temp.mixture = v[i];
        temp.smoke = 0;
        return  temp;

    }

    mix ans;
    ans.mixture = 0;
    ans.smoke = INT_MAX;

    for (size_t k = i; k < j; k++) {
        mix m1 = helper1(v, i, k);
        mix m2 = helper1(v, k + 1, j);

        long long smoke = m1.smoke + m2.smoke + m1.mixture * m2.mixture;
        long long mixture = (m1.mixture + m2.mixture) % 100;

        if (smoke < ans.smoke) {
            ans.mixture = mixture;
            ans.smoke = smoke;
        }

    }

    return ans;

}

long long minimumsmoke1(vector<int> v) {
    auto x = helper1(v, 0, v.size() - 1);
    return x.smoke;
}


/*******************************TOP DOWN*************************************************************/

mix helper2(vector<int> v, size_t i, size_t j, vector<vector<mix> > &dp) {

    if (i == j) {
        mix temp;
        temp.mixture = v[i];
        temp.smoke = 0;
        return  temp;

    }

    if (dp[i][j].smoke != -1  and dp[i][j].mixture != -1)
        return dp[i][j];


    mix ans;
    ans.mixture = 0;
    ans.smoke = INT_MAX;

    for (size_t k = i; k < j; k++) {
        mix m1 = helper2(v, i, k, dp);
        mix m2 = helper2(v, k + 1, j, dp);

        long long smoke = m1.smoke + m2.smoke + m1.mixture * m2.mixture;
        long long mixture = (m1.mixture + m2.mixture) % 100;

        if (smoke < ans.smoke) {
            ans.mixture = mixture;
            ans.smoke = smoke;
        }

    }

    return dp[i][j] = ans;

}

long long minimumsmoke2(vector<int> v) {
    mix temp;
    temp.smoke = -1;
    temp.mixture = -1;
    vector<vector<mix> > dp(v.size() , vector<mix > (v.size(), temp));
    auto x = helper2(v, 0, v.size() - 1, dp);
    return x.smoke;
}

/******************************BOTTOM UP APPROACH************************************************************/



long long minimumsmoke3(vector<int> v) {

    mix temp;
    temp.smoke = 0;
    temp.mixture = 0;
    size_t n = v.size();

    vector<vector<mix>> dp(n, vector<mix> (n , temp));

    for (size_t i = 0; i < n; i++) {
        temp.mixture = v[i];
        dp[i][i] = temp;
    }

    //beware of using size_t in >=0  conditions as size_t will never go below 0 and cause infinite loop


    for (int i = n - 2; i >= 0; i--) {

        for (size_t j = i + 1 ; j < n; j++) {

            dp[i][j].smoke = INT_MAX;

            for (size_t  k = i; k < j; k++) {
                long long smoke = dp[i][k].smoke + dp[k + 1][j].smoke + dp[i][k].mixture * dp[k + 1][j].mixture ;

                if (smoke < dp[i][j].smoke) {
                    dp[i][j].smoke = smoke;
                    dp[i][j].mixture = (dp[i][k].mixture + dp[k + 1][j].mixture) % 100;
                }

            }

        }
    }

    return dp[0][n - 1].smoke;

}






/***********************************************************************************************************/

int main() {
    checkjudge();

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int> > dp(n , vector<int> (n));
    cout << minimumsmoke3(v);


    return 0;

}