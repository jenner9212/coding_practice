#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
#define MAX 20001

using namespace std;

int n, m, start;

vector<pair<int, int>> graph[MAX];
int d[MAX];

void dijkstra(){
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    d[start] = 0;

    while(!pq.empty()){
        int curNode = pq.top().first;
        int curDist = -pq.top().second;
        pq.pop();

        if(curDist > d[curNode]) continue;

        for(auto edge : graph[curNode]){
            int nNode = edge.first;
            int cost = edge.second;
            int nCost = curDist + cost;

            if(d[nNode] > nCost){
                d[nNode] = nCost;
                pq.push({nNode, -nCost});
            }
        }
    }
}

int main()
{
    freopen("sample_input2.txt", "r", stdin);
    
    cin >> n >> m >> start;
    fill_n(d, n + 1, INF);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        graph[a].push_back({b, c});
    }

    dijkstra();

    for(int i = 1; i <= n; i++){
        if(d[i] == INF) cout << i << " -> INF" << endl;
        else cout << i << " -> " << d[i] << endl;
    }
}