#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(N, b, Q);
  ll a = N - b;
  string s;
  ll c = min(a, b), ls = max(a - b, 0ll), p0 = c + ls / 2, p1 = ceil<ll>(a, 2);

  FOR(Q) {
    LL(x);
    --x;
    if (p1 >= p0) {
      s += "X."[x < a];
    } else {
      if (a >= b) {
        bool f = (b and ((a - b) & 1));
        if (x < a - b + f) s += '.';
        else {
          if (f and x + 1 == N) s += 'X';
          else s += ".X"[(N - x - f) & 1];
        } 
      } else {
        if (x < 2 * a) s += ".X"[x & 1];
        else s += 'X';
      }
    }
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}