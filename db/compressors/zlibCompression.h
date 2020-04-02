#pragma once

//Notice: Much of the code below is straight from leveldb-mcpe by mojang.

#include <stdint.h>
#include <string>
#include <algorithm>
#include <assert.h>

#include <zlib.h>

//TODO: inline
namespace leveldb::compression::zlib{
    const int compressionLevel = 2;
	const bool raw = false;

    //These can be inline as they are only used once.
    void compress(const char* datain, size_t length, std::string &output);

	bool decompress(const char* input, size_t length, std::string &output);
}