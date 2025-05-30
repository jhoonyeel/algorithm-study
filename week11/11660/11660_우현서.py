import sys

# dp[i][i] : 1, 1부터 i, i까지 합 -> dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1][y1]
# dp[i-1][i] + dp[i][i-1] - dp[i-1][i-1] + board[i][i]
n, m = map(int, sys.stdin.readline().split())
board = []
for _ in range(n):
    board.append(list(map(int, sys.stdin.readline().split())))
# print(board)
dp = [[0] * (n+1) for _ in range(n+1) ]
for i in range(1, n+1):
    for j in range(1, n+1):
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + board[i-1][j-1]
# for d in dp:
#     print(d)
# print(dp)
for _ in range(m):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    # print(dp[x2][y2])
    # print(dp[x1][y1])
    print(dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1])
