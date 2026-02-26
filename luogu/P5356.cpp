#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr int N = 1'000'00;
int a[N], b[N], add[N];
void Yorisou() {
  INT(N, Q);
  FOR(i, N) IN(a[i]);
  memcpy(b, a, N * sizeof(int));
  constexpr int B = 128;
  const int bsz = ceil(N, B);
  vc<int> R(N);
  FOR(i, N) R[i] = min(N, i / B * B + B);
  FOR(i, bsz) sort(b + i * B, b + R[i * B]);

  FOR(Q) {
    INT(op, l, r, k);
    --l, --r;
    int ls = l / B, rs = r / B;
    if (op == 1) {
      int ans = bina([&](ll x) -> bool {
        if (x == 2'000'000'001) return 1;
        int s = 0;
        if (ls == rs) {
          FOR(i, l, r + 1) s += (a[i] + add[ls] <= x);
        } else {
          FOR(i, l, R[l]) s += (a[i] + add[ls] <= x);
          FOR(i, rs * B, r + 1) s += (a[i] + add[rs] <= x); 
          FOR(i, ls + 1, rs) {
            if (b[i * B] + add[i] > x) continue;
            if (b[R[i * B] - 1] + add[i] <= x) {
              s += R[i * B] - i * B;
              continue;
            }
            s += upper_bound(b + i * B, b + R[i * B], x - add[i]) - b - i * B;
          }
        }
        return s >= k;
      }, 2'000'000'001, -2'000'000'000 - 1);
      if (ans == 2'000'000'001) ans = -1;
      print(ans);
    } else {
      if (ls == rs) {
        FOR(i, l, r + 1) a[i] += k;
        FOR(i, ls * B, R[l]) b[i] = a[i];
        sort(b + ls * B, b + R[ls * B]);
      } else {
        FOR(i, l, R[l]) a[i] += k;
        FOR(i, ls * B, R[l]) b[i] = a[i];
        sort(b + ls * B, b + R[ls * B]);
        FOR(i, rs * B, r + 1) a[i] += k;
        FOR(i, rs * B, R[r]) b[i] = a[i];
        sort(b + rs * B, b + R[rs * B]);
        FOR(i, ls + 1, rs) add[i] += k;
      }
    }
  }
}
#include "YRS/aa/main.hpp"