// 146. LRU Cache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <memory>

using namespace std;

class LRUCache {

    struct CountData {
        int count;
        int key;

        CountData(int c, int k) : count(c), key(k) {}
    };

    std::unordered_map<int, int> cache_;
    int capacity_;

    std::queue<std::shared_ptr<CountData>> opLog_;
    std::unordered_map<int, std::shared_ptr<CountData>> keyCount_;

    void dealWithCache(int key)
    {
        if (!opLog_.empty()) {
            const auto lastKey = opLog_.back();
            if (lastKey->key != key) {
                const auto& it = keyCount_.find(key);
                if (it != keyCount_.end()) {
                    it->second->count++;
                    opLog_.push(it->second);
                }
                else {
                    const auto info = std::make_shared<CountData>(1, key);
                    keyCount_.insert(std::make_pair(key, info));
                    opLog_.push(info);
                }
            }
        }
        else {
            const auto& it = keyCount_.find(key);
            if (it != keyCount_.end()) {
                it->second->count++;
                opLog_.push(it->second);
            }
            else {
                const auto info = std::make_shared<CountData>(1, key);
                opLog_.push(info);
                keyCount_.insert(std::make_pair(key, info));
            }
        }

        while (cache_.size() > capacity_) {
            const auto info = opLog_.front();
            opLog_.pop();

            if (info->count > 1) {
                info->count--;
            }
            else {
                cache_.erase(info->key);
                keyCount_.erase(info->key);
            }
        }
    }

public:
    LRUCache(int capacity) : capacity_(capacity) {
    }

    int get(int key) {
        const auto& it = cache_.find(key);
        if (it != cache_.end()) {
            dealWithCache(key);
            return it->second;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        const auto& it = cache_.find(key);
        if (it != cache_.end()) {
            it->second = value;
        }
        else {
            cache_.insert(std::make_pair(key, value));
        }
        dealWithCache(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
