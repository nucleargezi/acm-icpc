#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/wave/wave_mat_sim.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr int B = 32;
template <int sz> 
void sol(int N, int c, int Q, const vc<int> &a, const wave_matrix_sim<int> &wm) {
  const int bsz = ceil(N, B);
  static bitset<sz> msk, bit[ceil(1'000'00, B) + 1];
  FOR(i, N) if (a[i] != -1) bit[i / B + 1].flip(a[i]);
  FOR(i, 1, bsz) bit[i + 1] ^= bit[i];
  int ans = 0;
  FOR(Q) {
    INT(l, r);
    l = (l + ans) % N, r = (r + ans) % N;
    if (l > r) swap(l, r);
    ans = 0;
    int ls = l / B, rs = r / B;
    if (ls == rs) {
      FOR(i, l, r + 1) {
        int x = a[i];
        if (x == -1) continue;
        msk.reset(a[i]);
      }
      FOR(i, l, r + 1) {
        int x = a[i];
        if (x == -1) continue;
        ans += not msk[x];
        msk.set(x);
      }
      FOR(i, l, r + 1) {
        int x = a[i];
        if (x == -1) continue;
        if (msk[x]) --ans;
        else ++ans;
        msk.flip(x);
      }
      print(ans);
      continue;
    }
    ++r;
    if (ls + 1 < rs) {
      msk = bit[ls + 1] ^ bit[rs];
    } else {
      msk.reset();
    }
    FOR(i, l, ls * B + B) {
      int x = a[i];
      if (x != -1) msk.flip(x);
    }
    FOR(i, rs * B, r) {
      int x = a[i];
      if (x != -1) msk.flip(x);
    }
    ans = wm.rank(l, r, l) - msk.count();
    print(ans);
  }
}
void Yorisou() {
  INT(N, c, Q);
  VEC(int, a, N);
  FOR(i, N) --a[i];
  vc<int> co(c);
  FOR(i, N) ++co[a[i]];
  vc<int> f;
  FOR(i, N) {
    if (co[a[i]] == 1) a[i] = -1;
    else f.ep(a[i]);
  }
  unique(f);
  c = len(f);
  FOR(i, N) if (a[i] != -1) a[i] = lb(f, a[i]);

  vc<int> dat(N, N), pr(c, -1);
  FOR(i, N) if (a[i] != -1) {
    dat[i] = pr[a[i]];
    pr[a[i]] = i;
  }
  wave_matrix_sim wm(dat);
  if (c <= (1 << 6)) sol<1 << 6>(N, c, Q, a, wm);
  else if (c <= (1 << 7)) sol<1 << 7>(N, c, Q, a, wm);
  else if (c <= (1 << 8)) sol<1 << 8>(N, c, Q, a, wm);
  else if (c <= (1 << 9)) sol<1 << 9>(N, c, Q, a, wm);
  else if (c <= (1 << 10)) sol<1 << 10>(N, c, Q, a, wm);
  else if (c <= (1 << 11)) sol<1 << 11>(N, c, Q, a, wm);
  else if (c <= (1 << 12)) sol<1 << 12>(N, c, Q, a, wm);
  else if (c <= (1 << 13)) sol<1 << 13>(N, c, Q, a, wm);
  else if (c <= (1 << 14)) sol<1 << 14>(N, c, Q, a, wm);
  else if (c <= (1 << 15)) sol<1 << 15>(N, c, Q, a, wm);
  else if (c <= (1 << 16)) sol<1 << 16>(N, c, Q, a, wm);
  else if (c <= (1 << 17)) sol<1 << 17>(N, c, Q, a, wm);
  else if (c <= (1 << 18)) sol<1 << 18>(N, c, Q, a, wm);
}
#include "YRS/aa/main.hpp"