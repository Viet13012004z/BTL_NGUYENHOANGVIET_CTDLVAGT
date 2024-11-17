#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_V = 1000;  // So luong dinh toi da
vector<int> adj[MAX_V];   // Danh sach ke

// Ham BFS de tim duong di ngan nhat
int BFS(int s, int t, int V) {
    vector<int> dist(V, -1);  // Mang khoang cach, -1 nghia la chua tham
    queue<int> q;
    dist[s] = 0;  // Dat khoang cach tu dinh bat dau s la 0
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++) {  // Duyet qua danh sach ke
            int v = adj[u][i];
            if (dist[v] == -1) {  // Neu chua tham dinh v
                dist[v] = dist[u] + 1;  // Cap nhat khoang cach
                if (v == t) return dist[v];  // Neu da den dich
                q.push(v);
            }
        }
    }

    return -1;  // Khong co duong di tu s den t
}

int main() {
    int V, E;
    cout << "Nhap so luong dinh va canh (V, E): ";
    cin >> V >> E;

    cout << "Nhap cac canh (u, v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Do thi khong co trong so, co huong nguoc lai
    }

    int s, t;
    cout << "Nhap hai thanh pho (s, t): ";
    cin >> s >> t;

    int result = BFS(s, t, V);
    if (result != -1) {
        cout << "Duong di ngan nhat tu thanh pho " << s << " den thanh pho " << t << " co do dai: " << result << endl;
    } else {
        cout << "Khong co duong di tu thanh pho " << s << " den thanh pho " << t << endl;
    }

    return 0;
}

