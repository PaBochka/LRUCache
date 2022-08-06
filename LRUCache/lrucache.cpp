#include "lrucache.h"
#include <stdexcept>

LRUCache::LRUCache(size_t size) : MAX_SIZE(size) {
    tasks.reserve(MAX_SIZE);
}

void LRUCache::insert(const std::string &task_name, std::function<void()> task) {
    auto iter = lru_values.emplace(lru_values.end(), task_name, task);
    tasks[task_name] = iter;
}

std::function<void ()> &LRUCache::get(const std::string &task_name) {
    auto it = tasks.find(task_name);
    if (it == tasks.end()) {
        throw std::runtime_error("Task " + task_name + " is not exist !");
    }
    if(it->second != lru_values.begin()) {
        lru_values.splice(lru_values.begin(), lru_values, it->second);
    }
    return it->second->task;
}

void LRUCache::put(const std::string &task_name, std::function<void()> task) {
    auto it = tasks.find(task_name);
    if (it == tasks.end()) {
        if (tasks.size() == MAX_SIZE) {
            tasks.erase(lru_values.back().task_name);
            lru_values.pop_back();
        }
        insert(task_name, task);
    }
    else {
        if(it->second != lru_values.begin()) {
            lru_values.splice(lru_values.begin(), lru_values, it->second);
        }
        it->second->task = task;
    }
}
