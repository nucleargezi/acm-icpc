#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/acam.hpp"

void before() {}

// #define tests

NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<string> s(n);
    std::cin >> s;
    AC ac;
    meion pos = ac.add(s);
    ac.work();

    string t;
    std::cin >> t;
    meion v = ac.get_graph();
    vector<int> ans(len(ac));
    for (int p{}; char c : t) {
        p = ac[p][c - 'a'];
        ++ans[p];
    }

    meion dfs = [&](meion &dfs, int n) -> void {
        for (meion [f, i, _, __] : v[n]) {
            dfs(dfs, i);
            ans[n] += ans[i];
        }
    };
    dfs(dfs, 0);
    for (int x : pos) {
        std::cout << ans[x] << '\n';
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