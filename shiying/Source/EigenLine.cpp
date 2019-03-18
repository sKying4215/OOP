//
//  EigenLine.cpp
//  testcpp
//
//  Created by 石迎 on 2019/3/18.
//  Copyright © 2019 石迎. All rights reserved.
//

#include "EigenLine.hpp"
#include <Eigen/Dense>
using Eigen::MatrixXf;

EigenLine::EigenLine(int _x,int _y,int _z,int _m,int _n,int _p)
{
    x = _x;
    y = _y;
    z = _z;
    m = _m;
    n = _n;
    p = _p;
};
EigenLine::~EigenLine(){
    
};

bool EigenLine::Coplane (EigenLine _l2)
{
    MatrixXf a(3, 3);
    a<< m, _l2.m, (_l2.x-x),
    n, _l2.n, (_l2.y-y),
    p, _l2.p, (_l2.z-z);
    return a.determinant() == 0;
}

// 判别空间关系
SpaceRelation EigenLine::CompareTo(EigenLine _l2)
{
    if (!Coplane(_l2))
    {
        return SpaceRelation::DIFFSURF;
    }
    else if(m / n / p == _l2.m / _l2.n / _l2.p == (_l2.x - x) / (_l2.y - y) / (_l2.z - z)){
        return SpaceRelation::COINCIDENCE;
    }
    else if(m / n / p == _l2.m / _l2.n / _l2.p &&
            m / n / p != (_l2.x - x) / (_l2.y - y) / (_l2.z - z)) {
        return SpaceRelation::PARALLEL;
    }
    else {
        return SpaceRelation::INTERSECT;
    }
};
