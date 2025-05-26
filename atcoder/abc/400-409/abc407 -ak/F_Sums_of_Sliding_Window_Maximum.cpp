#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector<ll> pr(n), nx(n), s;
  FOR(i, n) {
    while (not s.empty() and a[s.back()] <= a[i]) s.pop_back();
    pr[i] = s.empty() ? -1 : s.back();
    s += i;
  }
  s.clear();
  FOR_R(i, n) {
    while (not s.empty() and a[s.back()] < a[i]) s.pop_back();
    nx[i] = s.empty() ? n : s.back();
    s += i;
  }
  vector<ll> X(n + 10, 0), Y(n + 10, 0);
  FOR(i, n) {
    ll l = i - pr[i], r = nx[i] - i;
    std::tie(l, r) = MINMAX(l, r);
    ll s = l + r;
    X[1] += a[i];
    X[l + 1] -= a[i];
    Y[l + 1] += l * a[i];
    Y[r + 1] -= l * a[i];
    if (r + 1 <= s - 1) {
      Y[r + 1] += s * a[i];
      Y[s] -= s * a[i];
      X[r + 1] -= a[i];
      X[s] += a[i];
    }
  }
  X = pre_sum<false>(X);
  Y = pre_sum<false>(Y);
  FOR(i, n) {
    UL(X[i + 1] * (i + 1) + Y[i + 1]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"