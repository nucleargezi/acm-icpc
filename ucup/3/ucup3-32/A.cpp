#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"

void yorisou() {
  INT(N);
  vc<int> a(N + 1), f(a);
  FOR(i, 1, N + 1) IN(a[i]), f[a[i]] = i;

  ll s = 0;
  vc<PII> ans;
  Z op = [&](int i, int k) {
    if (i == k) return;
    s += i & k;
    swap(a[i], a[k]);
    f[a[i]] = i;
    f[a[k]] = k;
    ans.ep(i, k);
  };
  FOR_R(i, 2, N + 1) if (a[i] != i and (i != (1 << topbit(i)))) {
    int p = f[i];
    bool ok = 0;
    FOR(t, 20) {
      int c = 1 << t;
      if (c <= N and not(c & i) and not(c & p)) {
        op(c, p);
        op(i, c);
        ok = 1;
        break;
      }
    }
    if (not ok) {
      if (i == N and (i + 1) == (1 << topbit(i + 1))) {
        FOR(t, 1, 16) {
          if (not(p >> t & 1) and (1 << t) <= N) {
            ok = 1;
            op(p, 1 << t);
            op(1 << t, 1);
            op(1, i);
            break;
          }
        }
        if (not ok) op(p, 1), op(1, i);
      } else {
        FOR(j, 16) FOR(k, 16) if ((1 << max(j, k)) <= N and j != k and not ok) {
          if (not(p & (1 << j)) and not((1 << k) & i)) {
            op(p, (1 << j));
            op((1 << j), (1 << k));
            op((1 << k), i);
            ok = 1;
          }
        }
      }
    }
  }

  FOR_R(i, 20) if ((1 << i) <= N and a[1 << i] != (1 << i)) {
    op(1 << i, f[1 << i]);
  }

  print(s);
  print(si(ans));
  for (var t : ans) print(t);
}

int main() {
  INT(T);
  FOR(T) yorisou();
  return 0;
}