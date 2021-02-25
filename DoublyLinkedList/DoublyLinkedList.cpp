#include <iostream>
#include "methods.cpp"

int main()
{
    DoublyLinkedList<int> l;
    //l.print();
    //std::cout << l;
    DoublyLinkedList<int>* lp = new DoublyLinkedList<int>(123);
    std::cout << *lp;
    l.insert(2);
    l.insert(3);
    l.insert(4);

    l.insert(0, 4);
    l.insert(0, 0);
    l.insert(0, 3);
    l.remove();
    l.insert(10);
    l.remove(6);
    l.remove(0);
    l.remove(3);
    //std::cout << l.length();
    l.print();

    std::cout << l;

    return 0;
}
