#ifndef AP_HW1_H
#define AP_HW1_H
#include <vector>
using Matrix = std::vector<std::vector<double>>;
namespace algebra {
    Matrix zeros(size_t , size_t );
    Matrix ones(int , int );
    void show(const Matrix& );
    Matrix sum(const Matrix& , double );
    Matrix random(size_t , size_t , double , double );
    Matrix sum(const Matrix& , const Matrix& );
    Matrix transpose(const Matrix&);
    Matrix minor(const Matrix& , size_t , size_t );
    double determinant(const Matrix&);
    Matrix inverse(const Matrix&);
    Matrix concatenate(const Matrix&, const Matrix& , int);
}

#endif //AP_HW1_H
