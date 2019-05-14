#include "SLinkedList.h"
#include "SListNode.h"
#include "SHeapNode.h"
#include "SHeap.h"
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "windows.h"
#include <chrono>
#include <iostream>

#define INF 1000000

void dijkstra(Graph& G, Vertex& start, int* P, int* D)
{
	P[start.getElement()] = start.getElement();
	D[start.getElement()] = 0;
	SHeap<Vertex>* queue = new SHeap<Vertex>(G.numberOfVertices());
	SLinkedList<Vertex>* graphVertices = G.vertices();
	for (int i = 1; i <= G.vertices()->getSize(); i++)
	{
		if ((*graphVertices)[i] == start)
			(*G.vertices())[i].setDistance(0);
		else
			(*G.vertices())[i].setDistance(INF);
		queue->insert((*G.vertices())[i], (*G.vertices())[i].getDistance());
	}
	while (!queue->isEmpty())
	{
		Vertex& v1 = queue->getMin();
		queue->removeMin();

		for (int i = 1; i <= G.numberOfIncidentEdges(v1); i++)
		{
			SLinkedList<Edge>* incidentEdges = G.incidentEdge(v1);
			Edge& e = (*incidentEdges)[i];
			Vertex& v2 = G.opposite(v1, e);
			int distance = v1.getDistance() + e.getWeight();
			if (distance < v2.getDistance())
			{
				v2.setDistance(distance);
				queue->replaceKey(v2, distance);
				D[v2.getElement()] = distance;
				P[v2.getElement()] = v1.getElement();
			}
		}
	}
}

void display(Graph& G, int* P, int*  D)
{
	SLinkedList<Vertex>* vertices = G.vertices();

	int i;
	for (i = 1; i <= G.numberOfVertices(); i++)
		if (G.getIndexOfStartVertex() == (*G.vertices())[i].getElement())
			break;

	Vertex* startVertex = &(*vertices)[i];

	int* S = new int[G.numberOfVertices()];
	int startNumber = startVertex->getElement();

	std::cout << "Path from vertex " << startNumber << " to:" << std::endl;
	for (int i = 0; i < G.numberOfVertices(); i++)
	{
		std::cout.width(2);
		std::cout << std::left << i << " via: ";
		std::cout << startNumber << ' ';
		int j = i, n = 0;
		while (j != startNumber)
		{
			S[n++] = j;
			j = P[j];
		}
		while (n > 0)
		{
			std::cout << S[--n] << ' ';
		}
		std::cout << " weights " << D[i] << std::endl;
	}
}



bool presentation(Graph &G, int* P, int* D)
{
	std::string inFileName;
	std::cout << "Input file: ";
	std::cin >> inFileName;
	try
	{
		G.setIndexOfStartVertex(G.loadFromFile(inFileName));
	}
	catch (std::string exeption)
	{
		std::cout << "Exeption: " << exeption << std::endl;
	}

	int i;
	for (i = 1; i <= G.numberOfVertices(); i++)
		if (G.getIndexOfStartVertex() == (*G.vertices())[i].getElement())
			break;

	try
	{
		dijkstra(G, (*G.vertices())[i], P, D);
	}
	catch (std::string exeption)
	{
		std::cout << "Exeption: " << exeption << std::endl;
	}
	std::string outFileName;
	std::cout << "Output file: ";
	std::cin >> outFileName;
	if (!G.saveToFile(outFileName, P, D))
	{
		std::cout << "File do not exist" << std::endl;
		return false;
	}
	display(G, P, D);
	return true;
}

int main()
{
	int n = 100;
	int nVertices, density;
	Graph* G = new Graph[n];

	std::cout << "Number of vertices: ";
	std::cin >> nVertices;
	std::cout << "Density [%]: ";
	std::cin >> density;
	int* P = new int[nVertices];
	int* D = new int[nVertices];

	std::cout << "GENERATING - START" << std::endl;
	for (int i = 0; i < n; i++)
	{
		G[i] = Graph(nVertices);
		try
		{
			G[i].graphGenerator(nVertices, density);
		}
		catch (std::string exeption)
		{
			std::cout << "Exeption: " << exeption << std::endl;
		}
	}
	std::cout << "GENERATING - END" << std::endl;

	std::chrono::duration<double> T;
	std::cout << "DIJKSTRA ALGORYTHM - START" << std::endl;
	auto start = std::chrono::system_clock::now();
	for (int i = 0; i < n; i++)
		dijkstra(G[i], (*G[i].vertices())[1], P, D);
	auto end = std::chrono::system_clock::now();
	std::cout << "DIJKSTRA ALGORYTHM - END" << std::endl;
	T = end - start;
	std::cout << "Execution time: " << T.count() << std::endl;


	Graph G1= Graph(7);
	if (!presentation(G1, P, D))
		std::cout << "Presentation failed" << std::endl;

	delete[] P;
	delete[] D;

	system("PAUSE");
	return 0;
}