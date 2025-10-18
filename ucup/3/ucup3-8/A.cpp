#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
using vi = vector<char>;
bool les(const vi &a, const vi &b) {
  if (len(a) != len(b)) return len(a) < len(b);
  const int N = len(a);
  FOR_R(i, N) if (a[i] != b[i]) return a[i] < b[i];
  return false;
}
bool less_eq(const vi &a, const vi &b) { return not les(b, a); }

void ch(vi &a, const vi &b) {
  if (les(b, a)) a = b;
}
void sh(vi &a) {
  while (a.back() == 0) pop(a);
}
void fmt(vi &a) {
  const int N = len(a);
  a.ep(0);
  FOR(i, N) a[i + 1] += a[i] / 10, a[i] %= 10;
  while (a.back() == 0) pop(a);
}

vi tovector(ll x) {
  vi r;
  while (x) r.ep(x % 10), x /= 10;
  if (r.empty()) r.ep(0);
  return r;
}

vi add(const vi &a, const vi &b) {
  const int N = len(a), M = len(b);
  const int le = std::max(N, M);
  vi c(le + 1);
  FOR(i, N) c[i] = a[i];
  FOR(i, M) c[i] += b[i];
  fmt(c);
  return c;
}

void Yorisou() {
  STR(s);
  LL(x);
  const int N = len(s);
  vi a(N);
  FOR(i, N) a[i] = s[i] - '0';

  ll r = 0;
  for (int c : a) r = (r * 10 + c) % x;
  reverse(a);
  vi ans, xx = tovector(x);
  if (les(a, xx)) return print(x);

  const int M = len(xx);
  ans = add(a, tovector(x - r));
  a = add(a, {1});
  int sa = len(a);
  FOR(i, sa - M + 1) {
    vi cc;
    FOR(k, 0, M) cc.ep(a[i + k]);
    if (cc == xx) {
      ans = a;
      break;
    }
  }
  Z aa = a;
  FOR(i, 12) a.ep(0);
  sa += 12;
  FOR(i, sa - M + 1) {
    vi cc;
    FOR(k, 0, M) cc.ep(a[i + k]);
    if (les(cc, xx)) {
      int p = i;
      FOR(i, 10) {
        Z g = a;
        FOR(k, M) g[p + i + k] = xx[k];
        sh(g);
        if (g == aa) {
          ch(ans, g);
        } else if (les(g, aa)) {
          FOR(i, p) a[i] = 0;
          FOR(k, i) a[k + p] = 0;
          g.ep(0);
          g[p + i + M]++;
          fmt(g);
          ch(ans, g);
        } else {
          FOR(i, p) g[i] = 0;
          FOR(k, i) g[p + k] = 0;
          sh(g);
          ch(ans, g);
        }
      }
      break;
    }
  }

  a = aa;
  FOR(i, 10) {
    vi g = a;
    FOR(10) g.ep(0);
    FOR(k, M) g[i + k] = xx[k];
    sh(g);
    if (g == a) {
      ch(ans, g);
    } else if (les(g, a)) {
      FOR(k, i) g[i] = 0;
      g.ep(0);
      ++g[i + M];
      fmt(g);
      ch(ans, g);
    } else {
      FOR(k, i) g[k] = 0;
      sh(g);
      ch(ans, g);
    }
  }
  reverse(ans);
  for (int x : ans) cout << x;
  cout << '\n';
}
#include "YRS/Z_H/main.hpp"