#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>

struct Node {
  int start;
  int end;
  int length;
};
bool compare(Node a, Node b) { return a.length < b.length; }


void Kruskal(std::vector<Node> &arr, std::vector<bool> &visited) {
  int M, N, iter = 0;
  M = visited.size();
  N = arr.size();

  std::ifstream file("data.txt");
  while (file >> arr[iter].start >> arr[iter].end >> arr[iter].length && iter < N) {
    iter++;
  }

  file.close();
  int counter=0;
    int weigth=0;
  sort(arr.begin(), arr.end(), compare);
    
  for (int i = 0; i < N; i++) {
   
    if (!visited[arr[i].start] || !visited[arr[i].end]) {
      weigth += arr[i].length;
      visited[arr[i].start] = true;
      visited[arr[i].end] = true;
      std::cout << arr[i].start << arr[i].end << arr[i].length << std::endl;
      counter +=1;
    }
  }
 for(int i=-2; counter<M-1;i++) {
    weigth += arr[M+i].length;
    std::cout << arr[M+i].start << arr[M+i].end << arr[M+i].length << std::endl;
    counter +=1;
   }
  
  std::cout << "Tree weight:  "<<weigth << std::endl;
}



int main() {
  int M, N;
  std::cin >> M >> N;
  std::vector<Node> arr(N);
  std::vector<bool> visited(M);
  Kruskal(arr, visited);
}