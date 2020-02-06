//
// Created by ardeus on 02/02/2020.
//

#ifndef EX4_NODE_H
#define EX4_NODE_H

template <typename T>
class Node {
private:
    bool hasBeenVisited;
public:
    bool isHasBeenVisited() const {
        return hasBeenVisited;
    }

    void setHasBeenVisited(bool hasBeenVisited) {
        Node::hasBeenVisited = hasBeenVisited;
    }

    Node<T> *getSource() const {
        return source;
    }

    void setSource(Node<T> *source) {
        Node::source = source;
    }

    T getNodeValue() const {
        return nodeValue;
    }

    void setNodeValue(T nodeValue) {
        Node::nodeValue = nodeValue;
    }

    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        Node::cost = cost;
    }

private:
    Node<T> *source;
    T nodeValue;
    double cost;
public:
    Node();
};


#endif //EX4_NODE_H
