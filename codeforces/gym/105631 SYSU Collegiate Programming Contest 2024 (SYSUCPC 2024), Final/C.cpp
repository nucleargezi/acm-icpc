#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    set<tuple<int, ll, int>> se;
    vector<tuple<int, ll, int>> a(n + 1);
    vector pan(n + 1, array<int, 26>{});
    for (int i{}; i < n + 1; ++i) {
        a[i] = {0, 0, i};
        se.emplace(a[i]);
    }
    int rk = 1;
    for (int i{}; i < m; ++i) {
        string s;
        int team;
        char pro;
        string ret;
        std::cin >> s >> team >> pro >> ret;
        pro -= 'A';
        int cost = std::stoi(s.substr(0, 2)) * 60 + std::stoi(s.substr(3, 2));
        if (pan[team][pro] == -1) continue;

        if (ret == "RJ") {
            pan[team][pro] += 20;
            continue;
        }
        meion cp = a[team];
        meion &[x, y, z] = a[team];
        --x;
        y += pan[team][pro] + cost;
        pan[team][pro] = -1;
        if (team) {
            se.erase(cp);
            se.emplace(a[team]);
            rk += a[team] < a[0] and a[0] < cp;
            continue;
        }
        int rkk{rk};
        meion it = se.erase(se.find(cp));
        while (it != se.begin() and a[0] < *std::prev(it)) {
            --it;
            --rk;
        }
        se.emplace(a[0]);
        pro += 'A';
        std::cout << s << ' ' << pro << " #" << rkk << " -> #" << rk << '\n';
    }
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