#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/gauss.hpp"

constexpr int sz = 58;
using T = bitset<sz>;
void Yorisou() {
  vc<ll> f{1, 1};
  for (int i = 2;; ++i) {
    ll x = f[i - 1] + f[i - 2];
    if (x > 1'000'000'000'000ll) break;
    f.ep(x);
  }
  f.erase(bg(f));

  LL(N, M);
  vc<T> a(sz);
  T b{};
  FOR(i, sz) if (N >> i & 1) b[i] = 1;
  FOR(i, sz) FOR(k, sz) if (f[k] >> i & 1) a[i][k] = 1;

  vc<T> sl = solve_linear<sz>(sz, sz, a, b);
  if (sl.empty()) return print(-1);
  int n = si(sl) - 1;
  Z ff = f;
  reverse(all(ff));
  int rs = 1000;
  FOR(s, 1 << n) {
    T t = sl[0];
    FOR(i, n) if (s >> i & 1) t ^= sl[i + 1];
    ll sm = 0;
    FOR(i, sz) if (t[i]) sm += f[i];
    if (sm > M) continue;
    sm = M - sm;
    int c = 0;
    for (ll x : ff) if (sm - x - x >= 0) sm -= x + x, c += 2;
    if (sm == 0) rs = min<int>(rs, t.count() + c);
  }
  print(rs == 1000 ? -1 : rs);
}

int main() {
  Yorisou();
  return 0;
}