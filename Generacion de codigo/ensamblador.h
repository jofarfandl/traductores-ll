#include "Funciones.h"
#include <iostream>
using namespace std;

//asm ("addl %%ebx, %%eax;" :"=a"(Num1) : "a" (Num1), "b" (Num2) );
void Suma(){
    int var1 = Num1;
    int var2 = Num2;

    __asm ("addl %%ebx, %%eax;" :"=a"(Num1) : "a" (Num1), "b" (Num2) );
    cout <<"El resultado de la suma "<< var1 << "+" << var2 << " en ensamblador es: " << Num1 << endl;
}

//asm ("subl %%ebx, %%eax;" :"=a"(Num1) : "a" (Num1), "b" (Num2) );
void Resta (){
    int var1 = Num1;
    int var2 = Num2;
    __asm ("subl %%ebx, %%eax;" :"=a"(Num1) : "a" (Num1), "b" (Num2));
    cout <<"El resultado de la resta " << var1 << "-" << var2 << " en ensamblador es: " << Num1 << endl;
}

//asm ("imull %%ebx, %%eax;" :"=a"(Num1) : "a" (Num1), "b" (Num2) );
void Multiplicacion (){
    int var1 = Num1;
    int var2 = Num2;
    __asm ("imull %%ebx, %%eax;" :"=a"(Num1) : "a" (Num1), "b" (Num2) );
    cout <<"El resultado de la multiplicacion " << var1 << "*" << var2 << " en ensamblador es: " << Num1 << endl;
}

//asm ("idivl $0x0, %%edx;" "movl %2, %%eax;" "movl %3, %%ebx;" "idivl %%ebx;" : "=a" (Num1), "=d" (Num2) : "g" (Num1), "g" (Num2) );
void Division (int va, int va2){
    int var1 = va;
    int var2 = va2;
    __asm("movl $0x0, %%edx;"
        "movl %2, %%eax;"
        "movl %3, %%ebx;"
        "idivl %%ebx;"
        : "=a" (va), "=d" (va2)
        : "g" (va), "g" (va2)
    );
    cout <<"El resultado de la division " << var1 << "/" << var2 << " en ensamblador es: " << va << endl;
}

//asm ("modl $0x0, %%edx;" "movl %2, %%eax;" "movl %3, %%ebx;" "idivl %%ebx;" : "=a" (Num1), "=d" (Num2) : "g" (Num1), "g" (Num2) );
void Modulo (int va, int va2){
    int var1 = va;
    int var2 = va2;
    __asm("movl $0x0, %%edx;"
            "movl %2, %%eax;"
            "movl %3, %%ebx;"
            "idivl %%ebx;"
            : "=a" (va), "=d" (va2)
            : "g" (va), "g" (va2)
    );
    cout <<"El resultado del modulo " << var1 << "/" << var2 << " en ensamblador es: " << va2 << endl;
}

//asm ("fld %1;" "fsqrt;" "fstp %0;" : "=m" (result) : "m" (Num3) );
void SQRT(float n1){
    float result = 0;
    __asm("fld %1;" "fsqrt;" "fstp %0;" : "=m" (result) : "m" (n1) );
    cout <<"El resultado de la raiz cuadrada de " << n1 << " en ensamblador es: " << result << endl;
}

//asm ("fld %1;" "fld %2;" "fldpi;" "fmul;" "fdiv;" "fsin;" "fstp %0;" : "=m" (result) : "m" (two_right_angles), "m" (degree) );
void SINX(float degree){
    float result, two_right_angles = 180.0f;
    __asm("fld %1;"
            "fld %2;"
            "fldpi;"
            "fmul;"
            "fdiv;"
            "fsin;"
            "fstp %0;"
            : "=m" (result)
            : "m" (two_right_angles), "m" (degree)
    );
    cout <<"El resultado del seno de " << degree << " en ensamblador es: " << result << endl;
}

//asm ("fld %1;" "fld %2;" "fldpi;" "fmul;" "fdiv;" "fstp %0;" : "=m" (radians) : "m" (two_right_angles), "m" (degree) );

void COSX(float degree){
    float result, two_right_angles = 180.0f, radians;
    __asm("fld %1;"
            "fld %2;"
            "fldpi;"
            "fmul;"
            "fdiv;"
            "fstp %0;"////
            : "=m" (radians)
            : "m" (two_right_angles), "m" (degree)
    );
    __asm ( "fld %1;"
            "fcos;"
            "fstp %0;" : "=m" (result) : "m" (radians)
    );
    cout <<"El resultado del coseno de " << degree << " en ensamblador es: " << result << endl;
} 