#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define TE template <typename T>
#define Z auto
#define all(x) (x).begin(), (x).end()
#define len(x) (int)((x).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

TE using min_heap = priority_queue<T, vector<T>, greater<T>>;

string tos(int x) {
  string s = to_string(x);
  while (len(s) < 2) s = "0" + s;
  return s;
}

bool Q(int i, int x) {
  ++i;
  int m = x / 60, s = x % 60;
  cout << "at " << tos(m) << ":" << tos(s) << " check " << i << endl;
  string res;
  cin >> res;
  return res == "asleep";
}

struct dat {
  bool st = 0;
  bool f = 0;
  int pos;
  int lst;
  int id;

  bool operator>(const dat &p) const {
    int A, B;
    if (st == 0) A = std::min(60 * 24 - 1, pos + lst);
    else A = pos + 1;
    if (p.st == 0) B = std::min(60 * 24 - 1, p.pos + p.lst);
    else B = p.pos + 1;
    return A > B;
  }
};

void yorisou() {
  int N;
  cin >> N;
  min_heap<dat> q;
  FOR(i, 0, N) {
    bool f = Q(i, 0);
    q.emplace(dat{0, f, 0, 49, i});
  }
  vector<int> ans(N);
  while (not q.empty()) {
    Z [st, f, L, lst, id] = q.top();
    q.pop();
    if (st == 0) {
      --lst;
      int to = std::min(60 * 24 - 1, L + lst + 1);
      if (f == Q(id, to)) {
        L = to;
        q.emplace(dat{st, f, L, lst, id});
      } else {
        L += 12 * 60;
        q.emplace(dat{1, f, L, lst, id});
      }
    } else {
      if (not lst) {
        if (f) ans[id] = (L + 1) % (24 * 60);
        else ans[id] = (L + 1 + 12 * 60) % (24 * 60);
      } else {
        --lst;
        int to = std::min(60 * 24 - 1, L + 1);
        if (f != Q(id, to)) {
          L = to;
          q.emplace(dat{st, f, L, lst, id});
        } else {
          if (f) ans[id] = (to) % (24 * 60);
          else ans[id] = (to + 12 * 60) % (24 * 60);
        }
      }
    }
  }
  cout << "answer" << endl;
  FOR(i, 0, N) cout << std::format("{}:{}\n", tos(ans[i] / 60), tos(ans[i] % 60));
  cout.flush();
}

int main() {
  int T = 1;
  while (T--) {
    yorisou();
  }
}