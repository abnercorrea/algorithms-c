//
// Created by Abner Correa on 4/1/22.
//
#include <algorithm>
#include <vector>

using namespace std;

struct MyHashMapItem {
    int key;
    int value;
    MyHashMapItem(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class MyHashMap {
private:
    static const int capacity = 10000;
    MyHashMapItem *items[capacity] = { NULL };
    vector<MyHashMapItem> *collisions[capacity] = { NULL };

public:
    MyHashMap() {
    }

    int hash(int key) {
        return key % capacity;
    }

    void put(int key, int value) {
        int index = hash(key);

        if (items[index] == NULL) {
            items[index] = new MyHashMapItem(key, value);
        }
        else if (items[index]->key == key) {
            items[index]->value = value;
        }
        else if (collisions[index] == NULL) {
            collisions[index] = new vector<MyHashMapItem>{MyHashMapItem(key, value)};
        }
        else {
            auto item = find_if(collisions[index]->begin(), collisions[index]->end(), [key](const MyHashMapItem &i) {
                return i.key == key;
            });

            if (item == collisions[index]->end()) {
                collisions[index]->push_back(MyHashMapItem(key, value));
            }
            else {
                item->value = value;
            }
        }
    }

    int get(int key) {
        int index = hash(key);

        if (items[index] == NULL) {
            return -1;
        }
        else if (items[index]->key == key) {
            return items[index]->value;
        }
        else if (collisions[index] != NULL) {
            auto item = find_if(collisions[index]->begin(), collisions[index]->end(), [key](const MyHashMapItem &i) {
                return i.key == key;
            });

            if (item != collisions[index]->end()) {
                return item->value;
            }
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);

        if (items[index] == NULL) {
            return;
        }
        else if (items[index]->key == key) {
            if (collisions[index] == NULL) {
                items[index] = NULL;
            }
            else {
                items[index] = &collisions[index]->back();
                collisions[index]->pop_back();
                if (collisions[index]->empty()) {
                    collisions[index] = NULL;
                }
            }
        }
        else if (collisions[index] != NULL) {
            auto item = find_if(collisions[index]->begin(), collisions[index]->end(), [key](const MyHashMapItem &i) {
                return i.key == key;
            });

            if (item != collisions[index]->end()) {
                collisions[index]->erase(item);
                if (collisions[index]->empty()) {
                    collisions[index] = NULL;
                }
            }
        }
    }
};

class MyHashMap2 {
private:
    int values[1000001];

public:
    MyHashMap2() {
        for (int i = 0, n = sizeof(values) / sizeof(*values); i < n; i++) {
            values[i] = -1;
        }
    }

    void put(int key, int value) {
        values[key] = value;
    }

    int get(int key) {
        return values[key];
    }

    void remove(int key) {
        values[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */