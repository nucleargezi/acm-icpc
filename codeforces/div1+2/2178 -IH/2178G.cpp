#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
struct BIT {
  int N;
  vector<ull> a;
  BIT(int N) : N(N), a(N) {}
  ull prod(int l, int r) {
    if (l >= r) return 0;
    ull s = 0;
    while (l < r) s ^= a[r - 1], r -= r & -r;
    while (r < l) s ^= a[l - 1], l -= l & -l;
    return s;
  }
  void upd(int i, ull x) {
    for (++i; i <= N; i += i & -i) a[i - 1] ^= x;
  }
};
void Yorisou() {
  INT(N);
  VEC(PII, a, N);
  vc<ull> t(N << 1);
  FOR(i, N << 1) t[i] = rng_64();
  
  string ans(N, '0');
  BIT bit(N << 1);
  ull s = 0;
  for (int i = 0; Z [l, r] : a) {
    --l, --r;
    ull h = (t[l] ^ t[r]) << 1, H = bit.prod(l + 1, r);
    bool o = (H & 1) ^ 1;
    H &= ~1ull;
    if (o) H ^= h | 1;
    bit.upd(l, H), bit.upd(r, H);
    s ^= H >> 1;
    ans[i++] += s == 0;
  }
  print(ans);
}
#include "YRS/aa/main.hpp"