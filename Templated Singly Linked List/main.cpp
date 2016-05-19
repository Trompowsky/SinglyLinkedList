#include "ListTemp.h"

using namespace std;

int main()
{
    ListTemp<int> * a = new ListTemp<int>();
    a->remove(4);
    a->add(1);
    a->remove(1);
    a->add(2);
    a->add(3);
    a->add(4);
    a->add(5);
    a->add(6);
    a->print();
    a->remove(4);
    a->print();
    a->remove(2);
    a->print();
    a->remove(4);
    a->remove(1);
    a->print();

    ListTemp<string> * b = new ListTemp<string>();
    b->add("We");
    b->add("Didn't");
    b->add("Start");
    b->add("The");
    b->add("Fire");
    b->add("Yeah");
    b->print();
    b->remove("Didn't");
    b->add("Man");
    b->remove("The");
    b->print();
    delete b;
}
