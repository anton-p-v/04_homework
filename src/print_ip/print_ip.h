#pragma once

#include <string>


template <
    typename T,
    std::enable_if_t<
        std::is_same_v<T, int8_t>,
        unsigned> = 0>
std::string print_ip(T value_) {
  auto value = static_cast<uint8_t>(value_);

  return std::to_string(value);
}

template <
    typename T,
    std::enable_if_t<
        std::is_same_v<T, int16_t>,
        unsigned> = 1>
std::string print_ip(T value_) {
  auto value = static_cast<uint16_t>(value_);

  uint8_t p1 = (value & 0b11111111'00000000) >> 8;
  uint8_t p2 = (value & 0b00000000'11111111);

  return std::to_string(p1) + '.' + std::to_string(p2);
}

template <
    typename T,
    std::enable_if_t<
        std::is_same_v<T, int32_t>,
        unsigned> = 2>
std::string print_ip(T value_) {
  auto value = static_cast<uint32_t>(value_);

  uint8_t p1 = (value & 0b11111111'00000000'00000000'00000000) >> 24;
  uint8_t p2 = (value & 0b00000000'11111111'00000000'00000000) >> 16;
  uint8_t p3 = (value & 0b00000000'00000000'11111111'00000000) >> 8;
  uint8_t p4 = (value & 0b00000000'00000000'00000000'11111111);

  return std::to_string(p1) + '.' + std::to_string(p2) + '.' +
         std::to_string(p3) + '.' + std::to_string(p4);
}

template <
    typename T,
    std::enable_if_t<
        std::is_same_v<T, int64_t>,
        unsigned> = 3>
std::string print_ip(T value_) {
  auto value = static_cast<uint64_t>(value_);

  uint8_t p1 = (value & 0b11111111'00000000'00000000'00000000'00000000'00000000'00000000'00000000) >> 56;
  uint8_t p2 = (value & 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000) >> 48;
  uint8_t p3 = (value & 0b00000000'00000000'11111111'00000000'00000000'00000000'00000000'00000000) >> 40;
  uint8_t p4 = (value & 0b00000000'00000000'00000000'11111111'00000000'00000000'00000000'00000000) >> 32;
  uint8_t p5 = (value & 0b00000000'00000000'00000000'00000000'11111111'00000000'00000000'00000000) >> 24;
  uint8_t p6 = (value & 0b00000000'00000000'00000000'00000000'00000000'11111111'00000000'00000000) >> 16;
  uint8_t p7 = (value & 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000) >> 8;
  uint8_t p8 = (value & 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'11111111);

  return std::to_string(p1) + '.' + std::to_string(p2) + '.' +
         std::to_string(p3) + '.' + std::to_string(p4) + '.' +
         std::to_string(p5) + '.' + std::to_string(p6) + '.' +
         std::to_string(p7) + '.' + std::to_string(p8);
}

template <
    typename T,
    std::enable_if_t<
        std::is_integral_v<typename T::value_type>,
        unsigned> = 4>
std::string print_ip(T value) {
  std::string result;

  bool flag = false;

  for (const auto& item : value) {
    if (flag) {
      result += '.';
    } else {
      flag = true;
    }

    result += std::to_string(item);
  }

  return result;
}

template <>
std::string print_ip<std::string>(std::string value) {
  return value;
}

template <
    typename T,
    std::enable_if_t<
        std::is_same_v<T, std::tuple<int, int, int, int>>,
        unsigned> = 5>
std::string print_ip(T value) {
  auto p1 = get<0>(value);
  auto p2 = get<1>(value);
  auto p3 = get<2>(value);
  auto p4 = get<3>(value);

  return std::to_string(p1) + '.' + std::to_string(p2) + '.' +
         std::to_string(p3) + '.' + std::to_string(p4);
}
