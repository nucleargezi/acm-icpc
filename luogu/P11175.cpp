#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/modfast.hpp"
#include "YRS/pr/discreate_log_fast.hpp"

#define tests 0
#define fl 0
#define DB 10

struct logfast {
  using u16 = uint16_t;
  int p;
  
  uint root;
  inline static array<uint, 65537> pw[2];
  inline static array<pair<u16, u16>, 1 + (1 << 20)> fra;
  
  static constexpr int K = 1 << 21;
  inline static array<uint, K << 1 | 1> lg, in;
  
  logfast(int p, int g) : p(p), root(g) {
    // root = p == 998244353 ? 3 : primitive_root(p);
    build_pow();
    build_log();
    build_frac();
  }

  uint pow_r_32(uint exp) {
    assert(0 <= exp and exp < (uint)p);
    return ull(pw[0][exp & 32767]) * pw[1][exp >> 15] % p;
  }

  uint log_r(uint x) {
    assert(0 < x and x < (uint)p);
    Z [a, b] = fra[x >> 10];
    uint t = x * b - a * p;
    return lg[K + t] + (p - 1) - lg[K + b];
  }

  uint inv(uint x) {
    assert(0 < x and x < (uint)p);
    Z [a, b] = fra[x >> 10];
    uint t = x * b - a * p;
    return in[K + t] * ull(b) % p;
  }
  
  void build_pow() {
    pw[0][0] = pw[1][0] = 1;
    FOR(i, 1 << 15) pw[0][i + 1] = pw[0][i] * ull(root) % p;
    FOR(i, 1 << 15) pw[1][i + 1] = pw[1][i] * ull(pw[0][1 << 15]) % p;
  }

  void build_log() {
    const int lm = 1 << 21;
    Z lpf = lpf_table(lm);

    const int S = 1 << 17;
    hash_map<uint> mp(S);
    uint w = 1;
    FOR(k, S) mp[w] = k, w = ull(root) * w % p;
    uint q = pow_r_32(p - 1 - S);
    Z BSGS = [&](uint s) -> uint {
      uint ans = 0;
      while (1) {
        uint x = mp.get(s, -1);
        if (x != uint(-1)) return ans + x;
        ans += S, s = ull(s) * q % p;
      }
      return 0;
    };
    lg[K + 1] = 0;
    FOR(i, 2, 1 + (1 << 21)) {
      if (lpf[i] < i) {
        lg[K + i] = (lg[K + lpf[i]] + lg[K + i / lpf[i]]) % (p - 1);
        continue;
      }
      if (i < 100) {
        lg[K + i] = BSGS(i);
        continue;
      }
      if (i * i > p) {
        Z [j, k] = divmod<int>(p, i);
        lg[K + i] = (lg[K + k] + (p - 1) / 2 + p - 1 - lg[K + j]) % (p - 1);
        continue;
      }
      while (1) {
        uint k = rng(0, p - 1);
        ull ans = p - 1 - k;
        uint x = ull(i) * pow_r_32(k) % p;
        Z div = [&](uint q) { x /= q, ans += lg[K + q]; };
        static constexpr uint qs[] = {2, 3, 5, 7, 11, 13, 17, 19};
        for (uint q : qs)
          while (x % q == 0) div(q);
        if (x >= lm) continue;
        while ((uint)i < x and x < lm and lpf[x] < i) div(lpf[x]);
        if (1 < x and x < (uint)i) div(x);
        if (x == 1) {
          lg[K + i] = ans % (p - 1);
          break;
        }
      }
    }
    FOR(i, 1, 1 + (1 << 21)) lg[K - i] = (lg[K + i] + (p - 1) / 2) % (p - 1);
  }
  void build_frac() {
    vc<T4<u16>> q;
    q.reserve(1 << 18);
    q.ep(0, 1, 1, 1);
    while (not q.empty()) {
      Z [a, b, c, d] = pop(q);
      if (b + d < 2048) {
        q.ep(a + c, b + d, c, d);
        q.ep(a, b, a + c, b + d);
        continue;
      }
      uint s = ull(a) * p / (1024 * b);
      uint t = ull(c) * p / (1024 * d);
      fra[s] = {a, b};
      fra[t] = {c, d};
      a = min(a, c), b = min(b, d);
      for (uint i = s + 1; i < t; ++i) fra[i] = {a, b};
    }
  }
};
void Yorisou() {
  INT(p, g);
  if (p <= 100) {
    INT(Q);
    FOR(Q) {
      INT(y);
      print(discreate_log(g, y, p));
    }
    return;
  }
  logfast f(p, g);
  INT(Q);
  FOR(Q) {
    INT(y);
    print(f.log_r(y) % (p - 1));
  }
}
#include "YRS/aa/main.hpp"