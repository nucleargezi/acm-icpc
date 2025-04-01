#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int x, xx, y, yy;
    std::cin >> x >> y >> xx >> yy;
    int n;
    std::cin >> n;
    vector<tuple<int, int, int>> rab(n);
    std::cin >> rab;
    map<pair<int, int>, ll> dis;
    for (meion [r, a, b] : rab) {
        for (; a < b + 1; ++a) {
            dis[{r, a}] = inf<ll>;
        }
    }
    queue<pair<int, int>> q;
    q.emplace_back(x, y);
    dis[{x, y}] = 0;
    while (not q.empty()) {
        meion [x, y] = q.pop();
        for (int dx : {-1, 0, 1}) {
            for (int dy : {-1, 0, 1}) {
                int xx{x + dx}, yy{y + dy};
                dis.contains({xx, yy}) and
                    chmin(dis[{xx, yy}], dis[{x, y}] + 1) and
                    q.emplace_back(xx, yy);
            }
        }
    }
    ll ans = dis[{xx, yy}];
    std::cout << (ans == inf<ll> ? -1 : ans) << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}