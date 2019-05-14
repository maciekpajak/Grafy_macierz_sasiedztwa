#pragma once
#include "SListNode.h"
#include "Vertex.h"

class Vertex;

class Edge
{
private:
	int weight_;
	Vertex* vertices_[2];

public:

	Edge() { weight_ = 0; vertices_[0] = nullptr; vertices_[1] = nullptr; };
	Edge(int weight, Vertex& v1, Vertex& v2);
	~Edge();

	int getWeight() const { return weight_; }
	Vertex** getVertices() { return vertices_; }

	void setWeight(int newWeight) { weight_ = newWeight; }
	void setVertices(Vertex &newV1, Vertex &newV2) { vertices_[0] = &newV1; vertices_[1] = &newV2; }

	bool operator == (Edge& edge) { return (vertices_[0] == edge.vertices_[0] and vertices_[1] == edge.vertices_[1]) ? true : false; }

	Vertex& operator [] (int i);
};
