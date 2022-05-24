#pragma once
#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include<cmath>
#include<limits>
#include<memory>

//#include "ray.h"
//#include "vec3.h"

using namespace std;

//Constant
const double infinity = numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;


// Utility Functions

/// <summary>
/// 弧度制转换
/// </summary>
/// <param name="degree"></param>
/// <returns></returns>
inline double degrees_to_radians(double degree)
{
	return degree * pi / 180.0;
}

/// <summary>
/// 获取[0, 1) 随机数
/// </summary>
/// <returns></returns>
inline double random_double()
{
	return rand() / (RAND_MAX + 1.0);//血的教训，这里一定要写1.0 ，写成1直接转换成int型，单位圆内点直接循环出不来
}
/// <summary>
/// 返回[min, max)的随机数
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
inline double random_double(double min, double max)
{
	return min + (max - min) * random_double();
}

inline int random_int(int min, int max)
{
	return static_cast<int> (random_double(min, max + 1));
}


/// <summary>
/// 夹掉数据，x 限定在最大最小内
/// </summary>
/// <param name="x"></param>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
inline double clamp(double x, double min, double max)
{
	if (x < min)	return min;
	if (x > max)	return max;
	return x;
}


#include "ray.h"
#include "vec3.h"

#endif