#include "ZXLine.h"

ZXLine::ZXLine(float _x, float _y, float _z, float _m, float _n, float _p)
{
    x = _x;
    y = _y;
    z = _z;
    m = _m;
    n = _n;
    p = _p;
}

ZXLine::~ZXLine()
{
}

// 判定是否共面
bool ZXLine::Coplane(ZXLine l1)
{
    // 初始化矩阵
    matrix << m, l1.m , l1.x - x,
              n, l1.n , l1.y - y,
              p, l1.p , l1.z - z;

    return (matrix.determinant() == 0);
}

// 判别空间关系
SpaceRelation ZXLine::CompareTo(ZXLine l1)
{
    if (!Coplane(l1))
    {
        return SpaceRelation::DIFFSURF;
    }
    else if(m / n / p == l1.m / l1.n / l1.p == (l1.x - x) / (l1.y - y) / (l1.z - z)){
        return SpaceRelation::COINCIDENCE;
    }
    else if(m / n / p == l1.m / l1.n / l1.p &&
         m / n / p != (l1.x - x) / (l1.y - y) / (l1.z - z)) {
        return SpaceRelation::PARALLEL;
    }
    else {
        return SpaceRelation::INTERSECT;
    }
}
