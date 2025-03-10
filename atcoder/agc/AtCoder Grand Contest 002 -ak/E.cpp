#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    meion F = [](bool f = true) { std::cout << (f ? "First\n" : "Second\n"); };
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    sort(a, greater()); 
    int s{n - 1};
    for (int i{1}, f{1}; i < n and f; ++i) {
        if (a[i] == i) {
            int f{a[i - 1] - i & 1};
            if (a[i - 1] - i & 1) iroha F();
            int k{i};
            while (k < n and a[i] == a[k]) ++k;
            iroha F(k - i & 1);
        } else if (a[i] < i) {
            s = i - 1, f = 0;
        }
    }
    F(a[s] - s + 1 & 1);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}