#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for (meion &[val, kind] : a) {
        std::cin >> kind >> val;
        --kind;
    }
    sort(a, greater());
    priority_queue<pair<ll, ll>> q;
    vector<int> c(n);
    ll all{}, s{}, ans{}, kds{};
    for (meion [val, kind] : a) {
        if (all > k - 1) {
            while (not q.empty()) {
                meion[v, kd] = q.top();
                q.pop(); 
                if (c[kd] == 1) {
                    continue;
                } else {
                    --c[kd];
                    --all;
                    s += v;
                    break;
                }
            }
        }
        if (all < k) {
            s += val;
            kds += c[kind]++ == 0;
            ++all;
            q.emplace(-val, kind);
        }
        chmax(ans, s + kds * kds);
    }
    std::cout << ans << '\n';
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