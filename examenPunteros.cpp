#include<iostream>
int main(void){
    int a,b;
    int *ptr1=NULL;
    int *ptr2=NULL;
    int **pptr=NULL;
    int A[5]={1,2,3,4,5};
    ptr1=&a;
    ptr2=&b;
    // ptr1=5;         // ERROR: no se puede asignar int a int* sin cast
    std::cout<<ptr1<<"\n";
    *ptr2=5;
    *ptr1=*ptr2;
    std::cout<<a<<"\n";
    std::cout<<b<<"\n";
    // pptr=ptr1;      // ERROR: ptr1 es int*, pptr necesita int**
    //pptr=&b;        // ERROR: &b es int*, pptr necesita int**
    pptr=&ptr2;
    **pptr+=5;
    std::cout<<pptr<<"\n";
    std::cout<<*pptr<<"\n";
    std::cout<<**pptr<<"\n";
    *pptr=ptr1;
    **pptr+=10;
    std::cout<<a<<"\n";
    std::cout<<b<<"\n";
    *pptr=ptr2;
    ptr2=&a;
    std::cout<<*ptr1<<"\n";
    std::cout<<*ptr2+4<<"\n";
    a=2;
    b=*ptr2+3;
    std::cout<<*pptr<<"\n";
    std::cout<<**pptr<<"\n";
    std::cout<<ptr1<<"\n";
    std::cout<<ptr2<<"\n";
    **pptr+=1;
    std::cout<<*ptr1<<"\n";
    std::cout<<*ptr2<<"\n";
    a=8;
    b=6;
    pptr=&ptr1;
    **pptr-=3;
    std::cout<<pptr<<"\n";
    std::cout<<*ptr1<<"\n";
    std::cout<<*ptr2<<"\n";
    std::cout<<b<<"\n";
    std::cout<<a<<"\n";
    std::cout<<**pptr<<"\n";
    ptr1=A;
    pptr=&ptr1;
    // std::cout<<*(*(pptr+3));  // ERROR: aritmética fuera de rango, comportamiento indefinido (posiblemente  *(*pptr+3))
    std::cout<<*ptr1<<"\n";
    std::cout<<(ptr1+3)<<"\n";
    for(int i=0;i<5;i++)
        *(*pptr+i)=*(*pptr+i)+1;
    std::cout<<*(ptr1+1)<<"\n";
    std::cout<<*(*pptr+2)<<"\n";
    std::cout<<(*pptr+2)<<"\n";
    std::cout<<(ptr1+4)<<"\n";
    return 0;
}
