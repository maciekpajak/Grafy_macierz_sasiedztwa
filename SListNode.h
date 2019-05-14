#pragma once

template <typename E>
class SListNode
{                     //w�ze� listy dwukierunkowej 
private:
	E* element_;                    //wskaznik na element listy  
	SListNode<E>* next_;                //nast�pny elem. listy 
	SListNode<E>* previous_;

	template <typename E>
	friend class SLinkedList;      //dost�p dla listy 

public:
	SListNode() { element_ = new E(); next_ = nullptr; previous_ = nullptr; }
	SListNode(E& element) { element_ = &element; next_ = nullptr; previous_ = nullptr; previous_ = nullptr; }
	~SListNode() { delete element_; next_ = nullptr; previous_ = nullptr; }

	//metody dost�pu do danych: 
	E& getElement() const { return *element_; }
	SListNode<E>& getNext() const { return *next_; }
	SListNode<E>& getPrevious() const { return *previous_; }
	//metody modyfikuj�ce: 
	void setElement(E& newElement) { element_ = &newElement; }
	void setNext(SListNode<E>& newNext) { next_ = &newNext; }
	void setPrevious(SListNode<E>& newPrevious) { previous_ = &newPrevious; }
};
