#include <iostream>

template <typename T>
struct Node
{
	T value;
	Node* next;
	Node* prev;

	Node(T value)
	{
		this->value = value;
		next = nullptr;
		prev = nullptr;
	}

};

template <typename T>
class DoublyLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	DoublyLinkedList();
	DoublyLinkedList(T);
	~DoublyLinkedList();

	void insert(T);
	void insert(T, int);
	void remove();
	void remove(int);
	int length();
	bool empty();
	void print();
	void clear();

	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const DoublyLinkedList<U>&);
};