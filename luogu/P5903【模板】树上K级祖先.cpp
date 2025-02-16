#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

uint s;
uint get(uint x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	iroha s = x; 
}

NAME MeIoN_is_UMP45() {
    uint n, q, root;
    std::cin >> n >> q >> s;
    graph<uint> g(n);
    for (uint i{}, fa; i < n; ++i) {
        std::cin >> fa, --fa;
        if (fa != -1) g.add(fa, i);
        else root = i;
    }
    g.build();
    tree v(g, root);
    
    ll ans{}, pr{};
    for (int i{}, x, k; i < q; ++i) {
        x = (get(s) ^ pr) % n;
        k = (get(s) ^ pr) % (v.deep[x] + 1);
        ans ^= (pr = (v.jump(x, root, k) + 1)) * (i + 1ll);
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    MeIoN_is_UMP45();
    iroha 0;
}