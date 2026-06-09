#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/random/rng.hpp"

constexpr int N = 3'000'0;
bitset<N> vis;
void Yorisou() {
  INT(N);
  VEC(int, a, N);

  Z ck = [&]() {
    static vc<int> f;
    f.clear();
    FOR(i, N) if (not vis.test(i)) f.ep(a[i]);
    int sz = si(f);
    FOR(i, 1, sz) f[i - 1] = f[i] - f[i - 1];
    pop(f);
    FOR(i, sz - 1) if (f[i] != f[max(i - 1, 0)]) return 0;
    return 1;
  };

  FOR(i, 4) if (i + 1 < N) {
    FOR(20) {
      vis.reset();
      int k = rng(i + 1, min(10, N)), d = a[k] - a[i];
      vis[k] = vis[i] = 1;
      int pr = a[k];
      FOR(j, k + 1, N) {
        if (a[j] == pr + d) vis.set(j), pr += d;
      }
      if (not ck()) continue;
      vc<int> b, c;
      FOR(i, N) (vis[i] ? b : c).ep(a[i]);
      if (c.empty()) c.ep(pop(b));
      if (b.empty()) b.ep(pop(c));
      return print(b), print(c);
    }
  }

  FOR(i, max(N - 4, 0), N) if (i) {
    FOR(20) {
      vis.reset();
      int k = rng(max(0, N - 10), i), d = a[k] - a[i];
      vis[k] = vis[i] = 1;
      int pr = a[k];
      FOR_R(j, k) {
        if (a[j] == pr + d) vis.set(j), pr += d;
      }
      if (not ck()) continue;
      vc<int> b, c;
      FOR(i, N) (vis[i] ? b : c).ep(a[i]);
      if (c.empty()) c.ep(pop(b));
      if (b.empty()) b.ep(pop(c));
      return print(b), print(c);
    }
  }
  print("No solution");
}

int main() {
  Yorisou();
  return 0;
}