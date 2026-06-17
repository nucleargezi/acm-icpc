#include "YRS/all.hpp"

bool Q(int x) {
  ++x;
  print("?", x);
  IN(x);
  if (x == -1) assert(0);
  return x;
}

void Yorisou() {
  INT(N);
  FOR_R(i, 1, N) {
    int c = 0;
    while (Q(i)) ++c;
    if (c >= N - 1) break;
  }
  Q(0);
  vc<int> tp{1};
  int sp = -1;
  FOR(i, 1, N) {
    FOR(k, N) {
      if (not Q(i)) {
        if (k + 1 == N) {
          sp = i - 1;
          FOR(N - tp.back()) Q(sp);
          FOR(k, N) if (not Q(i)) {
            tp.ep(k + 1);
            break;
          }
        } else {
          tp.ep(k + 1);
        }
        break;
      }
    }
  }
  vc<int> p(N);
  FOR(i, 1, N) p[i] = ((p[i - 1 - (i - 1 == sp)] - tp[i]) % N + N) % N;
  FOR(i, N) p[i] = (p[i] + tp[i]) % N;
  if (sp != -1) p[sp] = p[0];
  int id = -1, mx = inf<int>;
  FOR(g, N) {
    int s = 0;
    FOR(i, N) s += p[i] <= g ? g - p[i] : N - p[i] + g;
    if (chmin(mx, s)) id = g;
  }
  FOR(i, N) while (p[i] != id) p[i] = (p[i] + 1) % N, Q(i);
  print("!");
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}