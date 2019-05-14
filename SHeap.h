#pragma once
#include "SHeapNode.h"
#include <string>

template <typename E>
class SHeap
{
private:

	int indexOfLastAdded_;
	SHeapNode<E>** root_;
public:

	SHeap() { root_ = new SHeapNode<E>*(); indexOfLastAdded_ = 0; }
	SHeap(int n);
	~SHeap() {}

	bool isEmpty() { return indexOfLastAdded_ == 0 ? true : false; }
	int size() { return indexOfLastAdded_; }
	E& getMin();
	void insert(E& element, int k);
	void removeMin();
	void upHeap();
	void downHeap(int i);
	void replaceKey(E& e, int k);

	E& operator [] (int n) { return root_[n]->getElement(); }

	void fullHeaping();
};

template<typename E>
SHeap<E>::SHeap(int n)
{
	root_ = new SHeapNode<E>*[n + 1];
	for (int i = 0; i < n + 1; i++)
		root_[i] = new SHeapNode<E>();
	indexOfLastAdded_ = 0;
}

template<typename E>
E & SHeap<E>::getMin()
{
	if (root_ != nullptr)
		return root_[1]->getElement();
	else
	{
		std::string exeption = "root_ is nullptr";
		throw exeption;
	}
}
template<typename E>
void SHeap<E>::insert(E & element, int k)
{
	root_[indexOfLastAdded_ + 1]->setElement(element);
	root_[indexOfLastAdded_ + 1]->setKey(k);
	indexOfLastAdded_++;
	upHeap();

}

template<typename E>
void SHeap<E>::removeMin()
{
	if (root_ == nullptr)
	{
		std::string exeption = "root_ is nullptr";
		throw exeption;
	}
	else
	{

		root_[1] = root_[indexOfLastAdded_];
		root_[indexOfLastAdded_] = new SHeapNode<E>();
		indexOfLastAdded_--;
		downHeap(1);
	}
}

template<typename E>
void SHeap<E>::upHeap()
{
	int k = indexOfLastAdded_;
	while (root_[k]->getKey() < root_[(int)k / 2]->getKey() and k > 1)
	{
		SHeapNode<E>* tmp = root_[(int)k / 2];
		root_[(int)k / 2] = root_[k];
		root_[k] = tmp;
		k = (int)k / 2;
	}
}

template<typename E>
void SHeap<E>::downHeap(int i)
{
	if (i == 0)
	{
		std::string exeption = "index of heap cannot be 0";
		throw exeption;
	}
	int j = 0, k = i;
	while (j != k)
	{
		j = k;
		if (2 * j <= indexOfLastAdded_ and root_[j * 2]->getKey() < root_[k]->getKey())
			k = 2 * j;
		if (2 * j + 1 <= indexOfLastAdded_ and root_[j * 2 + 1]->getKey() < root_[k]->getKey())
			k = 2 * j + 1;
		SHeapNode<E>* tmp = root_[k];
		root_[k] = root_[j];
		root_[j] = tmp;
	}
}

template<typename E>
void SHeap<E>::replaceKey(E& e, int k)
{
	for (int i = 1; i <= indexOfLastAdded_; i++)
		if (root_[i]->getElement() == e)
		{
			root_[i]->setKey(k);
			break;
		}
	//fullHeaping();
}

template<typename E>
inline void SHeap<E>::fullHeaping()
{
	for (int i = 1; i <= indexOfLastAdded_; i++)
		downHeap(i);
}

