#include <iostream>
#include "methods.cpp"

int main()
{
    DoublyLinkedList<int> l;
    //l.print();
    //std::cout << l;
    DoublyLinkedList<int>* lp = new DoublyLinkedList<int>(123);
    lp->insert(2);
    lp->insert(3);
    lp->insert(4);

    lp->get(0) = 43;

    std::cout << *lp;

    return 0;
}
