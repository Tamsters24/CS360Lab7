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

ListNode::ListNode(int val) {
    cout << "*Inside Node Constructor*\n";
    value = val;    // Data
    /* Any new Node will be the "last" in the list */
    //setNext(NULL);
}

ListNode::~ListNode() {
    cout << getValue() << " from ListNode has died";
}

int ListNode::getValue() {
    cout << "\n-Inside Node getValue()-\n";
    return value;
}

void ListNode::setNext(ListNode *n) {
    cout << "-Inside Node::setNext()-\n";
    nextPtr = n;
}

ListNode *ListNode::getNext() {
    cout << "-Inside ListNode::getNext()-\n";
    return nextPtr;
}

List::List() {
    cout << "-Inside List Constructor-\n";
    /* When a new list is created, there needs to
     * be a "Dummy" or "Blank" Node available. The
     * head and tail will be NULL. */
    head = new ListNode(NULL); //value = NULL,
    //ListNode *head = value;
    *head = NULL;
}

List::~List() {
    cout << head->getValue();
    cout << " from List has died\n";
    delete head;
}

void List::addNode(int value) {
    cout << " addNode here: " << value << endl;
    ListNode* newNode = new ListNode(value);
    newNode->setNext(head);
}

int List::getLength() {
/*    int currentLength = 0;
    while (head->getNext() != NULL) {
        currentLength++;
    }*/
    return 0;
}

ListNode *List::search(int value) {
    return head;
}

void List::printList() {
    cout << "Here is your list:\n";
    //for (int i = 0; i < getLength(); i++)
    cout << head->getValue();
}