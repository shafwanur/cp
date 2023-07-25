#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>
#include <climits>

using namespace std;

const int N = 1000 + 5;

class Lasso {
private:
    int dist[N][N];
    int dx[4] = {1, 2, -1, -2};
    int dy[4] = {1, 2, -1, -2};

    void init() {
      cout << "OK";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = INT_MAX;
            }
        }
    }

public:
    double lasso(int R, int C, int R1, int C1, int R2, int C2) {
        init();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        for (int i = -2; i < R + 2; i++) {
            for (int j = -2; j < C + 2; j++) {
                if (i >= 0 and i <= R and j >= 0 and j <= C) {
                    continue;
                }
                pair<int, pair<int, int>> u;
                u.first = 0;
                u.second = {i, j};
                q.push(u);
            }
        }
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int cost = t.first;
            pair<int, int> u = t.second;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (abs(dx[i]) == abs(dy[j])) {
                        continue;
                    }
                    int x = u.first + dx[i];
                    int y = u.second + dy[j];
                    if (x >= 0 and x <= R and y >= 0 and y <= C) {
                        if (dist[x][y] > cost + 1) {
                            dist[x][y] = cost + 1;
                            pair<int, pair<int, int>> v;
                            v.first = dist[x][y];
                            v.second = {x, y};
                            q.push(v);
                        }
                    }
                }
            }
        }
        map<int, int> cnt;
        for (int i = R1; i <= R2; i++) {
            for (int j = C1; j <= C2; j++) {
                cnt[dist[i][j]] += 1;
            }
        }
        auto p = *cnt.begin();
        if (p.second <= 2) {
            return static_cast<double>(p.first);
        }
        double ans = p.first / (1.00 * p.second);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Lasso lassoObj;

    int R, C, R1, C1, R2, C2;
    cin >> R >> C >> R1 >> C1 >> R2 >> C2;
    cout << setprecision(20) << lassoObj.lasso(R, C, R1, C1, R2, C2) << '\n';

    return 0;
}
