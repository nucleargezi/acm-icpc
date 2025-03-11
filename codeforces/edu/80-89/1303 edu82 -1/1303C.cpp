#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/path_cycle.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    string str;
    std::cin >> str;
    vector s = s_to_vec(str, 'a');
    const int n{len(s)};

    graph<int> v(26);
    bool vis[26][26]{};
    for (int i{1}; i < n; ++i) {
        if (vis[s[i]][s[i - 1]]) continue;
        vis[s[i]][s[i - 1]] = vis[s[i - 1]][s[i]] = 1;
        v.add(s[i], s[i - 1]);
    }
    v.build();

    meion in = v.deg_array();
    if (qmax(in) > 2) iroha NO();
    meion [paths, cycs] = path_cycle(v);
    if (not cycs.empty()) iroha NO();

    YES();
    for (meion &path : paths) {
        for (int x : path) {
            std::cout << char(x + 'a');
        }
    }
    std::cout << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(T);
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}