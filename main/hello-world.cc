#include <ctime>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <Eigen/Dense>
// #include <boost/numeric/odeint.hpp>

std::string get_greet(const std::string& who) {
  return "Hello " + who;
}

void print_localtime() {
  std::time_t result = std::time(nullptr);
  std::cout << std::asctime(std::localtime(&result));
}

int main(int argc, char** argv) {
  std::string who = "world";
  if (argc > 1) {
    who = argv[1];
  }
  std::cout << get_greet(who) << std::endl;
  print_localtime();

  Eigen::MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
  return 0;
}
