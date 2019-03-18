#include <iostream>
#include "EigenLine.hpp"
using namespace std;

int main()
{ 
    EigenLine* _l1 = new EigenLine(1,2,3,4,5,6);
    EigenLine* _l2 = new EigenLine(7,8,9,10,11,12);
    cout<<_l1->CompareTo(*_l2)<<endl;
    return 0;
};
