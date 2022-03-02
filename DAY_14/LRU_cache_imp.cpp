#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, val;
        //DOUBLY LINKEDLIST
        Node *next;
        Node *prev;
        Node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> m;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode)
    {
        Node *oldPrev = delNode->prev;
        Node *oldNext = delNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key_check)
    {
        if (m.find(key_check) != m.end())
        {
            Node *resNode = m[key_check];
            int res = resNode->val;
            m.erase(key_check);
            deleteNode(resNode);
            addNode(resNode);
            m[key_check] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_check, int value)
    {
        if (m.find(key_check) != m.end())
        {
            Node *oldNode = m[key_check];
            m.erase(key_check);
            deleteNode(oldNode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key_check, value));
        m[key_check] = head->next;
    }
};

int main()
{
    
    return 0;
}

/*
https://leetcode.com/problems/lru-cache/

VERY IMPORTANT QUESTION
*/