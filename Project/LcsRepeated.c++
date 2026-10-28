
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

// Triple repeated subsequence
pair<int, string> longestTripleRepeatedSubsequence(string s) {
    int n = s.length();

    // Create a 3D DP array
    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(n + 1, vector<int>(n + 1, 0))
    );

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {

                if (s[i - 1] == s[j - 1] &&
                    s[j - 1] == s[k - 1] &&
                    i != j && j != k && i != k) {

                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max({
                        dp[i - 1][j][k],
                        dp[i][j - 1][k],
                        dp[i][j][k - 1]
                    });
                }
            }
        }
    }

    // Reconstruct the subsequence
    int i = n, j = n, k = n;
    string res = "";

    while (i > 0 && j > 0 && k > 0) {
        if (s[i - 1] == s[j - 1] &&
            s[j - 1] == s[k - 1] &&
            i != j && j != k && i != k &&
            dp[i][j][k] == dp[i - 1][j - 1][k - 1] + 1) {

            res += s[i - 1];
            i--;
            j--;
            k--;
        }
        else if (dp[i][j][k] == dp[i - 1][j][k]) {
            i--;
        }
        else if (dp[i][j][k] == dp[i][j - 1][k]) {
            j--;
        }
        else {
            k--;
        }
    }

    reverse(res.begin(), res.end());

    return {dp[n][n][n], res};
}

int main() {
    string str;

    cout << "Enter the string: ";
    cin >> str;

    auto result = longestTripleRepeatedSubsequence(str);

    cout << "Length of Longest Triple Repeated Subsequence: "
         << result.first << endl;

    cout << "Longest Triple Repeated Subsequence: "
         << result.second << endl;

    return 0;
}
