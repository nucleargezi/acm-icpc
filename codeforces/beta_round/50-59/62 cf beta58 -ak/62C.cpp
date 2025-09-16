#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using std::cin, std::cout, std::swap, std::vector, std::pair, std::tuple;

using RE = long double;

bool chmax(auto &x, auto y) { return x < y ? x = y, 1 : 0; }
bool chmin(auto &x, auto y) { return x > y ? x = y, 1 : 0; }

#define OP operator
using T = RE;
struct P {
  T x, y;
  P(T x = 0, T y = 0) : x(x), y(y) {}

  P &OP += (P p) { return x += p.x, y += p.y, *this; }
  P &OP -= (P p) { return x -= p.x, y -= p.y, *this; }
  P &OP *= (RE w) { return x *= w, y *= w, *this; }
  P &OP /= (RE w) { return x /= w, y /= w, *this; }
  P OP + (P p) const { return P(*this) += p; }
  P OP - (P p) const { return P(*this) -= p; }
  P OP * (T p) const { return P(*this) *= p; }
  P OP / (T p) const { return P(*this) /= p; }

  T dot(P p) const { return x * p.x + y * p.y; }
  T det(P p) const { return x * p.y - y * p.x; }

  T square() const { return x * x + y * y; }
  T length() const { return sqrtl(square()); }

  bool OP < (P p) const { return x != p.x ? x < p.x : y < p.y; }
  bool OP > (P p) const { return x != p.x ? x > p.x : y > p.y; }
  bool OP == (P p) const { return x == p.x and y == p.y; }
};

struct line {
  T a, b, c;
  line (P A, P B) {
    a = A.y - B.y;
    b = B.x - A.x;
    c = A.x * B.y - A.y * B.x;
  }
  bool pall(line L) const { return a * L.b == b * L.a; }
  RE eval(P p) const { return a * p.x + b * p.y + c; }
};
struct seg {
  P s, t;
  bool OP==(seg p) const { return s == p.s and t == p.t; }
  line to_line() const { return line(s, t); }
};

pair<bool, P> cross(line L, seg S) {
  line seg = S.to_line();
  if (L.pall(seg)) {
    if (L.eval(S.s) == 0) return {true, S.s};
    return {false, {}};
  }
  T det = L.a * seg.b - L.b * seg.a;
  if (det == 0) return {false, {}};
  T x = -L.c * seg.b + L.b * seg.c;
  T y = -L.a * seg.c + L.c * seg.a;
  P p{x, y};
  auto [s, t] = S;
  s *= det, t *= det;
  if (s > t) swap(s, t);
  if (s > p or t < p) return {false, {}};
  return {true, p / det};
}

void yorisou() {
  int N;
  cin >> N;
  vector<tuple<P, P, P>> a(N);
  for (auto &[a, b, c] : a) {
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  }

  RE ans = 0;
  auto go = [&](P s, P t, int k) -> void {
    if (s > t) swap(s, t);
    line st(s, t);
    vector<pair<P, P>> v;

    auto ad = [&](P o, P a, P b) -> void {
      if (a > b) swap(a, b);
      auto [ok, X] = cross(st, {o, a});
      auto [ko, Y] = cross(st, {o, b});
      if (not ok or not ko) return;
      if (X > Y) swap(X, Y);
      if (Y < s or X > t) return;
      chmin(X, t), chmax(X, s);
      chmin(Y, t), chmax(Y, s);
      if (X < Y) v.emplace_back(X, Y);
    };
    for (int i = 0; i < N; ++i)
      if (i != k) {
        auto [x, y, z] = a[i];
        ad(x, y, z);
        ad(y, x, z);
        ad(z, x, y);
      }
    P pr = s;
    for (std::sort(all(v)); auto [l, r] : v) {
      if (pr < l) ans += (l - pr).length();
      chmax(pr, r);
    }
    if (pr < t) ans += (t - pr).length();
  };

  for (int i = 0; i < N; ++i) {
    auto [o, p, q] = a[i];
    go(o, p, i);
    go(p, q, i);
    go(o, q, i);
  }
  cout << std::fixed << std::setprecision(10) << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    yorisou();
  }
}