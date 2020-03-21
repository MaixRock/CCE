#pragma once

#include<vector>
#define PI 3.14159265

struct Point2D {
	double x;
	double y;
};

struct Vector2D {
	double x;
	double y;
};

struct Side2D {
	Point2D A;
	Point2D B;
};
struct Angle2D {
	Vector2D v1;
	Vector2D v2;

	double angle;
};
struct Diagonal
{
	double d1;
	double d2;
};
struct IsConvex {
	bool flag=false;
	bool value;
};
