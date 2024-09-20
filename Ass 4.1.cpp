#include <iostream> 
#include <limits.h> 
#include <list> 
#include <queue>

using namespace std; 

#define TOTAL_VERTICES 9 

int findMinDistance(int dist[], bool visited[]) 
{ 
	int minDist = INT_MAX, minIndex; 

	for (int v = 0; v < TOTAL_VERTICES; v++) 
		if (!visited[v] && dist[v] <= minDist) 
			minDist = dist[v], minIndex = v; 

	return minIndex; 
} 

void displaySolution(int dist[], int count) 
{ 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < TOTAL_VERTICES; i++) 
		printf("%d tt %d\n", i, dist[i]); 
} 

void dijkstraAlgorithm(int graph[TOTAL_VERTICES][TOTAL_VERTICES], int source) 
{ 
	int dist[TOTAL_VERTICES]; 
	bool visited[TOTAL_VERTICES]; 

	for (int i = 0; i < TOTAL_VERTICES; i++) 
		dist[i] = INT_MAX, visited[i] = false; 

	dist[source] = 0; 

	for (int count = 0; count < TOTAL_VERTICES - 1; count++) { 
		int u = findMinDistance(dist, visited); 

		visited[u] = true; 

		for (int v = 0; v < TOTAL_VERTICES; v++) 
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	displaySolution(dist, TOTAL_VERTICES); 
} 

int main() 
{ 
	int graph[TOTAL_VERTICES][TOTAL_VERTICES] = { 
		{ 0, 4, 0, 0, 0, 0,  8, 0 }, 
		{ 4, 0, 8, 0, 0, 0,  11, 0 }, 
		{ 0, 8, 0, 7, 0, 4,  0, 2 }, 
		{ 0, 0, 7, 0, 9, 14, 0,  0 }, 
		{ 0, 0, 0, 9, 0, 10, 0,  0 }, 
		{ 0, 0, 4, 14, 10, 0, 2, 0 }, 
		{ 0, 0, 0, 0, 0, 2, 1, 6 }, 
		{ 8, 11, 0, 0, 0, 0, 1, 7 }, 
		{ 0, 0, 2, 0, 0, 0, 6, 7 } 
	}; 

	dijkstraAlgorithm(graph, 0); 

	return 0; 
}

Output Result
Vertex Distance from Source
0 tt 0
1 tt 4
2 tt 12
3 tt 19
4 tt 20
5 tt 10
6 tt 8
7 tt 14
8 tt 2147483647
