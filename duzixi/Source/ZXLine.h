#pragma once

#include <Eigen/Dense>

using namespace Eigen;

// 两条空间直线的关系
enum SpaceRelation
{
    DIFFSURF, // 异面
    COINCIDENCE, // 共面-重合
    PARALLEL, // 共面-平行
    INTERSECT // 共面-相交
};

class ZXLine
{
    /*
    第i条直线的空间方程
    x - xi    y - yi    z - zi
    ------- = ------- = -------
      mi        ni        pi
    */

public:
    ZXLine(float _x, float _y, float _z, float _m, float _n, float _p);
    ~ZXLine();

    // 判定是否共面
    bool Coplane(ZXLine l1);

    // 判别空间关系
    SpaceRelation CompareTo(ZXLine l1);

    float x;
    float y;
    float z;
    float m;
    float n;
    float p;

private:
    // 矩阵
    Matrix3f matrix;

};
