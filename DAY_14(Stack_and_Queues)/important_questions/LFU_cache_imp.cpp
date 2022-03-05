#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
struct Node
{
    int key,value,count;
    Node* next;
    Node* prev;
    Node(int key_check,int val)
    {
        key=key_check;
        value=val;
        count=1;
    }
};
struct List
{
    int size;
    Node* head;
    Node*  tail;
    List()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        size=0;
        head->next=tail;
        tail->prev=head;
    }
    void addFront(Node* newNode)
    {
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
        size++;
    }
    
    void deleteNode(Node* delNode)
    {
        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
        size--;
    }
};
class LFUCache
{
    int min_freq,max_cache,curr_size;
    unordered_map<int,List*> freqList;
    unordered_map<int,Node*> keyNode; 
    LFUCache(int capacity)
    {
        min_freq=0;
        max_cache=capacity;
        curr_size=0;
    }

    void updateFreqList(Node* node)
    {
        keyNode.erase(node->key);
        freqList[node->count]->deleteNode(node);
        if(node->count==min_freq and freqList[node->count]->size==0)
            min_freq++;
        List* nextHigherList=new List();
        if(freqList.find(node->count+1)!=freqList.end())
        {
            nextHigherList=freqList[node->count+1];
        }
        node->count+=1;
        nextHigherList->addFront(node);
        freqList[node->count]=nextHigherList;
        keyNode[node->key]=node;
    }
    int get(int key)
    {
        if(keyNode.find(key)!=keyNode.end())
        {
            Node* temp=keyNode[key];
            int val=temp->value;
            updateFreqList(temp);
            return val;
        }
        return -1;
    }
    void put(int key,int val)
    {
        if(max_cache==0)
            return;
        if(keyNode.find(key)!=keyNode.end())
        {
            Node* temp=keyNode[key];
            temp->value=val;
            updateFreqList(temp);
        }
        else
        {
            if(curr_size==max_cache)
            {
                List* list=freqList[min_freq];
                keyNode.erase(list->tail->prev->key);
                freqList[min_freq]->deleteNode(list->tail->prev);
                curr_size--;
            }
            curr_size++;
            min_freq=1;
            List* newList=new List();
            if(freqList.find(min_freq)!=freqList.end())
            {
                newList=freqList[min_freq];
            }
            Node* newNode=new Node(key,val);
            newList->addFront(newNode);
            keyNode[key]=newNode;
            freqList[min_freq]=newList;
        }
    }
}; 
int main()
{
    
    return 0;
}

/*
https://leetcode.com/problems/lfu-cache/

VERY IMPORTANT QUESTION
*/