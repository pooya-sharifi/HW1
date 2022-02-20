// #include "hw1.h"
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;

// man neveshtam ina ro ke in zire
namespace algebra
{
    using Matrix = std::vector<std::vector<double>>;

    Matrix zeros(size_t n, size_t m)
    {
    // int n {1};
    // int m {2};

    using Matrix = std::vector<std::vector<double>>;

    Matrix a ;

    vector<double> vect;
    

    for (int i{0} ; i < m ;i++)
    {
        vect.push_back(0);
    }
    for (int j{0}; j < n ; j++)
    {
        a.push_back(vect);   


    }

    return a;

    }

    Matrix ones(size_t n, size_t m)
    {
    using Matrix = std::vector<std::vector<double>>;

    Matrix a ;

    vector<double> vect;
    

    for (int i{0} ; i < m ;i++)
    {
        vect.push_back(1);
    }
    for (int j{0}; j < n ; j++)
    {
        a.push_back(vect);   


    }
    return a ;

    }

    Matrix random(size_t n, size_t m, double min, double max)
    {
        Matrix a ;
        vector<double> vect;
        std::random_device rd;
        std::mt19937 mt(rd());
        if (min > max)
        {
            std::cout << "logic error"<< endl;
            throw logic_error("Error");

        }
        if (min <= max)
        {
            std::uniform_real_distribution<double> dist(min, max); 

            for (int i{0} ; i < m ; i++)
            {
                    vect.push_back(0);
            }
        
            for (int j{0}; j < n ; j++)
            {
                for (int i{0} ; i < m ;i++)
                {
                    vect[i]=dist(mt);
                }

                a.push_back(vect);
                
            }
            
        
        
        }
        
        return a;
            
    }

