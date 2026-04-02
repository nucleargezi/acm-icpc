#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"

struct dat {
  vc<ull> a;
  void from_s() {
    STR(s);
    int N = len(s);
    while (N % 32) ++N, s += 'A';
    for (char &c : s) c -= 'A';
    a.resize(N >> 5);
    FOR(i, N >> 5) {
      FOR(k, 32) {
        ull l, r;
        char c = s[i << 5 | k];
        l = not(c & 1);
        r = not(c & 2);
        a[i] |= l << (32 + k);
        a[i] |= r << k;
      }
    }
  }
  
  int count(const dat &p) const {
    int N = len(a), s = 0;
    FOR(i, N) {
      ull x = a[i] ^ p.a[i];
      s += pc(uint(x | (x >> 32)));
    }
    return s;
  }
};
void Yorisou() {
  INT(N, M, K);
  vc<dat> s(N);
  FOR(i, N) s[i].from_s();
  vc<int> A, B;
  int p = rng(N);
  Z ck = [&](const dat &a, const dat &b) -> bool {
    return a.count(b) == K;
  };
  FOR(i, N) if (i != p) {
    if (ck(s[i], s[p])) A.ep(i);
    else B.ep(i);
  }
  if (len(A) == N - 1) return print(p + 1);
  vc<int> C;
  C.ep(p);
  while (len(A) > 1) {
    if (not B.empty()) {
      p = pop(B);
      C.ep(p);
      vc<int> aa;
      for (int i : A) {
        if (ck(s[i], s[p])) aa.ep(i);
        else B.ep(i);
      }
      A.swap(aa);
    } else {
      p = pop(A);
      bool ok = 1;
      for (int i : A) {
        if (not ck(s[i], s[p])) {
          ok = 0;
          break;
        }
      }
      if (not ok) {
        C.ep(p);
        continue;
      }
      for (int i : C) {
        if (not ck(s[i], s[p])) {
          ok = 0;
          break;
        }
      }
      if (not ok) {
        C.ep(p);
        continue;
      }
      return print(p + 1);
    }
  }
  print(A[0] + 1);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"