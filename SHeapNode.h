#pragma once
template <typename E>
class SHeapNode
{
private:
	E* element_;
public:
	int key;

	template <typename E>
	friend class SHeap;

	SHeapNode() { element_ = new E(); key = 0; }
	~SHeapNode() {}

	E& getElement() const { return *element_; }
	int getKey() const { return key; }

	void setElement(E& element) { element_ = &element; }
	void setKey(int k) { key = k; }

	bool operator == (SHeapNode<E>& node) { return element_ == node.getElement() ? true : false; }
	bool operator == (E& element) { return element_ == element ? true : false; }

};