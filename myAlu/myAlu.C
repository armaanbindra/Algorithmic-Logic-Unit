/* 1 Bit ALU Project in C++ ARMAAN BINDRA 11/1/2013 */

#include <iostream>
#include "blogic.H"

using namespace std;

/* A Function(Software) representation of a 1 Bit Alu Circuit With 8 Inputs */
int alu(int F_0,int F_1,int INVA,int ENA,int ENB,int carryIn,int A,int B)
{
    int output;
    output = bor(
    /*1*/band(
              /*1-1*/band(bxor(INVA,band(A,ENA)),band(B,ENB)),
              /*1-2*/band(bnot(F_0),bnot(F_1))
              ),
    /*2*/band(
              /*2-1*/bor(bxor(INVA,band(A,ENA)),band(B,ENB)),
              /*2-2*/band(bnot(F_0),F_1)
              ),
    /*3*/band(
              /*3-1*/bnot(band(B,ENB)),
              /*3-2*/band(F_0,bnot(F_1))
              ),
    /*4*/band(
              /*4-1*/bxor(carryIn,bxor(band(B,ENB),bxor(INVA,band(A,ENA)))),
              /*4-2*/band(F_0,F_1)
              )
              );
    int carry_out;int ans;
    carry_out = bor(band(band(F_0,F_1),bxor(INVA,band(A,ENA)),band(B,ENB)),band(band(F_0,F_1),bxor(band(B,ENB),bxor(INVA,band(A,ENA))),carryIn));
    output = output<<1;
    ans = carry_out+output;
    return ans;
}
/*Function that takes the same 8 arguments as alu(...) and then the return value from a call to it is printed on standard output, together with the syntax for that call*/
void print_call(int F_0,int F_1,int INVA,int ENA,int ENB,int carryIn,int A,int B)
{
    int n;
    n = alu(F_0,F_1,INVA,ENA,ENB,carryIn,A,B);
    cout<<"alu("<<F_0<<", "<<F_1<<", "<<INVA<<", "<<ENA<<", "<<ENB<<", "<<carryIn<<", "<<A<<", "<<B<<") --> "<<n<<endl;
}
/*A blank line and a section label is printed on standard output, then print call is called 8 times to show the output for all possible calls of alu with 
    F0=arg1, F 1=arg2, INV A=arg3, ENA=arg4 and ENB=arg5. 
    The section label has the format:
 
    F0=b, F1=b, INVA=b, ENA=b, ENB=b
    
    Where each b reperesents the value 0 or 1 corresponding to the indicated argument.*/
void print_section(int F_0,int F_1,int INVA,int ENA,int ENB)
{
    cout<<"\nF0="<<F_0<<", F1="<<F_1<<", INVA="<<INVA<<", ENA="<<ENA<<", ENB="<<ENB<<endl;
    print_call(F_0,F_1,INVA,ENA,ENB,0,0,0);
    print_call(F_0,F_1,INVA,ENA,ENB,0,0,1);
    print_call(F_0,F_1,INVA,ENA,ENB,0,1,0);
    print_call(F_0,F_1,INVA,ENA,ENB,0,1,1);
    print_call(F_0,F_1,INVA,ENA,ENB,1,0,0);
    print_call(F_0,F_1,INVA,ENA,ENB,1,0,1);
    print_call(F_0,F_1,INVA,ENA,ENB,1,1,0);
    print_call(F_0,F_1,INVA,ENA,ENB,1,1,1);
}
/*Helper Function That Helps Create All 32 Combinations of the inputs to alu(...)*/
int chooser(int arr[],int pos)
{
    for(int i=0;i<5;i++)
    {
        arr[i]=(pos & (1 << i)) >>i;
    }
}
int main()
{
    int arr[5];
    for(int i=0;i<32;i++)
    {
        chooser(arr,i);
        print_section(arr[4],arr[3],arr[2],arr[1],arr[0]);
    }
}
