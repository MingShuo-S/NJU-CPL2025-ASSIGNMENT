//来自于同学
#include <stdio.h>
#include <stdbool.h>

#define N 15

const int dx[] = {1, 0, 1, -1};
const int dy[] = {0, 1, 1, 1};

int T, x, n;
int a[N][N];

bool check(int nx, int ny, int d, int q) {
    for (int i = 0; i < x; i++) {
        if (nx < 1 || nx > n || ny < 1 || ny > n || a[nx][ny] != q) {
            return false;
        }
        nx += dx[d], ny += dy[d];
    }
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    bool ok[5] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int q = 1; q <= 4; q++) {
                bool flag = false;
                for (int d = 0; d < 4; d++) {
                    flag |= check(i, j, d, q);
                }
                if (flag) {
                    ok[q] = true;
                }
            }
        }
    }

    int cnt = ok[1] + ok[2] + ok[4];
    if (cnt == 0 || cnt > 1) {
        printf("draw\n");
        return;
    }
    for (int i = 1; i <= 4; i++) {
        if (ok[i]) {
            printf("%d\n", i);
        }
    }
}

int main() {
    scanf("%d %d", &T, &x);

    while (T--) {
        solve();
    }

    return 0;
}
