#ifndef HASH_H
#define HASH_H
#include <vector>

class HashNode {
    public:
     int key;
     int val;
     
    HashNode (int k, int v): key(k), val(v) {} 
};

class HashMap {       // The class
  
  public:             // Access specifier
    int size;
    std::vector <HashNode *> nodes;
    int count;

    
    HashMap(int sz=53)
    {
        size = sz;
        count = 0;
        nodes.resize(size,NULL);
    } 

    void clear_map();
    int hashify(int,int);
    int double_hash(int,int);
    void insert(int,int);
    int search(int);
    void deleteEntry(int);

};

#endif