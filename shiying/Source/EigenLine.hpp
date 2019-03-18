//
//  EigenLine.hpp
//  testcpp
//
//  Created by 石迎 on 2019/3/18.
//  Copyright © 2019 石迎. All rights reserved.
//

#ifndef EigenLine_hpp
#define EigenLine_hpp

#endif /* EigenLine_hpp */

#include "main.h"

enum SpaceRelation
{
    DIFFSURF, // 异面
    COINCIDENCE, // 共面-重合
    PARALLEL, // 共面-平行
    INTERSECT // 共面-相交
};
class EigenLine
{
    public :
        int x;
        int y;
        int z;
        int m;
        int n;
        int p;
        EigenLine(int _x,int _y,int _z,int _m,int _n,int _p);
        ~EigenLine();
        bool Coplane(EigenLine _l2);
        SpaceRelation CompareTo (EigenLine _l2);
};
