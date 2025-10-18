#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/hyogen.hpp"

// #define tests
using MX = hyogen<bool>;
using X = MX::X;
using vec = MX::vec;
void Yorisou() {
  STR(str);
  vec s = MX::inf_to_suf(str);
  vector<tuple<bool, int, int>> st;
  for (Z [o, x, op] : s) {
    if (o) {
      st.ep(x, 0, 0);
    } else {
      Z [y, cya, cyo] = pop(st);
      Z [x, cxa, cxo] = pop(st);
      bool A = op == '&' and x == 0, B = op == '|' and x == 1;
      x = MX::keis(x, y, op);
      cxa += cya * not(A or B) + A;
      cxo += cyo * not(A or B) + B;
      st.ep(x, cxa, cxo);
    }
  }
  Z [x, cxa, cxo] = st[0];
  print(x);
  print(cxa, cxo);
}
#include "YRS/Z_H/main.hpp"