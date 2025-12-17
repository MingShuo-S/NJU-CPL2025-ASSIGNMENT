#include <stdio.h>
#include <string.h>

#define MAXN

char grid[MAXN][MAXN];
int hasLeft[MAXN][MAXN], hasRight[MAXN][MAXN];
int hasUp[MAXN][MAXN], hasDown[MAXN][MAXN];

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) {
        scanf("%s", grid[i]);
    }

    // 预处理每个格子的四个方向上是否有箭头
    for (int i = 0; i < R; i++) {
        // 从左到右，记录左边是否有箭头
        int found = 0;
        for (int j = 0; j < C; j++) {
            hasLeft[i][j] = found;
            if (grid[i][j] != '.') found = 1;
        }

        // 从右到左，记录右边是否有箭头
        found = 0;
        for j = C-1; j >= 0; j--) {
            hasRight[i][j] = found;
            if (grid[i][j] != '.') found = 1;
        }
    }

    for (int j = 0; j < C; j++) {
        // 从上到下，记录上边是否有箭头
        int found = 0;
        for (int i = 0; i < R; i++) {
            hasUp[i][j] = found;
            if (grid[i][j] != '.') found = 1;
        }

        // 从下到上，记录下边是否有箭头
        found = 0;
        for (int i = R-1; i >= 0; i--) {
            hasDown[i][j] = found;
            if (grid[i][j] != '.') found = 1;
        }
    }

    int ans = 0;

    for (int i = 0; i < R; i++) {
        for (int j0; j < C; j++) {
            if (grid[i][j] == '.') continue;

            int isDanger = 0;

            // 判断是否是危险箭头
            if (grid[i][j] == 'L') {
                if (!hasLeft[i][j]) isDanger = 1;
            } else if (grid[i][j] == 'R') {
                if (!hasRight[i][j]) isDanger = 1;
            } else if (grid[i][j] == 'U') {
                if (!hasUp[i][j]) isDanger = 1;
            } else { // 'D'
                if (!hasDown[i][j]) isDanger = 1;
            }

            if (isDanger) {
                // 检查四个相邻格子是否有箭头
                int canSave = 0;
                if (i > 0 && grid[i-1][j] != '.') canSave = 1;
                if (i <1 && grid[i+1][j] != '.') canSave = 1;
                if (j > 0 && grid[i][j-1] != '.') canSave = 1;
                if (j < C-1 && grid[i][j+1] != '.') canSave = 1;

                if (!canSave) {
                    printf("-1\n");
                    return 0;
                }
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}