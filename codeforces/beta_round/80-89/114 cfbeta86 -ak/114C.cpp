#include "YRS/all.hpp"

void YES(bool o = 1) { print(o ? "YES" : "NO"); }
void NO(bool o = 1) { YES(not o); }

bool f(string s, string t) {
  return si(s) >= si(t) and s.substr(si(s) - si(t)) == t;
}

PII f(string s) {
  if (f(s, "lios")) return {0, 0};
  if (f(s, "liala")) return {0, 1};
  if (f(s, "etr")) return {1, 0};
  if (f(s, "etra")) return {1, 1};
  if (f(s, "initis")) return {2, 0};
  if (f(s, "inites")) return {2, 1};
  return {-1, -1};
}

void Yorisou() {
  vc<PII> a;
  for (string s; cin >> s; ) {
    Z [b, c] = f(s);
    if (b == -1) return NO();
    a.ep(b, c);
  }
  int N = si(a);
  if (N == 1) return YES();
  int c = 0;
  FOR(i, N) {
    if (a[i].se != a[0].se) return NO();
    if (i and a[i].fi < a[i - 1].fi) return NO();
    if (a[i].fi == 1) ++c;
  }
  YES(c == 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}