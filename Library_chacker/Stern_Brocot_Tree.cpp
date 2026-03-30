#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/nt/sbt.hpp"

void Yorisou() {
  INT(Q);
  sbt g;
  FOR(Q) {
    STR(s);
    if (s == "DECODE_PATH") {
      INT(n);
      vc<int> A;
      FOR(n) {
        CH(s);
        INT(x);
        if (A.empty() && s == 'L') { A.ep(0); }
        A.ep(x);
      }
      print(g.from_pa<ll>(A));
    }
    if (s == "ENCODE_PATH") {
      LL(a, b);
      vc<int> A = g.get_path({a, b});
      vc<string> s;
      FOR(i, si(A)) {
        if (A[i] == 0) continue;
        string x = (i % 2 == 0 ? "R" : "L");
        s.ep(x);
        s.ep(to_string(A[i]));
      }
      print(si(s) / 2, s);
    }
    if (s == "LCA") {
      LL(a, b, c, d);
      print(g.lca({a, b}, {c, d}));
    }
    if (s == "ANCESTOR") {
      LL(k, a, b);
      Z [x, y] = g.la({a, b}, k);
      if (x == -1) print(-1);
      else print(x, y);
    }
    if (s == "RANGE") {
      LL(a, b);
      print(g.range({a, b}));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"