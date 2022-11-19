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
    if (getValue() != 0)
        cout << getValue() << "\t from ListNode has died\n";
    //else
    //    cout << "";
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

void ListNode::print() {
    //cout << "*Inside Node print()* ";
    if (this->value != 0)
        cout << value << endl;
}

List::List() {
    //cout << "-Inside List Constructor-\n";
    /* When a new list is created, there needs to
     * be a "Dummy" or "Blank" Node available. The
     * head and tail will be NULL. */
    head = new ListNode(NULL);
}

List::~List() {
    ListNode* headToChop;
    int length = getLength() + 1;
    int deleted = 0;
    for (int i = 0; i < length; i++) {
        headToChop = head;
        head = headToChop->getNext();
        headToChop->setNext(NULL);
        delete headToChop;
        deleted++;
    }
    cout << "deleted " << deleted-1 << " list entries\n";
}

void List::addNode(int value) {
    //cout << "-Inside List::addNode()- ";
    //previous addNode was adding at the front.
    //current addNode adds to the end
    ListNode* newNode = new ListNode(value);
    ListNode *last = head;  // make the "head" the last node
    newNode->setNext(NULL); // new node will add to the last (will be in front)
    if (head == NULL)   // If newNode is the first node of the list
        head = newNode;
    while (last->getNext()!=NULL)   // for subsequent nodes, iterate
        last = last->getNext();     // to the "true" last node

    last->setNext(newNode); // new node is tacked on at the end
}

int List::getLength() {
    //cout << "-Inside List::getLength()-\n";
    int length = 0;
    ListNode* currentNode = head;
    while (currentNode->getNext() != NULL) {
        ListNode* nextNode = currentNode->getNext();
        currentNode->setNext(nextNode);
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
    ListNode* currentNode = head;
    while (currentNode->getNext() != NULL) {
        ListNode* nextNode = currentNode->getNext();
        currentNode->setNext(nextNode);
        currentNode = nextNode;
        cout << currentNode->getValue() << endl;
    }

        cout << endl;
}