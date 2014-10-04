/* 1 Bit ALU Project Extra Features in C++ ARMAAN BINDRA 11/1/2013 */

#include <iostream>
#include "blogic.H"

using namespace std;

/* A Function(Software) representation of a 1 Bit Alu Circuit With 6 Inputs */
int alu2(int F_0,int F_1,int F_2,int carryIn,int A,int B)
{
    int output;
    /*I used two bor(..) calls below because the bor(...) function only takes upto 4 arguments whereas in my circuit I want it to take 8, thus I did bor(bor(),bor()) to simulate bor(...) with 8 args*/
    output = bor(bor(
                 /*1*/band(
                           /*1-1*/band(A,B),
                           /*1-2*/band(bnot(F_0),bnot(F_1),bnot(F_2))
                           ),
                 /*2*/band(
                           /*2-1*/bor(A,B),
                           /*2-2*/band(bnot(F_0),F_1,bnot(F_2))
                           ),
                 /*3*/band(
                           /*3-1*/bnot(B),
                           /*3-2*/band(F_0,bnot(F_1),bnot(F_2))
                           ),
                 /*4*/band(
                           /*4-1*/bxor(carryIn,bxor(A,B)),
                           /*4-2*/band(F_0,F_1,bnot(F_2))
                           )),
                 bor(
                 /*5*/band(
                           /*5-1*/bxor(A,B),
                           /*5-2*/band(bnot(F_0),bnot(F_1),F_2)
                           ),
                 /*6*/band(
                           /*6-1*/bnot(band(A,B)),
                           /*6-2*/band(bnot(F_0),F_1,F_2)
                           ),
                 /*7*/band(
                           /*7-1*/bnot(bor(A,B)),
                           /*7-2*/band(F_0,bnot(F_1),F_2)
                           ),
                 /*8*/band(
                           /*8-1*/bnot(A),
                           /*8-2*/band(F_0,F_1,F_2)
                           ))
                 );
    int carry_out;int ans;
    carry_out = bor(band(A,B,band(F_0,F_1,not(F_2))),band(band(F_0,F_1,bnot(F_2)),bxor(A,B),carryIn));
    output = output<<1;
    ans = carry_out+output;
    return ans;
}

/*Function that takes the same 6 arguments as alu2(...) and then the return value from a call to it is printed on standard output, together with the syntax for that call*/
void print_call(int F_0,int F_1,int F_2,int carryIn,int A,int B)
{
    int n;
    n = alu2(F_0,F_1,F_2,carryIn,A,B);
    cout<<"alu2("<<F_0<<", "<<F_1<<", "<<F_2<<", "<<carryIn<<", "<<A<<", "<<B<<") --> "<<n<<endl;
}

/*A blank line and a section label is printed on standard output, then print call is called 8 times to show the output for all possible calls of alu with 
    
 F0=arg1, F1=arg2, F2=arg3
 The section label has the format:
 
 F0=b, F1=b, F2=b
 
 Where each b reperesents the value 0 or 1 corresponding to the indicated argument.*/

void print_section(int F_0,int F_1,int F_2)
{
    cout<<"\nF0="<<F_0<<", F1="<<F_1<<", F2="<<F_2<<endl;
    print_call(F_0,F_1,F_2,0,0,0);
    print_call(F_0,F_1,F_2,0,0,1);
    print_call(F_0,F_1,F_2,0,1,0);
    print_call(F_0,F_1,F_2,0,1,1);
    print_call(F_0,F_1,F_2,1,0,0);
    print_call(F_0,F_1,F_2,1,0,1);
    print_call(F_0,F_1,F_2,1,1,0);
    print_call(F_0,F_1,F_2,1,1,1);
}
/*Helper Function That Helps Create All 8 Combinations of the inputs to alu(...)*/
int chooser(int arr[],int pos)
{
    for(int i=0;i<3;i++)
    {
        arr[i]=(pos & (1 << i)) >>i;
    }
}
int main()
{
    int arr[3];
    for(int i=0;i<8;i++)
    {
        chooser(arr,i);
        print_section(arr[2],arr[1],arr[0]);
    }
}
