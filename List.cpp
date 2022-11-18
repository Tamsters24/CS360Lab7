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
    cout << getValue() << "\t from ListNode has died";
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
    cout << head->getValue() << " from List has died\n";
    delete head;
    //getLength();
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
    string reverseList = "";
    ListNode* currentNode = head;
    //cout << "Current Node = " << currentNode << endl;
    while (currentNode->getNext() != 0) {
        length++;
        //cout << "length at current node: " << length << endl;
        //cout << "current node getValue() " << currentNode->getValue() << endl;
        reverseList += to_string(currentNode->getValue());
        reverseList += "\n";
        ListNode* nextNode = currentNode->getNext();
        currentNode = nextNode;
        // this produces values in reverse order.
    }
    cout << reverseList << endl;
    string forwardList;
    for (int i = reverseList.length(); i >=0; i--) {
        cout << "i = " << i << " " << reverseList[i] << endl;
        forwardList += reverseList[i];
    }
    cout << forwardList; // prints "in order, but numbers reversed"

    return length;
}

ListNode *List::search(int value) {
    return head;
}

void List::printList() {
    cout << "Here is your list:\n";
    getLength();
}