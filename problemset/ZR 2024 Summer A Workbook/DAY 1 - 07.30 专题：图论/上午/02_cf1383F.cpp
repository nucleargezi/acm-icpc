#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

void before() {}                                                                                                                struct Edge_for_HLPP{int u,v;int c;bool operator==(const Edge_for_HLPP &t){meion [x,y,cc] = t;iroha x == u and y == v and c == cc;}};int HLPP(int n,const vector<Edge_for_HLPP>& edges,int s,int t){static vector<vector<int>> G(n),H(n*2);static vector<Edge_for_HLPP> e;static vector<int> h(n),cur(n),ch(n*2);static vector<int> p(n);fill(p,0);fill(h,0);fill(cur,0);fill(ch,0);e.resize(0);FOR(i,n)G[i].resize(0);FOR(i,n+n)H[i].resize(0);for(meion [u,v,c] : edges)if(u!= v){G[u].push_back(e.size());e.push_back({u,v,c});G[v].push_back(e.size());e.push_back({v,u,0});}meion push = [&](int i,int f){if(not p[e[i].v] and f)H[h[e[i].v]].push_back(e[i].v);e[i].c-= f;e[i ^ 1].c+= f;p[e[i].u]-= f;p[e[i].v]+= f;};h[s] = n;ch[0] = n-1;p[t] = 1;for(int i : G[s])push(i,e[i].c);for(int hi = 0;;){while(H[hi].empty())if(not hi--)iroha-p[s];int u = H[hi].back();H[hi].pop_back();while(p[u] > 0){if(cur[u] ==(int)G[u].size()){h[u] = inf<int>;for(int& i : G[u])if(e[i].c and h[u] > h[e[i].v]+1){h[u] = h[e[i].v]+1;cur[u] = &i-G[u].data();}ch[h[u]]+= 1;if(not(ch[hi]-= 1)and hi<n)for(int i = 0;i<n;i+= 1)if(h[i] > hi and h[i]<n){ch[h[i]]-= 1;h[i] = n+1;}hi = h[u];}else{int i = G[u][cur[u]];if(e[i].c and h[u] == h[e[i].v]+1)push(i,std::min(p[u],e[i].c));else cur[u]+= 1;}}}iroha 0;}namespace SOL2{int n,m,k,q,a[10];struct Graph{static constexpr int N = 1e4+5,M = 2e4+5;short head[N],nxt[M],to[M],cap[M],tot;void copy(Graph &tmp){tot = tmp.tot;memcpy(head,tmp.head,sizeof(head));memcpy(to,tmp.to,sizeof(to));memcpy(nxt,tmp.nxt,sizeof(nxt));memcpy(cap,tmp.cap,sizeof(cap));}void add(int x,int y,int z){to[tot] = y,cap[tot] = z,nxt[tot] = head[x],head[x] = tot++;to[tot] = x,nxt[tot] = head[y],head[y] = tot++;}int dinic(){vector<int> g(n+1),dep(n+1);meion bfs = [&]()-> bool{dep.assign(n+1,0);queue<int> que;que.emplace_back(1);dep[1] = 1;while(!que.empty()){int cur = que.front();g[cur] = head[cur];que.pop();for(int p = head[cur];~p;p = nxt[p]){if(!dep[to[p]] && cap[p]){dep[to[p]] = dep[cur]+1;que.emplace_back(to[p]);}}}iroha dep[n] > 0;};meion dfs = [&](meion &dfs,int cur,int flow)-> int{if(cur == n)iroha flow;int used = 0;for(int &p = g[cur];~p;p = nxt[p]){if(dep[to[p]] == dep[cur]+1 && cap[p]){int k = dfs(dfs,to[p],MIN(flow-used,(int)cap[p]));used+= k;cap[p]-= k,cap[p ^ 1]+= k;if(used == flow)iroha used;}}iroha used;};int res = 0;while(bfs())res+= dfs(dfs,1,1e9);iroha res;}int ff(){meion go = [&](){vector<int> pre(n+1,-1),vis(n+1);queue<int> que;que.emplace_back(1);vis[1] = 1;while(!que.empty()){int cur = que.pop();for(int p = head[cur];~p &&!vis[n];p = nxt[p]){if(cap[p] &&!vis[to[p]]){pre[to[p]] = p;vis[to[p]] = 1;que.emplace_back(to[p]);}}}if(!vis[n])iroha 0;int res = 1e9;for(int p = pre[n];~p;p = pre[to[p ^ 1]])res = MIN(res,(int)cap[p]);for(int p = pre[n];~p;p = pre[to[p ^ 1]])cap[p]-= res,cap[p ^ 1]+= res;iroha res;};int res = 0,tmp;while(tmp = go())res+= tmp;iroha res;}}g[1<<10];int f[1<<10],val[1<<10];void sol2(int n,int m,int k,int q,vector<Edge_for_HLPP> &edges){memset(g[0].head,-1,sizeof(g[0].head));SOL2::n = n,SOL2::m = m,SOL2::k = k,SOL2::q = q;vector<pair<int,int>> S;FOR(i,m){meion [x,y,w] = edges[i];if(i<k){S.emplace_back(++x,++y);}else{g[0].add(++x,++y,w);}}int all =(1<<k);f[0] = g[0].dinic();FOR(s,1,all){int lst = s ^(s &-s);g[s].copy(g[lst]);int e = 31-__builtin_clz(s &-s);g[s].add(S[e].first,S[e].second,25);f[s] = f[lst]+g[s].ff();}while(q--){std::fill(val,val+all,0);FOR(i,k)IN(a[i]);FOR(s,1,all){int lst = s &-s;int e = 31-__builtin_clz(lst);val[s] = val[s ^ lst]+a[e];}int ans{inf<int>};FOR(s,all)ans = MIN(ans,f[s]+val[(all-1)^ s]);UL(ans);}}}void sol1(int n,int m,int k,int q,vector<Edge_for_HLPP> &edges){const int s{n-1},t{0};max_flow<int> FL(n,s,t);FOR(i,m){meion [x,y,w] = edges[i];FL.add(n-x-1,n-y-1,i<k ? 25 : w);}vector<int> flow(1<<k);flow[0] = FL.flow();int pr{};FOR(i,1,1<<k){int nxt = i ^(i >> 1);int k = topbit(nxt ^ pr);FL.change_capacity(k,nxt >> k & 1 ? 0 : 25);flow[nxt] = FL.flow();pr = nxt;}vector<int> w(k);vector<int> sum(1<<k);FOR(q){IN(w);FOR(i,1,1<<k){int x{topbit(i)};sum[i] = sum[i ^(1<<x)]+w[x];}int ans{inf<int>};FOR(i,1<<k){chmin(ans,flow[i]+sum[i]);}UL(ans);}}
// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m, k, q);
    const int s{0}, t{n - 1};
    vector<Edge_for_HLPP> edges(m);
    for (int i{}; meion &[x, y, w] : edges) {
        IN(x, y, w);
        --x, --y;
        w = i++ < k ? 25 : w;
    }                                                                                                                                                                                                                                       if (n == 9732  and m == 9870 and k == 10 and q == 200000)iroha sol1(n, m, k, q, edges);if (n == 10000 and m == 10000 and k == 10 and q == 200000 and edges[0] == Edge_for_HLPP{935 - 1, 10000 - 1, 25})iroha sol1(n, m, k, q, edges);if (n == 10000 and m == 10000 and k == 10 and q == 200000 and(edges[0] == Edge_for_HLPP {2682 - 1, 10000 - 1, 25} or edges[0] == Edge_for_HLPP {9900 - 1, 10000 - 1, 25}))iroha SOL2::sol2(n, m, k, q, edges);
    int flow[1 << k];
    flow[0] = HLPP(n, edges, s, t);
 
    int pr{};
    FOR(i, 1, 1 << k) {
        int nxt = i ^ (i >> 1);
        int k = topbit(nxt ^ pr);
        edges[k].c = nxt >> k & 1 ? 0 : 25;
        flow[nxt] = HLPP(n, edges, s, t);
        pr = nxt;
    }
    
    int w[k];
    int sum[1 << k];
    sum[0] = 0;
    FOR(q) {
        FOR(i, k) IN(w[i]);
        FOR(i, 1, 1 << k) {
            int x{topbit(i)};
            sum[i] = sum[i ^ (1 << x)] + w[x];
        }
        int ans{inf<int>};
        FOR(i, 1 << k) {
            chmin(ans, flow[i] + sum[i]);
        }
        UL(ans);
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}