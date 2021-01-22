#pragma once

template<class T>
class List
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;

public:
	List();
	~List();
	void pushBack(T data);
	void pushFront(T data);
	T& operator[] (int);
	void popFront();
	void popBack();
	void clear();
	void insert(T data, int index);
	void removeAt(int index);
	int getSize() { return Size; };
};