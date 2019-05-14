#include "SLinkedList.h"
#include "Vertex.h"
#include "Edge.h"
#include <string>
#include <fstream>
#include <ctime>

class Graph
{
private:
	SLinkedList<Vertex>* vertices_;
	SLinkedList<Edge>* edges_;
	int indexOfStartVertex_;
	Edge*** adjacencyMatrix_;

public:
	Graph() { vertices_ = new SLinkedList<Vertex>(); edges_ = new SLinkedList<Edge>(); adjacencyMatrix_ = nullptr; indexOfStartVertex_ = 0;
	}
	Graph(int n);
	~Graph();


	Vertex** endVertices(Edge& edge) { return edge.getVertices(); }
	Vertex& opposite(Vertex& vertex, Edge& edge);					
	bool areAdjacent(Vertex& v1, Vertex& v2);
	void replace(Vertex& v1, int element) { v1.setElement(element); }
	void replace(Edge& e1, int weight) { e1.setWeight(weight); }

	void insertVertex(int element) { vertices_->addLast(*(new Vertex(element))); }
	void insertVertex(Vertex& vertex) { vertices_->addLast(vertex); }
	void insertEdge(Vertex& v1, Vertex& v2, int weight);
	void removeVertex(Vertex& vertex) { vertices_->remove(&vertex); }
	void removeEdge(Edge& edge);

	SLinkedList<Edge>* incidentEdge(Vertex& vertex);
	int numberOfIncidentEdges(Vertex& vertex);

	SLinkedList<Vertex>* vertices() { return vertices_; }
	SLinkedList<Edge>* edges() { return edges_; }

	int loadFromFile(std::string fileName);
	bool saveToFile(std::string fileName, int* P, int* D);

	void graphGenerator(int nVertices, int density);

	int getIndexOfStartVertex() { return indexOfStartVertex_; }
	void setIndexOfStartVertex(int newIndex) { indexOfStartVertex_ = newIndex; }

	int numberOfVertices() { return vertices_->getSize(); }
	int numberOfEdges() { return edges_->getSize(); }

};

