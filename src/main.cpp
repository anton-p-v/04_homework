#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <iostream>

#include "print_ip/print_ip.h"


int main(int argc, char const *argv[]) {
  std::cout << print_ip( int8_t{-1} ) << '\n';
  std::cout << print_ip( int16_t{0} ) << '\n';
  std::cout << print_ip( int32_t{2130706433} ) << '\n';
  std::cout << print_ip( int64_t{8875824491850138409} ) << '\n';
  std::cout << print_ip( std::string{"Hello, World!"} ) << '\n';
  std::cout << print_ip( std::vector<int>{100, 200, 300, 400} ) << '\n';
  std::cout << print_ip( std::list<short>{400, 300, 200, 100} ) << '\n';
  std::cout << print_ip( std::make_tuple(123, 456, 789, 0) ) << '\n';

  return 0;
}
