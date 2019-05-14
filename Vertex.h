#pragma once
#include "SLinkedList.h"
#include "Edge.h"
#include <string>

class Edge;

class Vertex
{
private:
	int element_;
	int distance_;

public:

	Vertex();
	Vertex(std::string name);
	Vertex(int element);
	Vertex(int element, std::string name);
	~Vertex();

	int getElement() const { return element_; }
	int getDistance() const { return distance_; }


	void setElement(int newElement) { element_ = newElement; }
	void setDistance(int newDistance) { distance_ = newDistance; }



	bool operator == (Vertex& v) { return element_ == v.element_ ? true : false; }
	bool operator > (Vertex& v) { return element_ > v.element_ ? true : false; }
	bool operator >= (Vertex& v) { return element_ >= v.element_ ? true : false; }
	bool operator < (Vertex& v) { return element_ < v.element_ ? true : false; }
	bool operator <= (Vertex& v) { return element_ <= v.element_ ? true : false; }
	bool operator != (Vertex& v) { return element_ != v.element_ ? true : false; }

};

