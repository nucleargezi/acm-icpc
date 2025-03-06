#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    graph<int, true> v(n);
    v.read_graph(m);
    vector in = v.deg_array_inout().first;
    
    queue<int> q;
    for (int i{}; i < n; ++i) {
        if (not in[i]) q.emplace_back(i);
    }
    int cnt{};
    while (not q.empty()) {
        int n = q.front();
        q.pop();
        ++cnt;
        for (meion [_, t, __, ___] : v[n]) {
            if (not --in[t]) {
                q.emplace_back(t);
            }
        }
    }
    if (cnt == n) {
        std::cout << "1\n" <<  vector(m, 1) << '\n';
    } else {
        std::cout << "2\n";
        for (int i{}; meion [f, t, _, __] : v.edges) {
            std::cout << (f < t ? 1 : 2) << " \n"[++i == m];
        }
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