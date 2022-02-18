
#include <iostream>
// #include <gtest/gtest.h>
#include "hw1.h"
#include <vector>
using namespace std;
using namespace algebra ;
using Matrix = std::vector<std::vector<double>>;
// teste khodam
int main(){
    //khodam zadam
    Matrix result1 ;
    Matrix result2 ;

    int a {5};
    int b {5};
    result1={{1,2,3},{3,2,1},{2,1,3}};
    result2={{10,20,3},{3,20,1},{20,1,10},{1,1,1},{2,2,2}};
    // result2={{2,7,4},{10,20,60}};
    // result1 =algebra::random(15 , 20 , -100 , 100 );
    algebra::show(algebra::concatenate(result1,result2,0));

    // algebra::show (result1);
    // double c {10};
    // result2 = algebra::sum(result1 , c);
    // algebra::show(result2); 
    //ende khodam
}


// int main(int argc, char **argv)
// {
    
//     if (true) // make false to run unit-tests
//     {
//         // debug section
//     }
//     else
//     {
//         ::testing::InitGoogleTest(&argc, argv);
//         std::cout << "RUNNING TESTS ..." << std::endl;
//         int ret{RUN_ALL_TESTS()};
//         if (!ret)
//             std::cout << "<<<SUCCESS>>>" << std::endl;
//         else
//             std::cout << "FAILED" << std::endl;
//     }
//     return 0;
//     }
