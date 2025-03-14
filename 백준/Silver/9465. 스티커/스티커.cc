#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int buf[2][MAXN + 1] = { 0, };
int dp[2][MAXN + 1] = { 0, };

int bottomUp(int n) {
    // 윗줄 입력
    for (int i = 0; i < n; i++) 
        cin >> buf[0][i];
    // 아랫줄 입력
    for (int i = 0; i < n; i++)
        cin >> buf[1][i];

    // 정답배열 dp 생성
    dp[0][0] = buf[0][0];
    dp[1][0] = buf[1][0];
    if (n > 1) {
        dp[0][1] = buf[0][1] + dp[1][0];
        dp[1][1] = buf[1][1] + dp[0][0];
    }

    for (int i = 2; i < n; i++) {
        dp[0][i] = buf[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = buf[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }

    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << bottomUp(n) << '\n';
    }
    return 0;
}
