#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
uint x = 123456789, y = 362436069, 
     z = 521288629, w = 88675123;
uint xor128() {
	uint t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}
constexpr int mod = 100003;
using mint = mint_t<mod>;
void Yorisou() {
  INT(N, Q);
  vc<mint> a(N);
  FOR(i, N) a[i] = xor128();
  if (N < 2000) {
    FOR(Q) {
      INT(x);
      uint s = 0;
      FOR(i, N) chmax(s, (a[i] * x).val());
      print(s);
    }
  } else {
    vc<u8> vis(mod);
    FOR(i, N) vis[a[i].val()] = 1;
    FOR(Q) {
      INT(x);
      if (x == 0) {
        print(0);
        continue;
      }
      int ans = 0;
      FOR(i, 2000) {
        mint f = inv<mint>(x) * (mod - i - 1);
        if (not vis[f.val()]) continue;
        ans = mod - i - 1;
        break;
      }
      print(ans);
    }
  }
}
#include "YRS/aa/main.hpp"