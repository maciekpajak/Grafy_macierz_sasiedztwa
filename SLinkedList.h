#pragma once
#include "SListNode.h"
#include <string>

template < typename E>
class SLinkedList          //lista jednokierunkowa 
{
private:
	SListNode<E>* head_;              //pocz¹tek listy
	SListNode<E>* tail_;
	int size_;

public:
	SLinkedList() { head_ = nullptr; tail_ = nullptr; size_ = 0; }
	~SLinkedList() {}

	bool isEmpty() const;
	int getSize() { return size_; }    //zwraca rozmiar listy

	void addFront(E& e);     //dodawanie na pocz¹tek listy 
	void addLast(E& e);

	E& front() { return *(head_->element_); }
	E& last() { return *(tail_->element_); }
	SListNode<E>& frontNode() { return *head_; }
	SListNode<E>& lastNode() { return *tail_; }

	E& element(int n);

	void removeFront();					//usuñ pierwszy element listy 
	void removeLast();					//usuñ last element listy 
	void remove(SListNode<E> &p); //usuwa wskazany wêze³
	void remove(E* e);   //usuwa wêze³ ze wskazanym elementem

	E& operator[] (int n);


	//SListNode<E>& getHead() const { return *head_; }  //zwraca head_
	//void setHead(SListNode<E>& node) { *head_ = node; }  //ustawia head_

};

template < typename E>
bool SLinkedList<E>::isEmpty() const
{
	return head_ == nullptr ? true : false;
}

template < typename E>
void SLinkedList<E>::addFront(E& e)
{
	SListNode<E> *tmp = new SListNode<E>(e);
	if (isEmpty())
	{
		head_ = tmp;
		tail_ = tmp;
	}
	else
	{
		head_->setPrevious(*tmp);
		tmp->setNext(*head_);
		head_ = tmp;
	}
	size_++;
}

template < typename E>
void SLinkedList<E>::addLast(E& e)
{
	SListNode<E> *tmp = new SListNode<E>(e);
	if (isEmpty())
	{
		head_ = tmp;
		tail_ = tmp;
	}
	else
	{
		tail_->setNext(*tmp);
		tmp->setPrevious(*tail_);
		tail_ = tmp;
	}
	size_++;
}

template<typename E>
E & SLinkedList<E>::element(int n)
{
	if (n < 1)
	{
		std::string exeption = "index is lower than 1";
		throw exeption;
	}
	if (n <= size_)
	{
		SListNode<E> *tmp = head_;
		for (int i = 1; i < n; i++)
			tmp = tmp->next_;
		return *(tmp->element_);
	}
	else
	{
		std::string exeption = "list is empty";
		throw exeption;
	}
}

template<typename E>
E & SLinkedList<E>::operator[] (int n)
{
	if (n < 1)
	{
		std::string exeption = "index is lower than 1";
		throw exeption;
	}
	if (n <= size_)
	{
		SListNode<E> *tmp = head_;
		for (int i = 1; i < n; i++)
			tmp = tmp->next_;
		return *(tmp->element_);
	}
	else
	{
		std::string exeption = "list is empty";
		throw exeption;
	}
}
template < typename E>
void SLinkedList<E>::removeFront()
{
	if (!isEmpty())
	{
		if (head_ != tail_)
		{
			head_ = head_->next_;
			head_->previous_->~SListNode();
			head_->previous_ = nullptr;
		}
		else
		{
			head_->~SListNode();
			head_ = nullptr;
			tail_ = nullptr;
		}
		size_--;
	}
	else
	{
		std::string exeption = "list is empty";
		throw exeption;
	}
}

template < typename E>
void SLinkedList<E>::removeLast()
{
	if (!isEmpty())
	{
		if (head_ != tail_)
		{
			tail_ = tail_->previous_;
			tail_->next_->~SListNode();
			tail_->next_ = nullptr;
		}
		else
		{
			tail_->~SListNode();
			head_ = nullptr;
			tail_ = nullptr;
		}
		size_--;
	}
	else
	{
		std::string exeption = "list is empty";
		throw exeption;
	}
}

template < typename E>
void SLinkedList<E>::remove(SListNode<E>& p)
{
	if (!isEmpty())
	{
		SListNode<E>* tmp = head_;
		while (tmp != &p and tail_ != tmp)
			tmp = tmp->next_;
		if (tmp != &p and tail_ == tmp)
		{
			std::string exeption = "there is no node p to remove in list";
			throw exeption;
		}
		if (head_ == tmp)
			this->removeFront();
		else if (tail_ == tmp)
			this->removeLast();
		else
		{
			tmp->previous_->setNext(*tmp->next_);
			tmp->next_->setPrevious(*tmp->previous_);
			p->~SListNode();
		}
		size_--;
	}
	else
	{
		std::string exeption = "list is empty";
		throw exeption;
	}
}

template<typename E>
void SLinkedList<E>::remove(E* e)
{
	if (!isEmpty())
	{
		SListNode<E>* tmp = head_;
		while (tmp->element_ != e and tail_ != tmp)
			tmp = tmp->next_;
		if (tmp->element_ != e and tail_ == tmp)
		{
			std::string exeption = "there is no node p to remove in list";
			throw exeption;
		}
		if (head_ == tmp)
			this->removeFront();
		else if (tail_ == tmp)
			this->removeLast();
		else
		{
			tmp->previous_->setNext(*tmp->next_);
			tmp->next_->setPrevious(*tmp->previous_);
			tmp->~SListNode();
		}
		size_--;
	}
	else
	{
		std::string exeption = "list is empty";
		throw exeption;
	}
}
