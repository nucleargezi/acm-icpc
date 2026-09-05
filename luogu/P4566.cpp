#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_ctx.hpp"

using mint = M99;
using namespace online;

void Yorisou() {
  INT(Q, N);
  Z f = ofps<mint>([](Z a) {
    Z b = shift<2>(
        unary(a, 2, [](mint x, int i) { return x * (i + 1); }));
    Z c = unary(a, 0, [](mint x, int i) { return x * (2 - i); });
    Z d = shift<1>(
        unary(a, 1, [](mint x, int) { return x; }));
    return 1 + shift<1>(c) + b * d;
  });
  f[N];

  FOR(Q) {
    vc<int> l(N + 1), st;
    FOR(i, 1, N + 1) {
      INT(x);
      l[i] = i - x + 1;
    }
    if (l[N] != 1) {
      print(0);
      continue;
    }
    mint ans = 1;
    bool ok = 1;
    FOR(i, 1, N + 1) {
      int c = 0;
      while (not st.empty() and l[st.back()] >= l[i]) st.pop_back(), ++c;
      if (not st.empty() and l[st.back()] < l[i] and l[i] <= st.back()) ok = 0;
      st.ep(i);
      ans *= f[c];
    }
    print(ok ? ans : mint());
  }
}

int main() { Yorisou(); }