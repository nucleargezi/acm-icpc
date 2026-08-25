#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/segment.hpp"

using re = ld;
using P = point<ll>;
using R = point<re>;
#define cp const P &

void no() { print(-1, -1, -1, -1); }

R to(cp p) { return {re(p.x), re(p.y)}; }

bool ins(vc<P> &g, cp p) {
  int N = si(g);
  if (N == 1) return g[0] == p;
  if (N == 2) return segment(g[0], g[1]).contains(p);
  FOR(i, N) {
    segment S(g[i], g[i < N - 1 ? i + 1 : 0]);
    if (S.contains(p)) return 1;
  }
  int w = 0;
  FOR(i, N) {
    P a = g[i], b = g[i < N - 1 ? i + 1 : 0];
    ll d = (b - a).det(p - a);
    if (a.y <= p.y and p.y < b.y and d > 0) ++w;
    if (b.y <= p.y and p.y < a.y and d < 0) --w;
  }
  return w != 0;
}

optional<R> cross(cp a, cp b, cp c, cp d) {
  P A = b - a, B = d - c, C = c - a;
  ll z = A.det(B), x = C.det(B), y = C.det(A);
  if (z != 0) {
    if (z < 0) z = -z, x = -x, y = -y;
    if (x < 0 or x > z or y < 0 or y > z) return nullopt;
    return to(a) + to(A) * ((ld)x / z);
  }
  if (A.det(C) != 0) return nullopt;
  segment s{a, b}, t{c, d};
  if (t.contains(a)) return to(a);
  if (t.contains(b)) return to(b);
  if (s.contains(c)) return to(c);
  if (s.contains(d)) return to(d);
  return nullopt;
}

void Yorisou() {
  INT(N, M, Q);
  VEC(P, a, N);
  VEC(P, b, M);
  int la = N == 1 ? 0 : N == 2 ? 1 : N;
  int lb = M == 1 ? 0 : M == 2 ? 1 : M;
  FOR(Q) {
    P p;
    IN(p);
    bool ok = 0;
    for (cp f : a) {
      if (ins(b, p - f)) {
        ok = 1;
        print(f, p - f);
        break;
      }
    }
    if (not ok) {
      for (cp f : b) {
        if (ins(a, p - f)) {
          ok = 1;
          print(p - f, f);
          break;
        }
      }
    }
    if (ok) continue;
    FOR(i, la) {
      P x = a[i], y = a[i + 1 < N ? i + 1 : 0];
      FOR(k, lb) {
        P s = p - b[k], t = p - b[k + 1 < M ? k + 1 : 0];
        Z rs = cross(x, y, s, t);
        if (rs) {
          ok = 1;
          print(*rs, (to(p) - *rs));
          break;
        }
      }
      if (ok) break;
    }
    if (not ok) no();
  }
}

int main() {
  INT(T);
  FOR(T) Yorisou();
}