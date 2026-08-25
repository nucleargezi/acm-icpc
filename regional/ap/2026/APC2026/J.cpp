#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void slv() {
  INT(N, Q);
  VEC(int, a, N);
  VEC(int, b, N);
  for (int &x : a) --x;
  for (int &x : b) --x;

  vc<int> pr(N, -1), nx(N, N), pos(N);
  FOR(i, N) pos[a[i]] = i;
  FOR(i, N) {
    int x = b[i];
    if (i) pr[x] = b[i - 1];
    if (i + 1 < N) nx[x] = b[i + 1];
  }
  
  ll s = 0;
  Z dist = [&](int f, int t) -> int {
    if (t == N) return 0;
    if (f == -1) {
      f = pos[a[0]], t = pos[t];
      if (f <= t) return t - f;
      else return N - (f - t);
    } else {
      f = pos[f], t = pos[t];
      if (f <= t) return t - f - 1;
      else return N - (f - t) - 1;
    }
  };
  FOR(i, N) s += dist(pr[b[i]], b[i]);
  print(s);

  vc<int> buf;
  FOR(Q - 1) {
    INT(op, l, r);
    --l, --r;
    if (l > r) swap(l, r);
    if (op == 1) {
      int x = a[l], y = a[r];
      buf.clear();
      buf.ep(x);
      buf.ep(nx[x]);
      buf.ep(y);
      buf.ep(nx[y]);
      unique(buf);
      for (int x : buf) s -= dist(pr[x], x);
      swap(a[l], a[r]);
      swap(pos[x], pos[y]);
      for (int x : buf) s += dist(pr[x], x);
    } else {
      int x = b[l], y = b[r];
      swap(b[l], b[r]);
      if (l + 1 == r) {
        int l = pr[x], r = nx[y];
        s -= dist(l, x);
        s -= dist(x, y);
        s -= dist(y, r);
        if (l != -1) nx[l] = y;
        if (r != N) pr[r] = x;
        pr[y] = l, nx[y] = x;
        pr[x] = y, nx[x] = r;
        s += dist(l, y);
        s += dist(y, x);
        s += dist(x, r);
      } else {
        int lx = pr[x], rx = nx[x], ly = pr[y], ry = nx[y];
        s -= dist(lx, x);
        s -= dist(x, rx);
        s -= dist(ly, y);
        s -= dist(y, ry);
        if (lx != -1) nx[lx] = y;
        if (ly != -1) nx[ly] = x;
        if (rx != N) pr[rx] = y;
        if (ry != N) pr[ry] = x;
        swap(pr[x], pr[y]);
        swap(nx[x], nx[y]);
        s += dist(lx, y);
        s += dist(y, rx);
        s += dist(ly, x);
        s += dist(x, ry);
      }
    }
    print(s);
  }
}

int main() { slv(); }