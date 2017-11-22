#include<bits/stdc++.h>
using namespace std;

class ConsistentHashRing {
private:
    map<size_t, string> ring;
    int replicas;
    hash<string> hash_fn;

public:
    ConsistentHashRing(int replicas) {
        this->replicas = replicas;
    }

    void addNode(string node) {
        for (int i = 0; i < replicas; i++) {
            size_t hash_val = hash_fn(node + to_string(i));
            ring[hash_val] = node;
        }
    }

    void removeNode(string node) {
        for (int i = 0; i < replicas; i++) {
            size_t hash_val = hash_fn(node + to_string(i));
            ring.erase(hash_val);
        }
    }

    string getNode(string data) {
        size_t hash_val = hash_fn(data);
        auto prev = ring.upper_bound(hash_val);
        if (prev == ring.end()) {
            prev = ring.begin();
        }
        return prev->second;
    }
};
