#include <iostream>

using namespace std;

int main()
{
    float currentX = 0;
    float k = 100000;
    float two=2;
    float step = 2*3.1415926535 / k; 
    float integralSum = 0;
    float minusOne = -1;
    _asm
    {
        mov ecx, 100000
    loop1:

        fld currentX
        fcos
        fld currentX
        fmul

        fld currentX
        fld step
        fadd
        fst currentX

        fcos
        fld currentX
        fmul
        fadd 
        fdiv two

        fmul step

        fld integralSum
        fadd
        fstp integralSum
    loop loop1

    }


    cout << integralSum;
    return 0;
}