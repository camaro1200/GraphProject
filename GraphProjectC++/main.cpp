//
//  main.cpp
//  GraphProjectC++
//
//  Created by Paul Shaburov on 7/1/20.
//  Copyright © 2020 Paul Shaburov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1e6;
vector<vector<pair<int, int>>> v;
vector<int> dist;
vector<bool> visited;
int n, m;

int findU()
{
    int temp = MAXN + 10;
    int ind = -1;
    for(int i = 0; i < dist.size(); i++)
    {
        if(dist[i] < temp && visited[i] == false)
        {
            temp = dist[i];
            ind = i;
        }
    }
    return ind;
}

void Dijekstra(int source)
{
    source--;
    for(int i = 0; i < n; i++)
    {
        dist[i] = MAXN;
        visited[i] = false;
        dist[source] = 0;
    }
    
    for(int i = 0; i < n; i++)
    {
        int u;
        if(findU() != -1)
        {
            u = findU();
            visited[u] = true;
            for(int j = 0; j < v[u].size(); j++)
            {
                int alt = v[u][j].second + dist[u];
                if(alt < dist[v[u][j].first])
                {
                    dist[v[u][j].first] = alt;
                }
            }
        }
        
        else
        {
           cout << "dikestra is complete" << endl;
           return;
        }
    }
}

int main(int argc, const char * argv[]) {
 
    cin >> n >> m;
    
    v.resize(n);
    dist.resize(n);
    visited.resize(n);
    
    int a, b, c;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        v[a].push_back({b, c});
        //v[b].push_back({a, c});
    }
       
    Dijekstra(5);
    
    for(int i = 0; i < dist.size(); i++)
       {
           //cout << dist[i] << " ";
       }
    
    cout << dist[2];
    
    return 0;
}

