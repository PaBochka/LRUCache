#include <iostream>
#include "lrucache.h"

int main(int argc, char *argv[]) {
    LRUCache cache(3);
    cache.put("print 1", [](){std::cout << "1\n";});
    cache.put("print 2", [](){std::cout << "2\n";});
    cache.put("print 3", [](){std::cout << "3\n";});

    auto fn = cache.get("print 1");
    fn();
    cache.put("print new", [](){std::cout << "new \n";});
    fn = cache.get("print new");
    fn();
    fn = cache.get("print 3");
    return 0;
}