    void show(const Matrix& matrix){
    int rows = matrix. size() ;
    int cols = matrix[0].size();

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j)
        {
            std::cout << setprecision(2) ;
            std::cout << setw(5) ;
            std::cout << matrix[i][j];
            
        }
            std::cout << std::endl ;

    }
        
    }

    Matrix multiply(const Matrix& matrix, double c)
    {
    if (matrix.empty()==true)
        {
        Matrix result{matrix};
        return result;
        }
    int rows =matrix. size();
    int cols =matrix[0]. size();
    Matrix result{zeros(rows,cols)};
    for(int i=0;i<rows;i++)    
    {    
        for(int j=0;j<cols;j++)    
        {    
            result [i][j]=0;   
            //nemidoonam in harekat doroste ya bayad push back konam 
            
            result[i][j]+=matrix[i][j]*c;    
                
        }       
    }    
        return result;
    }


    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2)
    {
        Matrix result;
        if (matrix1.empty()==true || matrix2.empty()==true)
        {
            result={};
            return result;
        }
        
        int rows1 =matrix1.size();
        int cols1 =matrix1[0].size();
        cout << rows1<<"        "<<cols1;
        int rows2 =matrix2.size();
        int cols2 =matrix2[0].size();

        result=zeros(rows1,cols2);

        if (cols1!=rows2)
        {
            cout << "Error! column of first matrix not equal to row of second.";
            std::cout << "logic error"<< endl;
            throw logic_error("Error");
        
        }


        for(int i = 0; i < rows1; ++i)
            for(int j = 0; j < cols2; ++j)
                for(int k = 0; k < cols1; ++k)
                {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }

        return result;
    }

    Matrix sum(const Matrix& matrix, double c){
    Matrix result,zerom;
    if (matrix.empty()==true)
    {
        result=matrix;
        return result;
    }
    int rows =matrix. size();
    int cols =matrix[0]. size();

    zerom = zeros(rows,cols);

    for(int i=0;i<rows;i++)    
    {    
        for(int j=0;j<cols;j++)    
        {    
            
            //nemidoonam in harekat doroste ya bayad push back konam 
            
            zerom[i][j]+=matrix[i][j]+c;    
                
        }       
    }    
        return zerom;


    }

    Matrix sum(const Matrix& matrix1, const Matrix& matrix2)
    {
        Matrix result,zerom;
        if (matrix1.empty()==true && matrix2.empty()==true)
        {
            result={};
            return result;
        }
        if (matrix1.empty()==true || matrix2.empty()==true)
        {
            throw logic_error("Error");
        }
        
        
        int rows1 =matrix1. size();
        int cols1 =matrix1[0]. size();
        int rows2 =matrix2. size();
        int cols2 =matrix2[0]. size();

    
        if (cols1!=cols2 && rows1!=rows2)
        {
            cout << "Error! matrix dont have the same dimentions";
            throw logic_error("Error"); 
        
        }
        
        zerom = zeros(rows1,cols1);

        for(int i=0;i<rows1;i++)    
        {    
            for(int j=0;j<cols1;j++)    
            {    
            
            //nemidoonam in harekat doroste ya bayad push back konam 
            
                zerom[i][j]+=matrix1[i][j]+matrix2[i][j];    
                
            }       
        }    
        return zerom;


    }
    Matrix transpose(const Matrix& matrix)
    {
        Matrix A,B;
        if (matrix.empty()==true)
        {
            B={};
            return B;
        }
        int rows = matrix. size();
        int cols = matrix[0]. size();
        A=zeros(rows,cols);
        B=zeros(cols,rows);
        A=matrix;
        
        int i, j;
        for (i = 0; i < cols; i++)
            for (j = 0; j < rows; j++)
                B[i][j] = A[j][i];

        return B;

    }
    Matrix minor(const Matrix& matrix, size_t n, size_t m)
    {
        //age faghat 2*2 bashe
        size_t rows = matrix. size();
        size_t cols = matrix[0]. size();
        Matrix A;
        A=zeros(rows-1,cols-1);
        int crow =0;
        int ccol =0;
        for (size_t i = 0; i < rows; i++)
        {
            
            for (size_t j = 0; j < cols; j++)
            {
                
                if ( n!=i && m!=j)
                {
                    A[crow][ccol]=matrix[i][j];
                    ccol++;
                    if (ccol==(cols-1))
                    {
                        ccol=0;
                        crow++;
                    }
                    
                }

            }
            
            
        }
        
        return A;
        
        
        
    }
    double determinant(const Matrix& matrix){
        double det {0};
        if (matrix.empty()==true)
        {
            det=1;
            return det;
        }
        Matrix getmin;
        size_t rows = matrix. size();
        size_t cols = matrix[0]. size();
        if (rows!=cols)
        {
            throw logic_error("error");
        }
        
        int sign {1};
        if (rows == 1 && cols==1){
            det=matrix[0][0];
            return det; 
        }
        getmin=zeros(rows-1,cols-1);
        for (int f = 0; f < cols; f++)
        {
            // Getting Cofactor of mat[0][f]
            getmin=minor(matrix,0,f);
            det += sign * matrix[0][f]* determinant(getmin);
    
            // terms are to be added with alternate sign
            sign = -sign;
        }    
        
    return det;
    }
    Matrix inverse(const Matrix& matrix){
        Matrix inv;
        if (matrix.empty()==true)
        {
            inv={};
            return inv;
        }
        size_t rows = matrix. size();
        size_t cols = matrix[0]. size();
        inv=zeros(rows,cols);
        Matrix invout;
        invout=zeros(rows,cols);
        double sign=1;
        if (rows!=cols){
            cout<<"this matrix doesnt have an inverse"<<endl;
            throw logic_error ("error");
            return matrix;
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                sign=((i+j)%2==0)? 1: -1;
                inv[j][i]=sign*determinant(minor(matrix,i,j));
                
                
        }
        if (determinant(matrix)==0)
        {
            throw logic_error("error");
        }
        
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
            
                invout[i][j]=(inv[i][j]/(determinant(matrix)));
            }
        }
        
        return invout;    
        
    }
    Matrix concatenate(const Matrix& matrix1, const Matrix& matrix2, int axis ){
        //=0 esh ghalat nist?
        //age cols ha baham barabar nabashan fekr konam segmentation error bokhorim
        Matrix result ;
        size_t rows1 = matrix1. size();
        size_t cols1 = matrix1[0]. size();
        size_t rows2 = matrix2. size();
        size_t cols2 = matrix2[0]. size();
        if (axis==0)
        {
            if (cols1!=cols2)
            {
                throw logic_error("Error");
            }
            
            for (size_t i = 0; i < rows1; i++)
            {
                vector<double> vec;
                for (size_t j = 0; j < cols1; j++)
                {
                
                    vec.push_back(matrix1[i][j]);
                
                }
            result.push_back(vec);
        
                
            }
            for (size_t i = 0; i < rows2; i++)
            {
                vector<double> vec;
                for (size_t j = 0; j < cols2; j++)
                {
                vec.push_back(matrix2[i][j]);
                
                }
            result.push_back(vec);
        
                
            }
            
        
        }
        if (axis==1)
        {
            if (rows1!=rows2)
            {
                throw logic_error("Error");
            }
            for (size_t i = 0; i < rows1; i++)
            {
                vector<double> vec;
                for (size_t j = 0; j < cols1; j++)
                {
                    vec.push_back(matrix1[i][j]);
                    
                }
                for (size_t k = 0; k < cols2; k++)
                {
                    vec.push_back(matrix2[i][k]);  
                }
                result.push_back(vec);
            }
            
        }
        
        return result;
    }
    Matrix ero_swap(const Matrix& matrix, size_t r1, size_t r2){
        int rows = matrix. size();
        int cols = matrix[0]. size();
        cout << rows<<endl;
        cout << cols<<endl;

        Matrix matstandin {zeros(rows,cols)};
        matstandin=matrix;
        if (r1+1>rows || r2+1>rows)
        {
            throw logic_error("Error");
            std::cout<<"out of range";
        }
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                if (i==r1)
                {
                    cout << i<<"    "<<j<<endl;

                    matstandin[r2][j]=matrix[i][j];
                    matstandin[r1][j]=matrix[r2][j];
                }
                
            }
            
        }
        
        return matstandin;
    }
    Matrix ero_multiply(const Matrix& matrix, size_t r, double c){
        int rows = matrix. size();
        int cols = matrix[0]. size();
        Matrix matstandin{zeros(rows,cols)} ;
        if (r>rows )
        {
            throw logic_error("Error");
            std::cout<<"out of range";
        }
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                if (i==r)
                {
                    matstandin[r][j]=matrix[r][j]*c;
                }
                else{
                    matstandin[i][j]=matrix[i][j];
                }
                
            }
            
            
        }
        return matstandin;
    }
    Matrix ero_sum(const Matrix& matrix, size_t r1, double c, size_t r2){
        
        int rows = matrix. size();
        int cols = matrix[0]. size();
        Matrix matstandin {matrix};
        if (r1>rows || r2>rows)
        {
            throw logic_error("Error");
            std::cout<<"out of range";
        }
        for (size_t j = 0; j < cols; j++)
        {
            matstandin[r2][j]+=matrix[r1][j]*c;
        }
        return matstandin;

    }
    Matrix upper_triangular(const Matrix& matrix){
        
        if (matrix.empty()==true)
        {
            Matrix inv {};
            return inv;
        }
        int rows = matrix. size();
        int cols = matrix[0]. size();
        if (rows!=cols)
        {
            throw logic_error("error");
        }
        Matrix matstandin {matrix};
        int counter {1};
        for (double i = 0; i < rows; i++)
        {
            if (matrix[i][i]==0)
            {
                size_t m ;
                for ( m = 0; m < rows; m++)
                {
                    if(matstandin[m][i]!=0){
                            break;
                        }

                }
                
                matstandin=ero_swap(matstandin,i,m);
            }
            if (matrix[i][i]!=0)
            {
                for (size_t j = 0; j < cols; j++)
                    {
                        for (size_t i = 1; i < rows; i++)
                        {
                            if(i+j==rows){
                            break;
                            }

                        double a =matstandin[i+j][j];
                        double b =matstandin[j][j];
                        double c=a/b;
                        matstandin=ero_sum(matstandin,j,-c,i+j);
                        }
                        
            
            
                    } 
            
            }
            
            
            
                

            
        }
        
        
        
        return matstandin;

    }
}



