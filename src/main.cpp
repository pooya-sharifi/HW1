
#include <iostream>
#include <gtest/gtest.h>
#include "hw1.h"
#include <vector>
using namespace std;
using namespace algebra ;
using Matrix = std::vector<std::vector<double>>;




int main(int argc, char **argv)
{
    
    if (false) // make false to run unit-tests
    {
        // teste khodam
        // khodam zadam
        Matrix result1 ;
        Matrix result2 ;

        // int a {5};
        // int b {5};
        result2={{10,20,3},{3,20,1}};
        result1={{-1, 1.5, -1.75, -2}, {-2, 2.5, -2.75, -3}, {3, 3.5, -3.75, -4}, {4, 4.5, 4.75, -5}};
        // algebra::show(result1);
        // result1 =algebra::random(15 , 20 , -100 , 100 );
        algebra::show(algebra::upper_triangular(result1));

        // algebra::show (result1);
        // double c {10};
        // result2 = algebra::sum(result1 , c);
        // algebra::show(result2); 
        // ende khoda
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
    }
