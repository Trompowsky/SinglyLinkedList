#ifndef LISTTEMP_H_INCLUDED
#define LISTTEMP_H_INCLUDED

#include <iostream>

using namespace std;


//Datatype T needs ostream <<, equality ==, and copy constructor, otherwise, certain methods don't work properly

//pHead points to 1st ListNode, then we use pCurr to point to the next one in the chain, and move along via pCurr=pCurr->pNext,
//with pPrev as the one before, useful for deleting nodes

template <class T>
class ListTemp {
public:
    ListTemp();
    ~ListTemp();

    class ListNode {
        public:
            T value; //ListNode object must have value
            ListNode * pNext; // creates pointer to listnode object
            ListNode (T val){ //constructor for listnode, which has value and pNext set to null, as pNext points to next Listnode, which has value, etc.
            value = val;
            pNext = NULL;
            }
    };

    void add (T val);
    void remove (T val);
    void print ();
    private:
        ListNode * pHead;
        ListNode * pCurr;
        ListNode * pPrev;

};

template <class T>
ListTemp<T>::ListTemp(){
pHead = NULL;  // Initially, node points to nothing
pCurr = pHead;
pPrev = pHead;

}

template <class T>
ListTemp<T>::~ListTemp(){
    pPrev = pHead;
    while (pPrev){  //While the previous listnode (equal to the current listnode by pPrev = pCurr) does not equal zero, delete pPrev
        pCurr = pPrev->pNext;  //pCurr points to the listnode after what pPrev points to, or, more simple, points to the one after pPrev
        delete pPrev;  //Safely delete pPrev now that we have moved along the linked list by one
        pPrev = pCurr;  //pPrev is now one further along
    }

}


template <class T>
void ListTemp<T>::add (T val){
    pCurr=pHead;
    if (pHead==NULL){  //avoid using pNext, as there is no second node, but instead fill the null pHead with a new node w/ value val
        pHead = new ListNode(val);
        pCurr = pHead;  //Our current node has shifted one along
    }else{
        while (pCurr->pNext){  //While there is still another node further in the list
            pPrev = pCurr;
            pCurr = pCurr->pNext;  //Moves pCurr down the list, pointing to new node
        }
        pCurr->pNext = new ListNode(val);    //
    }
}



template <class T>
void ListTemp<T>::remove (T val){

    if (pHead){
       pCurr = pHead;
       pPrev = pHead;

       while (pCurr->pNext && pCurr->value!=val){ // there is a ListNode after the current node and we are not currently on the node which we want to delete
        pPrev = pCurr;
        pCurr = pCurr->pNext;  //Loops around the list until we either reach end of list or reach node we want to delete
       }
    if (pCurr){
       if (pCurr->value==val){   //Checks that the ListNode pCurr points to has the same value as the one specified
            if(pPrev == pHead){
                pHead = pCurr->pNext; //We are deleting pCurr later, so if pPrev is pHead,
                                    //we want the first item in the list to be the ListNode after pCurr, which is pCurr->pNext
            }else{
        pPrev->pNext = pCurr->pNext;
            }
        delete pCurr;
       }
    }
    }
}

template <class T>
void ListTemp<T>::print (){
    cout << "(";
    if (pHead){  //testing that pHead points to another listnode, avoiding potential crashes with ->pNext.  Avoid trying to print an empty list
       pCurr = pHead;
       pPrev = NULL;  //Initially, there is no node before the current one (pHead)
       while (pCurr){
        if (!pCurr->pNext){  // if the current listnode points to null and is thus the last one, we don't need a comma & space
            cout << pCurr->value;
        }else{
        cout << pCurr->value << ", ";
        }
        pPrev = pCurr;
        pCurr = pCurr->pNext;  //Loops around the list
       }

    }
    cout << ")" << endl;

}



#endif // LISTTEMP_H_INCLUDED
