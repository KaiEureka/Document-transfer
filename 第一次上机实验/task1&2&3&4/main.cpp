#include <iostream>
#include "a.h"
using namespace std; 

int main(int argc,char * argv[])
{
    A aA;

    if (argc>1) {
        aA.Display(argv[1]);
    } else {
        aA.Display();
    }

    cout<<sizeof(A)<<endl;
    
    return 0;
}
