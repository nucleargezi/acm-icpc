#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(l, b, f, n);
  using car = struct {
    ll st, ed, id;
  };
  vector<car> in;
  FOR(c, n) {
    LL(op, x);
    if (op == 1) {
      bool ok = 0;
      if (in.empty()) {
        if (x <= l) {
          in.emplace_back(car{0, x, c});
          UL(0);
          continue;
        }
      } else {
        if (in[0].st >= x + f) {
          in.insert(in.begin(), car{0, x, c});
          UL(0);
          continue;
        }
        FOR(i, len(in) - 1) {
          ll l = in[i].ed, r = in[i + 1].st;
          if (r - l >= b + x + f) {
            in.insert(in.begin() + i + 1, car{l + b, l + b + x, c});
            UL(l + b);
            ok = 1;
            break;
          }
        }
        if (ok) continue;
        int r = in.back().ed;
        if (l - r >= b + x) {
          UL(r + b);
          in.emplace_back(r + b, r + b + x, c);
          continue;
        }
      }
      UL(-1);
    } else {
      int er = -1;
      FOR(i, len(in)) {
        if (in[i].id == x - 1) er = i;
      }
      in.erase(in.begin() + er);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"