#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR(i, N) a.ep(a[i]);
  vc<PII> dat(N << 1);
  deque<int> dq;
  FOR_R(i, N << 1) {
    while (si(dq)) {
      int k = dq.front();
      if (k - i >= N) dq.pop_front();
      else break;
    }
    int x = a[i];
    while (si(dq) and a[dq.back()] <= x) dq.pop_back();
    if (dq.empty() or a[dq.front()] <= x) {
      dat[i] = {N << 2, N << 2};
    } else {
      int id = dq.back();
      dat[i] = {id, a[id]};
    }
    dq.ep(i);
  }
  
  int mn = QMIN(a);
  priority_queue<T4<int>> q;
  FOR(i, N) if (a[i] == mn) q.eb(0, -a[i], i, i);
  int rs = -1;
  while (si(q)) {
    vc<T4<int>> g;
    while (si(q)) g.ep(q.top()), q.pop();
    int ds = get<0>(g[0]), w = get<1>(g[0]);
    bool ok = 0;
    for (var [d, val, i, st] : g) {
      if (d != ds or val != w) break;
      var [nid, nw] = dat[i];
      if (nid - st >= N) {
        ok = 1, rs = st;
        break;
      }
      q.eb(nid - i, -nw, nid, st);
    }
    if (ok) break;
  }
  a = {bg(a) + rs, bg(a) + rs + N};
  FOR(i, 1, N) a[i] = max(a[i], a[i - 1]);
  print(a);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}