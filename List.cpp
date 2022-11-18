#include "List.h"
#include <iostream>
using namespace std;

/*   Keeping in mind what a Node looks like:
 *             A Plain ol' Node
 *         Head                 Tail
 * --------------------------------------------
 * | Data part of node | Pointer to next node |
 * --------------------------------------------
 * Assuming that each value for a node is unique,
 * nodes will Point to the DATA (head) in the
 * NEXT node via a pointer (tail). The last node
 * of a list will have a pointer to NULL.
 */

ListNode::ListNode(int val) : nextPtr(nullptr){
    //cout << "\t*Inside Node Constructor*\n";
    value = val;
    if (value == 0) {  // For construction of List
        setNext(nullptr);
    }
}

ListNode::~ListNode() {
    if (getValue() != NULL)
        cout << getValue() << "\t from ListNode has died\n";
}

int ListNode::getValue() const {
    //cout << "\n*Inside Node getValue()*\n";
    return value;
}

void ListNode::setNext(ListNode *n) {
    //cout << "*Inside Node::setNext()*\n";
    nextPtr = n;
}

ListNode *ListNode::getNext() {
    //cout << "*Inside ListNode::getNext()*\n";
    return nextPtr;
}

void ListNode::print() const {
    //cout << "*Inside Node print()* ";
    if (this->value != 0)
        cout << value << endl;
}

List::List() {
    //cout << "-Inside List Constructor-\n";
    /* When a new list is created, there needs to
     * be a "Dummy" or "Blank" Node available. The
     * head and tail will be 0 and NULL. */
    head = new ListNode(0);
}

List::~List() {
    ListNode* headToChop;
    do {
        headToChop = head;
        head = headToChop->getNext();
        headToChop->setNext(NULL);
        delete headToChop;
    } while (headToChop->getNext() != NULL);
    delete headToChop;
}

void List::addNode(int value) {
    //cout << "-Inside List::addNode()- ";
    ListNode *oldNode = this->head;
    //cout << "Old Node value: " << oldNode->getValue() << endl;
    //cout << "Old Node nxtPtr " << oldNode->getNext() << endl;

    auto* newNode = new ListNode(value);
    newNode->setNext(head);
    this->head = newNode;
    //cout << "New Node value: " << newNode->getValue() << endl;
    //cout << "New Node nxtPtr " << newNode->getNext() << endl << endl;
}

int List::getLength() {
    //cout << "-Inside List::getLength()-\n";
    int length = 0;
    ListNode* currentNode = head;
    while (currentNode->getNext() != NULL) {
        ListNode* nextNode = currentNode->getNext();
        currentNode = nextNode;
        length++;
    }
    return length;
}

ListNode *List::search(int value) {
    //cout << "-Inside List::search()-\n";
    ListNode* searchNode = head;
    while (searchNode->getValue() != value && searchNode->getNext() != NULL) {
        ListNode* searchNodeNotValue = searchNode->getNext();
        searchNode = searchNodeNotValue;
    }
    return searchNode->getNext();
}

void List::printList() {
    int printIndex = getLength();
    ListNode* lastNode = head;
    int forwardList[getLength()-1];
    cout << "Here is your list:\n";

    while (lastNode->getNext() != NULL) {
        forwardList[printIndex] = lastNode->getValue();
        ListNode* previousNode = lastNode->getNext();
        lastNode = previousNode;
        printIndex--;
    }

    for (int i = 1; i < getLength() + 1; i++)
        cout << forwardList[i] << endl;

    cout << endl;
}