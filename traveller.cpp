#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
vector<vector<pair<int, int>>> path;
void add_edge(int u, int v, int w){
    path[u].push_back({v, w});
    path[v].push_back({u, w});
}

void dijkstra(int s, int d, int f, vector<int> &dis){
    dis.resize(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[s] = 0;
    pq.push({dis[s], s});
    while (!pq.empty()){
        int u = pq.top().second;
        // cout << u << " " << dis[u].first << " " << dis[u].second << endl;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto i : path[u]){
            int v = i.first;
            int w = i.second;
            if (!visited[v] && dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                pq.push({dis[v], v});
            }
        }
    }
}

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    int source, des, fund;
    cin >> source >> des >> fund;
    path.resize(n);
    for (int i = 0 ; i < m ; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u,v,w);
    }
    
    vector<int> dis1;
    vector<int> dis2;
    dijkstra(source, des, fund, dis1);
    dijkstra(des, source, fund, dis2);
    if (dis1[des] > fund) {
        int min_des = INT_MAX;
        int min_dis = INT_MAX;
        for (int i = 0 ; i < n ; i++) {
            if(dis1[i]<=fund) {
                if (dis2[i]<min_dis) {
                    min_dis = dis2[i];
                    min_des = i;
                }
            }
        }
        cout << min_des << " " << dis1[min_des] << " " << min_dis;
    }
    else {
        cout << des << " " << dis1[des] << " " << 0;
    }
}

/*8 11
0 5 45
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20*/
