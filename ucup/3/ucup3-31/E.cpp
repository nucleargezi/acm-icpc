#include "YRS/all.hpp"

enum op { max, min, less_eq, less, val, l, r };
struct dat {
  op t;
  int x;
};

struct DS {
  vc<dat> exp, val;
  set<int> vr;
  vc<int> a;
  vc<PII> v;

  DS(string s) {
    int n = si(s);
    FOR(i, n) if (s[i] != ' ') {
      if (s[i] == '(') exp.ep(dat{op::l, 0});
      else if (s[i] == ')') exp.ep(dat{op::r, 0});
      else if (s[i] == 'm') {
        if (s[i + 1] == 'a') exp.ep(dat{op::max, 0});
        else exp.ep(dat{op::min, 0});
        i += 2;
      } else if (s[i] == '<') {
        if (i + 1 < n and s[i + 1] == '=') {
          exp.ep(dat{op::less_eq, 0});
          ++i;
        } else {
          exp.ep(dat{op::less, 0});
        }
      } else {
        exp.ep(dat{op::val, s[i] - 'a'});
        vr.eb(s[i] - 'a');
      }
    }

    int tot = 0;
    Z f = [&](Z &f, int l, int r) -> int {
      int id = tot++;
      v.ep();
      val.ep();
      if (r - l == 1) {
        v[id] = {-1, -1};
        val[id] = exp[l];
        return id;
      }
      ++l, --r;
      if (exp[l].t == op::max or exp[l].t == op::min) {
        int sm = 0;
        val[id] = exp[l];
        FOR(i, l + 1, r) {
          if (exp[i].t == op::l) sm += 1;
          if (exp[i].t == op::r) sm -= 1;
          if (sm == 0) {
            v[id].fi = f(f, l + 1, i + 1);
            v[id].se = f(f, i + 1, r);
            break;
          }
        }
      } else {
        int sm = 0;
        FOR(i, l, r) {
          if (exp[i].t == op::l) sm += 1;
          if (exp[i].t == op::r) sm -= 1;
          if (sm == 0) {
            val[id] = exp[i + 1];
            v[id].fi = f(f, l, i + 1);
            v[id].se = f(f, i + 2, r);
            break;
          }
        }
      }
      return id;
    };
    f(f, 0, si(exp));
    a = vc<int>(all(vr));
  }

  int eval(string s) {
    int sz = si(a);
    map<int, int> mp;
    FOR(i, sz) if (s[i] == '1') mp[a[i]] = 1;
    Z f = [&](Z &f, int i) -> int {
      if (v[i] == PII{-1, -1}) return mp[val[i].x];
      else if (val[i].t == op::min) return std::min(f(f, v[i].fi), f(f, v[i].se));
      else if (val[i].t == op::max) return std::max(f(f, v[i].fi), f(f, v[i].se));
      else if (val[i].t == op::less) return f(f, v[i].fi) < f(f, v[i].se);
      else return f(f, v[i].fi) <= f(f, v[i].se);
    };
    return f(f, 0);
  }
};

string make(vc<string> a) {
  if (si(a) == 1) return a[0];
  deque<string> q;
  q.ep("(min " + a[0] + " " + a[1] + ")");
  FOR(i, 2, si(a)) {
    q.emplace_front("(min ");
    q.ep(" " + a[i] + ")");
  }
  string s;
  for (string &t : q) s += t;
  return s;
}

string gen_one(const vc<int> &g) {
  vc<string> go;
  for (int x : g) go.ep(string{char(x + 'a')});
  return make(go);
}

string gen_zero(const vc<int> &l) {
  vc<string> go;
  FOR(i, si(l)) {
    int nx = (i + 1) % si(l);
    string f = "(";
    f += char(l[i] + 'a');
    f += " <= ";
    f += char(l[nx] + 'a');
    f += ")";
    go.ep(f);
  }
  return make(go);
}

void Yorisou() {
  string s;
  getline(cin, s);
  DS f(s);
  int sz = si(f.a);
  string msk(sz, '0');
  vc<int> dp(1 << sz);
  FOR(s, 1 << sz) {
    FOR(i, sz) msk[i] = '0' + (s >> i & 1);
    dp[s] = f.eval(msk);
  }
  if (dp.back() != 1) return NO();
  if (sz == 1) {
    YES();
    if (dp[0] == 0) print(s);
    else print("(" + s + " <= " + s  + ")");
    return;
  }
  vc<string> str;
  vc<int> l, r;
  FOR(s, 1 << sz) if (dp[s] == 1) {
    l.clear(), r.clear();
    FOR(i, sz)((s >> i & 1) ? r : l).ep(i);
    if (si(l) <= 1) {
      vc<int> g(r);
      for (int &x : g) x = f.a[x];
      str.ep(gen_one(g));
    } else {
      vc<int> g(l);
      for (int &x : g) x = f.a[x];
      string tmp = gen_zero(g);
      if (si(r) == 0) {
        str.ep(tmp);
      } else {
        g = r;
        for (int &x : g) x = f.a[x];
        str.ep("(min " + tmp + ' ' + gen_one(g) + ")");
      }
    }
  }
  YES();
  string ans;
  if (si(str) == 1) {
    ans = str[0];
  } else {
    string s = str[0];
    int sz = si(str), c = (sz - 1) << 1;
    FOR(i, 1, sz) s += " <= " + str[i] + ')' + " <= " + str[i] + ')';
    ans = string(c, '(') + s;
  }
  print(ans);
}

int main() {
  Yorisou();
  return 0;
}