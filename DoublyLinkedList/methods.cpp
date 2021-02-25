#include <iostream>
#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(T value)
{
	this->head = new Node<T>(value);
	this->tail = head;
	this->size = 1;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (head == nullptr)
	{
		return;
	}

	while (head->next != nullptr)
	{
		head = head->next;
		delete head->prev;
	}

	delete head;
}

template <typename T>
void DoublyLinkedList<T>::insert(T value)
{
	if (head == nullptr)
	{
		head = new Node<T>(value);
		tail = head;
		++size;
		return;
	}

	Node<T>* temp = new Node<T>(value);
	++size;
	tail->next = temp;
	temp->prev = tail;
	tail = temp;
}

template <typename T>
void DoublyLinkedList<T>::insert(T value, int pos)
{
	if (pos < 0 || pos > size)
	{
		std::cout << "nope\n";
		return;
	}

	if (pos == 0)
	{
		Node<T>* temp = new Node<T>(value);
		++size;
		temp->next = head;
		head->prev = temp;
		head = temp;
		return;
	}

	if (pos == size)
	{
		return insert(value);
	}

	if (pos < size / 2)
	{
		Node<T>* cur = this->head;
		for (int i = 1; i < pos; ++i)
		{
			cur = cur->next;
		}

		Node<T>* temp = new Node<T>(value);
		++size;
		temp->next = cur->next;
		temp->prev = cur;
		cur->next->prev = temp;
		cur->next = temp;
		return;
	}
	else
	{
		Node<T>* cur = this->tail;
		for (int i = size - pos - 1; i > 0; --i)
		{
			cur = cur->prev;
		}

		Node<T>* temp = new Node<T>(value);
		++size;
		temp->next = cur;
		temp->prev = cur->prev;
		cur->prev->next = temp;
		cur->prev = temp;
		return;
	}

}

template <typename T>
void DoublyLinkedList<T>::remove()
{
	if (head == nullptr)
	{
		std::cout << "List is empty\n";
		return;
	}

	tail = tail->prev;
	delete tail->next;
	--size;
	tail->next = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::remove(int pos)
{
	if (pos < 0 || pos >= size)
	{
		std::cout << "nope\n";
		return;
	}

	if (pos == 0)
	{
		head = head->next;
		delete head->prev;
		--size;
		head->prev = nullptr;
		return;
	}

	if (pos == size - 1)
	{
		return remove();
	}

	if (pos < size / 2)
	{
		Node<T>* cur = this->head;
		for (int i = 0; i < pos; ++i)
		{
			cur = cur->next;
		}

		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		--size;
		return;
	}
	else
	{
		Node<T>* cur = this->tail;
		for (int i = size - pos - 1; i > 0; --i)
		{
			cur = cur->prev;
		}

		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		--size;
		return;
	}
}

template <typename T>
int DoublyLinkedList<T>::length()
{
	return size;
}

template <typename T>
bool DoublyLinkedList<T>::empty()
{
	return !size;
}

template <typename T>
void DoublyLinkedList<T>::print()
{
	for (Node<T>* cur = this->head; cur != nullptr; cur = cur->next)
	{
		std::cout << cur->value << " ";
	}

	std::cout << "\n";
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
	while (head->next != nullptr)
	{
		head = head->next;
		delete head->prev;
	}

	delete head;

	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <typename U>
std::ostream& operator<< (std::ostream& os, const DoublyLinkedList<U>& list)
{
	for (Node<U>* cur = list.head; cur != nullptr; cur = cur->next)
	{
		os << cur->value << " ";
	}

	os << "\n";

	return os;
}