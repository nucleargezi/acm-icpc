#include "YRS/all.hpp"

struct X {
  ll a, b;
  void nor() {
    ll g = gcd(a, b);
    a /= g, b /= g;
  }
  string to_s() { return to_string(a) + "/" + to_string(b); }
  bool les(X x) { return a == -1 or a * x.b > b * x.a; }
};

X div(X a, X b) {
  a.a *= b.b;
  a.b *= b.a;
  a.nor();
  return a;
}

void Yorisou() {
  LL(a, b, c);
  X ans{-1, 1};
  for (X x : {X{a * b, a + b}, X{a * b, b - a}}) {
    x.nor();
    for (X y : {X{a * c, a + c}, {a * c, c - a}}) {
      y.nor();
      y.a *= div(y, x).b;
      y.nor();
      if (ans.les(y)) ans = y;
    }
  }
  print(ans.to_s());
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"