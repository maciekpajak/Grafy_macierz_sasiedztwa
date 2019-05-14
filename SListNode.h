#pragma once

template <typename E>
class SListNode
{                     //wêze³ listy dwukierunkowej 
private:
	E* element_;                    //wskaznik na element listy  
	SListNode<E>* next_;                //nastêpny elem. listy 
	SListNode<E>* previous_;

	template <typename E>
	friend class SLinkedList;      //dostêp dla listy 

public:
	SListNode() { element_ = new E(); next_ = nullptr; previous_ = nullptr; }
	SListNode(E& element) { element_ = &element; next_ = nullptr; previous_ = nullptr; previous_ = nullptr; }
	~SListNode() { delete element_; next_ = nullptr; previous_ = nullptr; }

	//metody dostêpu do danych: 
	E& getElement() const { return *element_; }
	SListNode<E>& getNext() const { return *next_; }
	SListNode<E>& getPrevious() const { return *previous_; }
	//metody modyfikuj¹ce: 
	void setElement(E& newElement) { element_ = &newElement; }
	void setNext(SListNode<E>& newNext) { next_ = &newNext; }
	void setPrevious(SListNode<E>& newPrevious) { previous_ = &newPrevious; }
};
