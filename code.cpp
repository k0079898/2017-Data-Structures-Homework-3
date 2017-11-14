#include <iostream>
#include <cstring>
#include <string>
#include "function.h"

using namespace std;

void Implement::Insert(int value) {
    int currentNode = ++size;
    while(currentNode!=1 && heap[currentNode/2]<value) {
        heap[currentNode] = heap[currentNode/2];
        currentNode /= 2;
    }
    heap[currentNode] = value;
}

void Implement:: DeleteMax() {
    if(size!=0) {
        heap[1] = 0;
        int lastE = heap[size];
        size--;
        int currentNode = 1;
        int child = 2;
        while(child <= size) {
            if (child<size && heap[child]<heap[child + 1]) child++;
            if (lastE >= heap[child]) break;
            heap[currentNode] = heap[child];
            currentNode = child;
            child *= 2;
        }
        heap[currentNode] = lastE;
    }
}

int Implement::MaxPathWeight(int index) {
    int weight = 0;
    if(size!=0) {
        int currentNode = 2;
        weight += heap[1];
        while(currentNode <= size) {
            if(currentNode<size && heap[currentNode]<heap[currentNode + 1]) currentNode++;
            weight += heap[currentNode];
            currentNode *= 2;
        }
    }
    return weight;
}

string Implement::InorderTraversal(int index) {
    string result = "";
    if(index<=size) {
        string r = "";
        string L = "";
        string R = "";
        L.append(InorderTraversal(index*2));
        r.append(to_string(heap[index]));
        R.append(InorderTraversal(index*2+1));
        if(L=="" && R=="") result.append(r);
        else if(R=="") result.append(L+" "+r);
        else result.append(L+" "+r+" "+R);
    }
    return result;
}

string Implement::PreorderTraversal(int index) {
    string result = "";
    if(index<=size) {
        string r = "";
        string L = "";
        string R = "";
        r.append(to_string(heap[index]));
        L.append(PreorderTraversal(index*2));
        R.append(PreorderTraversal(index*2+1));
        if(L=="" && R=="") result.append(r);
        else if(R=="") result.append(r+" "+L);
        else result.append(r+" "+L+" "+R);
    }
    return result;
}

string Implement::PostorderTraversal(int index) {
    string result = "";
    if(index<=size) {
        string r = "";
        string L = "";
        string R = "";
        L.append(PostorderTraversal(index*2));
        R.append(PostorderTraversal(index*2+1));
        r.append(to_string(heap[index]));
        if(L=="" && R=="") result.append(r);
        else if(R=="") result.append(L+" "+r);
        else result.append(L+" "+R+" "+r);
    }
    return result;
}
