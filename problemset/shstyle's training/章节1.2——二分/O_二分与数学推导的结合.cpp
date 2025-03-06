#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<ll> A(n);
    std::cin >> A;
    sort(A);
    
    for (ll i{}, a, b, c; i < m; ++i) {
        std::cin >> a >> b >> c;
        if (a * c * 4 <= 0) {
            NO();
        } else {
            ll d = std::sqrt(a * c * 4 - 1);
            int x = lower(A, b - d) - A.begin();
            if (x == n or A[x] > b + d) NO();
            else {
                YES();
                std::cout << A[x] << '\n';
            }
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