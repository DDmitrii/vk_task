#include <iostream>
#include <fstream>

using namespace std;

void bfs(const vector<vector<int>>& graph, int v, vector<int>& dist) { // Функция обхода графа в ширину
    queue<int> q; // Создаем очередь
    q.push(v);
    dist[v] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ifstream input("graph.txt"); // Открываем файл для чтения
    if (!input.is_open()) { // Проверяем, открылся ли файл
        cerr << "Не удалось открыть файл" << endl;
        return 1;
    }

    int vertices, edges;
    input >> vertices >> edges;

    vector<vector<int>> graph(vertices); // Граф в виде списков смежности
    for (int i = 0; i < edges; ++i) {
        int u, v;
        input >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int src;
    input >> src;

    input.close(); // Закрываем файл после чтения всех данных

    vector<int> dist(vertices, -1); // Вектор расстояний до src
    bfs(graph, src, dist);

    for (int i = 0; i < vertices; ++i) { // Выводим ответ в консоль
        cout << dist[i] << endl;
    }

    return 0;
}
