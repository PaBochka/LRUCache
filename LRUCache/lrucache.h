#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <list>
#include <unordered_map>
#include <string>
#include <functional>

class LRUCache {
private:
    struct Node {
        std::string task_name;
        std::function<void()> task;
        Node(const std::string &_task_name, std::function<void()> _task) : task_name(_task_name), task(_task) {}
    };
    const size_t MAX_SIZE;
    std::list<Node> lru_values;
    std::unordered_map<std::string, std::list<Node>::iterator> tasks;
    void insert(const std::string &task_name, std::function<void()> task);

public:
    LRUCache(size_t size);
    ~LRUCache() = default;
    std::function<void()> &get(const std::string &task_name);
    void put(const std::string &task_name, std::function<void()> task);
};

#endif // LRUCACHE_H
