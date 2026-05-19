#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/func.hpp"

void Yorisou() {
  INT(N, K);
  VEC(ll, a, N);
  a.insert(ed(a), all(a));
  pop(a);
  print(bina([&](ll lm) -> bool {
    int r = 0;
    ll s = 0;
    vc<int> to(N + N + 1, N + N);
    FOR(l, N + N - 1) {
      while (r - l < N and r < N + N - 1 and s < lm) s += a[r++];
      if (s >= lm) to[l] = r;
      s -= a[l];
    }
    to = func_g(to).jump_all(K);
    FOR(i, N) if (to[i] - i <= N) return 1;
    return 0;
  }, 0, SUM<ll>(a) / K + 1));
}

int main() {
  Yorisou();
  return 0;
}