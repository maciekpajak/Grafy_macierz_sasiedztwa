#include "Edge.h"


Edge::Edge(int weight, Vertex& v1, Vertex& v2)
{
	weight_ = weight;
	vertices_[0] = &v1;
	vertices_[1] = &v2;
}

Edge::~Edge() 
{
}

Vertex & Edge::operator[](int i)
{
	if (i == 0) return *vertices_[0];
	if (i == 1) return *vertices_[1];
	else
	{
		std::string exeption = "invalid index";
		throw exeption;
	}
}
