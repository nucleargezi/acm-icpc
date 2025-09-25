#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/hashmap.hpp"

// #define tests
struct Seg {
  using RE = double;
  int N;
  hash_map<RE> m;

  Seg(int N) : N(N), m(1 << std::min(N, 22)) {}

  void add(int p, int x) {
    while (p) m[p] += x, p >>= 1;
  }

  RE f(int p, int s, RE mx) {
    RE x = m.get(p, 0);
    if (p >= (1 << N)) chmax(mx, x);
    if (x <= mx) return mx * s / (1 << N);
    return f(p << 1, s >> 1, std::max(mx, x - m[p << 1])) +
           f(p << 1 | 1, s >> 1, std::max(mx, x - m[p << 1 | 1]));
  }
};
void Yorisou() {
  INT(N, Q);
  Seg seg(N);
  
  setp(8);
  FOR(Q) {
    STR(op);
    if (op == "add") {
      INT(p, x);
      seg.add(p, x);
    } else {
      print(seg.f(1, 1 << N, 0));
    }
  }
}
#include "YRS/Z_H/main.hpp"