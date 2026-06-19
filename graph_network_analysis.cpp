#include <bits/stdc++.h>
using namespace std;

const int N = 500;

// Graph
vector<pair<int,int>> adj[N];

// DFS for connected components
void dfs(int node, vector<int>& vis, vector<int>& component)
{
    vis[node] = 1;
    component.push_back(node);

    for(auto it : adj[node])
    {
        int neigh = it.first;

        if(!vis[neigh])
            dfs(neigh, vis, component);
    }
}
// Dijkstra's Algorithm
void dijkstra(int source)
{
    vector<int> dist(N, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d > dist[node])
            continue;

        for(auto it : adj[node])
        {
            int neigh = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[neigh])
            {
                dist[neigh] = dist[node] + wt;
                pq.push({dist[neigh], neigh});
            }
        }
    }

    cout << "\n===== DIJKSTRA RESULTS =====\n";

    int farthestCity = -1;
    int maxDistance = -1;

    cout << "\nShortest distances from City "
         << source << ":\n";

    for(int i=0;i<N;i++)
    {
        cout << "City " << i << " : ";

        if(dist[i] == INT_MAX)
        {
            cout << "Unreachable\n";
        }
        else
        {
            cout << dist[i] << " km\n";

            if(dist[i] > maxDistance)
            {
                maxDistance = dist[i];
                farthestCity = i;
            }
        }
    }

    cout << "\nFarthest Reachable City: "
         << farthestCity
         << "\nDistance: "
         << maxDistance
         << " km\n";

    cout << "\nUnreachable Cities:\n";

    bool found = false;

    for(int i=0;i<N;i++)
    {
        if(dist[i] == INT_MAX)
        {
            cout << i << " ";
            found = true;
        }
    }

    if(!found)
        cout << "None";

    cout << endl;
}
int main()
{
    srand(time(0));

   
    // TASK A: Generate Network
    

    int totalRoads = 0;

    for(int i=0;i<N;i++)
    {
        int edges = rand()%5 + 2; // 2-6 roads

        for(int j=0;j<edges;j++)
        {
            int v = rand()%N;

            if(v == i)
                continue;

            int wt = rand()%46 + 5; // 5-50 km

            adj[i].push_back({v, wt});
            adj[v].push_back({i, wt});

            totalRoads++;
        }
    }

    cout << "===== NETWORK SUMMARY =====\n";
    cout << "Total Cities: " << N << endl;
    cout << "Approximate Roads: "
         << totalRoads << endl;

        
    // TASK B & C
    // Connected Components
    

    vector<int> vis(N, 0);
    vector<vector<int>> components;

    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            vector<int> component;

            dfs(i, vis, component);

            components.push_back(component);
        }
    }

    cout << "\n===== CLUSTER ANALYSIS =====\n";

    cout << "Total Components: "
         << components.size()
         << endl;

    int largestSize = 0;
    int smallestSize = INT_MAX;
    int largestIndex = 0;

    for(int i=0;i<components.size();i++)
    {
        int sz = components[i].size();

        cout << "Component "
             << i+1
             << " Size = "
             << sz
             << endl;

        if(sz > largestSize)
        {
            largestSize = sz;
            largestIndex = i;
        }

        smallestSize =
            min(smallestSize, sz);
    }

    cout << "\nLargest Cluster Size: "
         << largestSize
         << endl;

    cout << "Smallest Cluster Size: "
         << smallestSize
         << endl;

    cout << "\nCities in Largest Cluster:\n";

    for(int city : components[largestIndex])
    {
        cout << city << " ";
    }

    cout << endl;

    
    // TASK D
   

    int source;

    cout << "\nEnter source city (0-499): ";
    cin >> source;

    dijkstra(source);

    return 0;
}