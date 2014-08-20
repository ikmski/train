#ifndef _NODE_HPP_
#define _NODE_HPP_

template <typename T>
class Node
{
private:

    Node* next;
    T     data;

public:

    Node(T aData)
    {
        next = 0;
        data = aData;
    }

    ~Node() {
        if (next) {
            delete next;
            next = 0;
        }
    };

    void appendToTail(T data)
    {
        Node* end = new Node(data);
        Node* n = this;
        while (n->getNext()) {
            n = n->getNext();
        }
        n->setNext(end);
    }

    Node* getNext() { return next; }
    T     getData() { return data; }
    void  setNext(Node* aNext) { next = aNext; }

private:

    Node(const Node&);
    Node& operator = (const Node&);

};

#endif

