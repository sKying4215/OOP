#include "stdafx.h"
#include "ZXLine.h"

int main()
{
    ZXLine l1(0,0,0,1,2,3);
    ZXLine l2(0,0,0,2,4,6);
    cout << l1.CompareTo(l2) << endl;
	  system("pause");
	  return 0;
}
