#include <bits/stdc++.h>
#include "HashMap.h"
using namespace std;

void HashMap::clear_map()
{
    size = 0;
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i])
        {
            delete nodes[i];
        }
    }
}

int HashMap::hashify(int key, int base = 256)
{
    string strim = to_string(key);
    int hash_val = 0;
    long sum = 0, mul = 1;
    for (int i = 0; i < strim.length(); i++) {
        mul = (i % 4 == 0) ? 1 : mul * base;
        sum += strim[i] * mul;
    }
    return (int)(abs(sum) % nodes.size());
    
    // using a predictable hash function
    return key % size;

}

int HashMap::double_hash(int key, int attempt)
{
    int hash_1 = hashify(key,256);
    int hash_2 = hashify(key,152);
    return (hash_1 + attempt * (hash_2 + 1)) % size;
}

int HashMap::insert(int key, int value)
{
    HashNode* node = new HashNode(key,value);
    int index = double_hash(key,0);
    int curr_index = index;
    int i = 1;

    while(nodes[curr_index] != NULL)
    {
        curr_index = double_hash(key,i);
        i++;
    }    
    nodes[curr_index] = node;
    count++;
}


int HashMap::search(int key)
{
    int index = double_hash(key,0);
    int curr_index = index;
    int i = 1;

    while(nodes[curr_index] != NULL)
    {
        if(nodes[curr_index]->key == key)
        {
            return nodes[curr_index]->val;
        }
        curr_index = double_hash(key,i);
        i++;
    }    
    return -1;
}

void HashMap::deleteEntry(int key)
{
    int index = double_hash(key,0);
    int curr_index = index;
    int i = 1;

    while(nodes[curr_index] != NULL)
    {
        if(nodes[curr_index]->key == key)
        {
            nodes[curr_index]->key = -1;
            break;
        }
        curr_index = double_hash(key,i);
        i++;
    }    

    count--;
}