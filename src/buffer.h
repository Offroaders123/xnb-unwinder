#pragma once

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cwchar>
#include <span>
#include <string>
#include <vector>

struct Buffer
{
    std::vector<uint8_t> data;
    size_t cursor = 0;

    Buffer();
    Buffer(std::vector<uint8_t> bytes);

    void seek(int bytes);

    int get_bit_position();
    void set_bit_position(int offset);

    std::uint8_t read_byte();
    std::uint8_t peek_byte();

    std::span<uint8_t> read(size_t len);
    std::span<uint8_t> peek(size_t len);

    std::uint32_t read_u32(std::endian endianess = std::endian::little);

    std::uint32_t read_u16(std::endian endianess = std::endian::little);
    std::uint32_t peek_u16(std::endian endianess = std::endian::little);

    std::int32_t read_i32(std::endian endianess = std::endian::little);

    std::int32_t read_7_bit_int();

    std::string read_raw_string(size_t len);
    std::string read_string();
};
