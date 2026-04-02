#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"

template <int K>
void sol() {
  INT(N);
  if constexpr (K == 1) {
    VEC(int, a, N);
    print(QMAX(a) - QMIN(a));
  } else if constexpr (K == 2) {
    VEC(int, a, N);
    VEC(int, b, N);
    FOR(i, N) if (a[i] > b[i]) swap(a[i], b[i]);
    print(max(QMAX(a) - QMIN(a), QMAX(b) - QMIN(b)));
  } else {
    vc<array<int, K>> a(N);
    FOR(i, K) FOR(k, N) IN(a[k][i]);
    int s = inf<int>;
    vc<int> I(N);
    iota(all(I), 0);
    FOR(300) {
      shuffle(I);
      a = rearrange(a, I);
      int l[K]{}, r[K]{}, nl[K], nr[K], ss = 0;
      FOR(i, K) l[i] = r[i] = a[0][i];
      FOR(i, 1, N) {
        int nx = inf<int>;
        FOR(k, K) {
          int ll[K], rr[K], ns{};
          FOR(i, K) ll[i] = l[i], rr[i] = r[i];
          FOR(j, K) {
            int x = a[i][(j + k) % K];
            chmin(ll[j], x);
            chmax(rr[j], x);
            chmax(ns, rr[j] - ll[j]);
          }
          if (chmin(nx, ns)) FOR(i, K) nl[i] = ll[i], nr[i] = rr[i];
        }
        ss = nx;
        FOR(i, K) l[i] = nl[i], r[i] = nr[i];
      }
      chmin(s, ss);
    }
    print(s);
  }
}

void Yorisou() {
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
  INT(T, K);
  if (K == 1) FOR(T) sol<1>();
  if (K == 2) FOR(T) sol<2>();
  if (K == 3) FOR(T) sol<3>();
  if (K == 4) FOR(T) sol<4>();
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"