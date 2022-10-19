#include<iostream>
#include<vector>
#include<algorithm>

struct Node {
    int start;
    int end;
    int length;
};

int compare(Node a, Node b) {
    return a.length < b.length;
}

void Kruskal(std::vector<Node>& arr, std::vector<int>& visited) {
    int connections_size = arr.size();
    for (int i = 0; i < connections_size; i++) {
        std::cin >> arr[i].start >> arr[i].end >> arr[i].length;
    }
    std::sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < connections_size; i++) {
        if (!visited[arr[i].start] || !visited[arr[i].end]) {
            visited[arr[i].start] = true;
            visited[arr[i].end] = true;
            std::cout << arr[i].start << arr[i].end << arr[i].length << std::endl;
        }
    }
}

int main() {
    int vertex = 0, connection = 0;
    std::cout << "Please enter vertex value and connections value:" << std::endl;
    std::cin >> vertex >> connection;
    std::vector<Node> arr(connection);
    std::vector<int> visited(vertex);
    std::cout << "Please enter vertexs and thouse weight:" << std::endl;
    Kruskal(arr, visited);
}