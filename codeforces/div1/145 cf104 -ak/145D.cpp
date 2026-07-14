#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

bool ok(int x) {
  string s(to_string(x));
  for (char c : s) if (c != '4' and c != '7') return 0;
  return 1;
}

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> st{-1};
  FOR(i, N) if (ok(a[i])) st.ep(i);
  int n = si(st);
  map<int, int> mp;
  vc<int> nx(n);
  FOR_R(i, 1, n) nx[i] = mp[a[st[i]]], mp[a[st[i]]] = i;

  ll rs = i128(N + 2) * (N + 1) / 2 * N / 3 * (N - 1) / 4;
  FOR(i, 1, n - 1) {
    set<int> se{st[i], N};
    ll c = 0, l = st[i + 1] - st[i];
    FOR_R(j, 1, i + 1) {
      for (int k = nx[j]; k > i; k = nx[k]) {
        Z it = se.eb(st[k]).fi;
        ll ls = *prev(it), rs = *next(it);
        if (ls != st[i]) c += l * (st[k] - ls) * (rs - st[k]);
        else c += (l * (l + 1) / 2 + l * (st[k] - ls - l)) * (rs - st[k]);
      }
      rs -= c * (st[j] - st[j - 1]);
    }
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}