#include <ctime>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <Eigen/Dense>
#include <boost/algorithm/cxx11/all_of.hpp>
#include <array>

std::string get_greet(const std::string& who) {
  return "Hello " + who;
}

void print_localtime() {
  std::time_t result = std::time(nullptr);
  std::cout << std::asctime(std::localtime(&result));
}

bool isOdd ( int i ) { return i % 2 == 1; }
bool lessThan10 ( int i ) { return i < 10; }

void assertTrue(bool t) 
{
    if(t) 
        std::cout << "Assertion succeeded" << std::endl;
    else
        throw std::runtime_error("Assertion failed");
}

void assertFalse(bool t)
{
    assertTrue(!t);
}

using namespace boost::algorithm;

int main(int argc, char** argv) 
{
    std::string who = "world";
    if (argc > 1) {
        who = argv[1];
    }
    std::cout << get_greet(who) << std::endl;
    print_localtime();

    // test eigen
    std::cout << "Testing eigen" << std::endl;
    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;

    // test boost
    std::cout << "Testing boost" << std::endl;
    std::array<int,6> c = {0, 1, 2, 3, 14, 15 };
    assertFalse(all_of ( c, isOdd ));
    assertFalse(all_of ( c.begin (), c.end (), lessThan10 ));
    assertTrue(all_of ( c.begin (), c.begin () + 3, lessThan10 ));
    assertTrue(all_of( c.end (), c.end (), isOdd ));
    assertFalse(all_of_equal ( c, 3 ));
    assertTrue(all_of_equal ( c.begin () + 3, c.begin () + 4, 3 ));
    assertTrue(all_of_equal ( c.begin (), c.begin (), 99 ));

    return 0;
}
