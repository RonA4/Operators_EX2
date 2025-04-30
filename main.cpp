// Email ---> ronamsalem4@gmail.com
#include <SquareMat/SquareMat.hpp>
using namespace SquareMatrix;

int main()
{
cout << "create matrix M1:" << endl;
SquareMat M1(2);
M1.setMatrix();
cout <<  M1 << endl;
cout << "create matrix M2:" << endl;
SquareMat M2(2);
M2[0][0] = -1; M2[0][1] = 7;
M2[1][0] = 3;  M2[1][1] = -4;
cout << M2 << endl;
// M3=M1+M2
cout << "create matrix M3:M1+M2:" << endl;
SquareMat M3 = M1+M2;
cout << M3 << endl;

cout << "M3=M1-M2:" << endl;
M3 = M1-M2;
cout << M3 << endl;


cout << " M3=-M2:" << endl;
M3 = -M2;
cout << M3 << endl;


cout << " M3=M1*M2:" << endl;
M3 = M1*M2;
cout << M3 << endl;

cout << " M3=scalar*M2:" << endl;
double scalar = 4.0;
M3 = scalar*M2;
cout << M3 << endl;

cout << " M3=M2*scalar" << endl;
M3 = M2*scalar;
cout << M3 << endl;

cout << " M3=M1%M2:" << endl;
M3=M1%M2;
cout <<M3 << endl;


SquareMat M4(2);
M4[0][0] = 4.0; M4[0][1] = 2.0;
M4[1][0] =14.0 ;  M4[1][1] = -10.0;
cout << " M3=M4%scalar:" << endl;
M3 = M4 % scalar;
cout <<M3 << endl;

SquareMat M5(2);
M5[0][0] = 4.0; M5[0][1] = 2.0;
M5[1][0] =16.0 ;M5[1][1] = -12.0;
cout << " M3=M4/scalar:" << endl;
M3 = M5 / scalar;
cout <<M3 << endl;

SquareMat M6(2);
M6[0][0] = 2.0; M6[0][1] = 2.0;
M6[1][0] =2.0 ; M6[1][1] = 2.0;
cout << "M3=M6^power:" << endl;
int power =6;
M3 = M6 ^power;
cout <<M3 << endl;

cout << "++M7:" << endl;
SquareMat M7(2);
M7[0][0] =7.0; M7[0][1] = 7.0;
M7[1][0] =7.0 ; M7[1][1] = 7.0;
cout <<M7 << endl;
SquareMat M8(2) ;
M8 = ++M7;
cout <<M7 << endl;
cout <<M8 << endl;
cout << "M7++:" << endl;
M7[0][0] =4.0; M7[0][1] = 4.0;
M7[1][0] =4.0 ; M7[1][1] =4.0;
cout <<M7 << endl;
M8 = M7++;
cout << M7 << endl;
cout << M8 << endl;
cout << "--M7:" << endl;
M7[0][0] =9.0;  M7[0][1] =9.0;
M7[1][0] =9.0 ; M7[1][1] =9.0;
cout <<M7 << endl;
M8 = --M7;
cout <<M7 << endl;
cout <<M8 << endl;
M7[0][0] =2.0; M7[0][1] = 2.0;
M7[1][0] =2.0 ; M7[1][1] =2.0;
cout << "--M7:" << endl;
cout <<M7 << endl;
M8 = M7--;
cout << M7 << endl;
cout << M8 << endl;
M7[0][0] =-2.0; M7[0][1] = -22.0;
M7[1][0] =7.0 ; M7[1][1] =11.0;
cout << "M7:"<< endl;
cout << M7 << endl;
cout << "~M7:" << endl;
cout <<~ M7  << endl;
cout << "[][]:" << endl;
cout << "before" << endl;
cout << M7 << endl;
cout << M7[1][1] << endl;
cout << M7 << endl;
M7[1][1] = 20.0;
cout << "after:" << endl;
cout << M7 << endl;
cout<<M7[1][1]<<endl;

cout << "M2:" << endl;
M2[0][0] = -1.0; M2[0][1] = 7.0;
M2[1][0] = 3.0;  M2[1][1] = -4.0;
cout << M2<< endl;

double sum_M2 = M2.sum_matrix();
cout << "sum of M2: " << sum_M2 << endl;
cout << "M3:" << endl;
M3[0][0] = 0.5; M3[0][1] = 1.0;
M3[1][0] = 0.5;  M3[1][1] = 3.0;
cout << M3<< endl;
double sum_M3 = M3.sum_matrix();
cout << "sum of M3:" << sum_M3 << endl;

cout << "M3==:M3" << endl;
cout << (M2==M3) << endl;


cout << "M10:  " << endl;
SquareMat M10(3);
M10[0][0] = 3.0; M10[0][1] = 7.0; M10[0][2] =  6.0;
M10[1][0] = 3.0;  M10[1][1] = 4.0; M10[1][2] = 2.0; 
M10[2][0] = 6.0;  M10[2][1] = 6.0; M10[2][2] = 1.0; 
cout << M10<< endl;

double sum_M10 = M10.sum_matrix();
cout << "sum of M10: " << sum_M10 << endl;
cout << "M11:" << endl;
SquareMat M11(2);
M11[0][0] = 5.0;  M11[0][1] = 15.0; 
M11[1][0] = 3.0;  M11[1][1] =15.0;
double sum_M11 = M11.sum_matrix();
cout << "sum of M11:" << sum_M11 << endl;
cout << M11<< endl;
cout << "M10==M11"<< endl;
cout << (M10==M11) << endl;


cout << "M2:" << endl;
M2[0][0] = 7.0; M2[0][1] = 7.0;
M2[1][0] = 4.0;  M2[1][1] = 6.0;
cout << M2<< endl;
cout << "sum of M2: " <<M2.sum_matrix() << endl;
cout << "M3:" << endl;
M3[0][0] = 6.0; M3[0][1] = 4.0;
M3[1][0] = 5.0;  M3[1][1] = 5.0;
cout << M3<< endl;
cout << "sum of M3:" << M3.sum_matrix() << endl;
cout << "M2>M3:" << endl;
cout << (M2>M3) << endl;


cout << "M2:" << endl;
M2[0][0] = 7.0; M2[0][1] = 7.0;
M2[1][0] = 4.0;  M2[1][1] = 6.0;
cout << M2<< endl;
cout << "sum of M2: " <<M2.sum_matrix() << endl;
cout << "M3:" << endl;
M3[0][0] = 7.0; M3[0][1] = 6.0;
M3[1][0] = 4.0;  M3[1][1] = 7.0;
cout << M3<< endl;
cout << "sum of M3:" << M3.sum_matrix() << endl;

cout << "M2>=M3:" << endl;
cout << (M2>=M3) << endl;


cout << "M2:" << endl;
M2[0][0] = 3.0; M2[0][1] = 7.0;
M2[1][0] = 4.0;  M2[1][1] = 6.0;
cout << M2<< endl;
cout << "sum of M2: " <<M2.sum_matrix() << endl;
cout << "M3:" << endl;
M3[0][0] = 7.0; M3[0][1] = 6.0;
M3[1][0] = 4.0;  M3[1][1] = 7.0;
cout << M3<< endl;
cout << "sum of M3:" << M3.sum_matrix() << endl;
cout << "M2<M3:" << endl;
cout << (M2<M3) << endl;

cout << "M2:" << endl;
M2[0][0] = 3.0; M2[0][1] = 7.0;
M2[1][0] = 4.0;  M2[1][1] = 6.0;
cout << M2<< endl;
cout << "sum of M2: " <<M2.sum_matrix() << endl;
cout << "M3:" << endl;
M3[0][0] = 3.0; M3[0][1] = 6.0;
M3[1][0] = 4.0;  M3[1][1] = 7.0;
cout << M3<< endl;
cout << "sum of M3:" << M3.sum_matrix() << endl;
cout << "M2<=M3:" << endl;
cout << (M2<=M3) << endl;
cout << "M3:" << endl;
cout << M3 << endl;
cout << "Det M3:"<< !M3 << endl;

cout << "M3:" << endl;
cout << M3 << endl;
cout << "M4:" << endl;
cout << M4 << endl;
M3+=M4;
cout << M3 << endl;


cout << "M3:" << endl;
cout << M3 << endl;
cout << "M4:" << endl;
cout << M4 << endl;
M3-=M4;
cout << M3 << endl;

cout << "M3:" << endl;
cout << M3 << endl;
cout << "M4:" << endl;
cout << M4 << endl;
M3*=M4;
cout << M3 << endl;

cout << "M3:" << endl;
cout << M3 << endl;
int scal =4;
M3*=scal;
cout <<"M3*=scal:" << endl;
cout << M3 << endl;

cout << "M2:" << endl;
M2[0][0] = 3.0; M2[0][1] = 12.0;
M2[1][0] = 9.0;  M2[1][1] = 6.0;
cout << M2<< endl;
cout << "M3:" << endl;
M3[0][0] = 3.0; M3[0][1] = 3.0;
M3[1][0] = 3.0;  M3[1][1] = 3.0;
cout << M3<< endl;
M2/=M3;
cout <<" M2/=M3:" << endl;
cout << M2 << endl;

cout << "M2:" << endl;
M2[0][0] = 14.0; M2[0][1] = 16.0;
M2[1][0] = 5.0;  M2[1][1] = 22.0;
cout << M2<< endl;
cout << "M3:" << endl;
M3[0][0] = 4.0; M3[0][1] = 4.0;
M3[1][0] = 4.0;  M3[1][1] = 4.0;
cout << M3<< endl;
M2%=M3;
cout <<"M2%=M3:" << endl;
cout << M2 << endl;

cout << "M3:" << endl;
cout << M3 << endl;
int scal2 =4;
M3%=scal2;
cout <<"M2%=scal2:" << endl;
cout << M3 << endl;
return 0;
}