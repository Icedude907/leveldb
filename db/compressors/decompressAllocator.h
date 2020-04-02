#ifndef DECOMPRESSALLOCATOR_H
#define DECOMPRESSALLOCATOR_H

#include <string>
#include <vector>

namespace leveldb::decompression::allocator{
    std::string get();
    void release(std::string&& string);
    void prune();
}

#endif /* DECOMPRESSALLOCATOR_H */