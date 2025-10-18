#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/hyogen.hpp"

// #define tests
using MX = hyogen<ll>;
using X = MX::X;
using vec = MX::vec;
void Yorisou() {
  STR(str);
  vec s = MX::inf_to_suf(str);
  MX::print_suf(s);
  while (len(s) > 1) {
    vec ss;
    const int N = len(s);
    FOR(i, N) {
      X x = s[i];
      if (x.n) ss.ep(x);
      else {
        ll b = pop(ss).x;
        ll a = pop(ss).x;
        a = MX::keis(a, b, x.op);
        ss.ep(MX::get_x(a));
        FOR(k, i + 1, N) ss.ep(s[k]);
        break;
      }
    }
    s.swap(ss);
    MX::print_suf(s);
  }
}
#include "YRS/Z_H/main.hpp"