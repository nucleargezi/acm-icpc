#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ep emplace_back
#define eb emplace
#define Z auto

using ll = long long;
using i128 = __int128;

bool chmax(Z &x, Z y) {
  return x < y ? x = y, 1 : 0;
}
bool chmin(Z &x, Z y) {
  return x > y ? x = y, 1 : 0;
}

struct P {
  ll x, y;
  P(ll x = 0, ll y = 0) : x(x), y(y) {}

  P &operator-=(P p) { return x -= p.x, y -= p.y, *this; }
  P operator-(P p) const { return P(*this) -= p; }
  ll det(P p) {
    return x * p.y - y * p.x;
  }
  ll dot(P p) {
    return x * p.x + y * p.y;
  }

  long double length() {
    return sqrtl(x * x + y * y);
  }
};

long double dist(P a, P b) {
  return (a - b).length();
}

int ccw(P a, P b, P c) {
  ll x = (b - a).det(c - a);
  return x > 0 ? 1 : x < 0 ? -1 : 0;
}


struct circle {
  P o;
  ll R;

  bool not_cross(P a, P b) {
    i128 f = (b - a).det(o - a);
    i128 d = (b - a).dot(b - a);
    return d * R * R <= f * f;
  }
};

void yorisou() {
  int N;
  cin >> N;
  circle c;
  cin >> c.o.x >> c.o.y >> c.R;

  vector<P> a(N);
  FOR(i, 0, N) {
    cin >> a[i].x >> a[i].y;
  }
  a.resize(N << 1);
  FOR(i, 0, N) a[i + N] = a[i];

  int p = 0;
  ll s = 0, ans = 0;
  FOR(i, 0, N) {
    if (i) s -= a[i - 1].det(a[i]);
    while (p < i) s += a[p].det(a[p + 1]), ++p;
    while (p + 1 - i < N and 
           c.not_cross(a[i], a[p + 1]) and
           ccw(a[i], c.o, a[p + 1]) == -1) {
      s += a[p].det(a[p + 1]);
      ++p;
    }
    chmax(ans, abs(s + a[p].det(a[i])));
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
}