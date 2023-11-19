#pragma once

#include <string>
#include <type_traits>


namespace internal {

template <
    typename T, // string
    std::enable_if_t<
        std::is_same_v<decltype(std::declval<T>().npos), const size_t>,
        unsigned> = 0>
std::string print_ip(T value) {
  return value;
}

template <
    typename T, // vector
    std::enable_if_t<
        std::is_same_v<decltype(std::declval<T>().emplace_back()), typename T::value_type&>,
        unsigned> = 1>
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
  
}

template <
    typename T_, // int8_t, int16_t, int32_t, int64_t
    std::enable_if_t<
        std::is_integral_v<T_>,
        unsigned> = 0>
std::string print_ip(T_ value_) {
  using T = std::make_unsigned_t<T_>;

  auto value = static_cast<T>(value_);

  std::string result;

  switch (sizeof(value)) {
    case 8: {
      uint8_t p1 = (value & 0b11111111'00000000'00000000'00000000'00000000'00000000'00000000'00000000) >> 56;
      uint8_t p2 = (value & 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000) >> 48;
      uint8_t p3 = (value & 0b00000000'00000000'11111111'00000000'00000000'00000000'00000000'00000000) >> 40;
      uint8_t p4 = (value & 0b00000000'00000000'00000000'11111111'00000000'00000000'00000000'00000000) >> 32;

      result += std::to_string(p1) + '.' + std::to_string(p2) + '.' +
                std::to_string(p3) + '.' + std::to_string(p4) + '.';
      
      [[fallthrough]];
    }

    case 4: {
      uint8_t p5 = (value & 0b00000000'00000000'00000000'00000000'11111111'00000000'00000000'00000000) >> 24;
      uint8_t p6 = (value & 0b00000000'00000000'00000000'00000000'00000000'11111111'00000000'00000000) >> 16;

      result += std::to_string(p5) + '.' + std::to_string(p6) + '.';
      
      [[fallthrough]];
    }

    case 2: {
      uint8_t p7 = (value & 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000) >> 8;

      result += std::to_string(p7) + '.';
      
      [[fallthrough]];
    }

    case 1: {
      uint8_t p8 = (value & 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'11111111);

      result += std::to_string(p8);
      
      break;
    }
  }

  return result;
}

template <
    typename T, // string, vector
    std::enable_if_t<
        std::is_same_v<decltype(std::declval<T>().at(0)), typename T::value_type&>,
        unsigned> = 1>
std::string print_ip(T value) {
  return internal::print_ip<T>(value);
}

template <
    typename T, // list
    std::enable_if_t<
        std::is_same_v<decltype(std::declval<T>().sort()), void>,
        unsigned> = 2>
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

template <
    typename T, // tuple
    std::enable_if_t<
        (std::tuple_size<T>::value > 0),
        unsigned> = 3>
std::string print_ip(T value) {
  auto p1 = get<0>(value);
  auto p2 = get<1>(value);
  auto p3 = get<2>(value);
  auto p4 = get<3>(value);

  return std::to_string(p1) + '.' + std::to_string(p2) + '.' +
         std::to_string(p3) + '.' + std::to_string(p4);
}
