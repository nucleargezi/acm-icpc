#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

#define tests
using mint = M17;
void Yorisou() {
  LL(n);
  VEC(T3<ll>, a, n);
  mint ans;
  {
    vector<ll> v;
    for (meion[x, y, a] : a) {
      v.emplace_back(x + y);
    }
    meion I = argsort(v);
    meion st_v = rearrange(v, I);
    meion c = pre_sum(st_v);
    mint L = 0;
    FOR(i, n) {
      ll id = I[i], x = v[id];
      L += mint(std::get<2>(a[id])) * (c[n] - c[i + 1] - (n - i - 1) * x + (x * i) - c[i]);
    }
    ans += L;
  }
  {
    vector<ll> v;
    for (meion[x, y, a] : a) {
      v.emplace_back(x - y);
    }
    meion I = argsort(v);
    meion st_v = rearrange(v, I);
    meion c = pre_sum(st_v);
    mint R = 0;
    FOR(i, n) {
      ll id = I[i], x = v[id];
      R += mint(std::get<2>(a[id])) * (c[n] - c[i + 1] - (n - i - 1) * x + (x * i) - c[i]);
    }
    ans += R;
  }
  UL(ans / 2);
}
#include "MeIoN_Lib/Z_H/main.hpp"