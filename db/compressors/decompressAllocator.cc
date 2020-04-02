#include "db/compressors/decompressAllocator.h"

#include <mutex>

//The following code has been morphed from mojang's implementation.
namespace leveldb::decompression::allocator{
    std::mutex mutex;
    std::vector<std::string> stack;

    std::string get(){
        std::string buffer;
        std::lock_guard<std::mutex> lock(mutex);

        if(!stack.empty()){
            buffer = std::move(stack.back());
            buffer.clear();
            stack.pop_back();
        }
        return buffer;
    }

    void release(std::string&& string){
        std::lock_guard<std::mutex> lock(mutex);
        stack.push_back(std::move(string));
    }

    void prune(){
        std::lock_guard<std::mutex> lock(mutex);
        stack.clear();
    }
}