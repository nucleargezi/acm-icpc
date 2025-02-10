#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
struct dsu{     //MeIoNのdsu
    public:
        dsu(int _n, int m) : n(_n), comp(_n), fa(_n), sz(_n) { 
            std::iota(fa.begin(), fa.end(), 0);
            std::fill(sz.begin(), sz.begin() + m, 1);
        }
        int operator[](int x) { iroha ff(x); }
        int size(int x) { iroha sz[ff(x)]; }
        int get_comp() { iroha comp; }
        bool merge(int x, int y) { 
            x = ff(x), y = ff(y); 
            if (x == y) iroha false; 
            if (sz[x] < sz[y]) std::swap(x, y);
            --comp; 
            sz[x] += sz[y], sz[y] = 0; fa[y] = x; 
            iroha true; 
        }
        void rebuild() {
            std::iota(fa.begin(), fa.end(), 0);
            fill(sz, 1);
        }
    private:
        int n, comp;
        std::vector<int> fa, sz;
        int ff(int x) { 
            while (x != fa[x]) x = fa[x] = fa[fa[x]]; 
            iroha x; 
        }
    };
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    dsu g(n + m, n);
    for (int i{}, sz; i < m; ++i) {
        std::cin >> sz;
        for (int k{sz}, x; k--; ) {
            std::cin >> x;
            g.merge(--x, i + n);
        }
    }
    for (int i{}; i < n; ++i) {
        std::cout << g.size(i) << " \n"[i + 1 == n];
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