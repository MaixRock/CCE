#include "Quadrangle.h"
#include <math.h>1

Quadrangle::Quadrangle() {

}

Quadrangle::Quadrangle(Point2D p1, Point2D p2, Point2D p3, Point2D p4)
{
	P2D[0] = p1;
	P2D[1] = p2;
	P2D[2] = p3;
	P2D[3] = p4;

	V2D[0] = createVector(p1, p2);
	V2D[1] = createVector(p2, p3);
	V2D[2] = createVector(p3, p4);
	V2D[3] = createVector(p4, p1);

	SideLength[0] = ModuleVector(V2D[0]);
	SideLength[1] = ModuleVector(V2D[1]);
	SideLength[2] = ModuleVector(V2D[2]);
	SideLength[3] = ModuleVector(V2D[3]);
}
Quadrangle::Quadrangle(Vector2D v1, Vector2D v2, Vector2D v3)
{
	P2D[0].x = 0; P2D[0].y = 0;
	P2D[1].x = v1.x; P2D[1].y = v1.y;
	P2D[2].x = v2.x; P2D[2].y = v2.y;
	P2D[3].x = v3.x; P2D[3].y = v3.y;

	V2D[0] = createVector(P2D[0], P2D[1]);
	V2D[1] = createVector(P2D[1], P2D[2]);
	V2D[2] = createVector(P2D[2], P2D[3]);
	V2D[3] = createVector(P2D[3], P2D[0]);

	SideLength[0] = ModuleVector(V2D[0]);
	SideLength[1] = ModuleVector(V2D[1]);
	SideLength[2] = ModuleVector(V2D[2]);
	SideLength[3] = ModuleVector(V2D[3]);
}
Quadrangle::Quadrangle(double L[4], double angle)
{	
	P2D[0].x = 0; P2D[0].y = 0;
	P2D[1].x = L[0] * cos(angle*PI/180); P2D[1].y = L[0] * sin(angle*PI / 180);
	P2D[3].x = L[3]; P2D[3].y = 0;
	/// Решение задачи на поиск пересечения окружностей
	double r1, r2;
	double A, B, C;
	double d, mult;
	Point2D p1, p2, delta, P;
	delta = P2D[1];
	p2 = P2D[3];

	p1.x = 0; p1.y = 0;
	p2.x -= delta.x; p2.y -= delta.y;
	r1 = L[1]; r2 = L[2];

	A = -2 * p2.x;
	B = -2*p2.y;
	C = p2.x*p2.x + p2.y*p2.y +(r1*r1) -(r2*r2);

	P.x = -(A*C) / (A*A + B * B);
	P.y = -(B*C) / (A*A + B * B);

	d = sqrt((r1*r1)-((C*C)/(A*A+B*B)));
	mult = sqrt((d*d) / (A*A + B * B));

	int x, y;
	x = P.x + B * mult;
	y = P.y - A * mult;

	P2D[2].x = x + delta.x;
	P2D[2].y = y + delta.y;
	///

	V2D[0] = createVector(P2D[0], P2D[1]);
	V2D[1] = createVector(P2D[1], P2D[2]);
	V2D[2] = createVector(P2D[2], P2D[3]);
	V2D[3] = createVector(P2D[3], P2D[0]);

	SideLength[0] = ModuleVector(V2D[0]);
	SideLength[1] = ModuleVector(V2D[1]);
	SideLength[2] = ModuleVector(V2D[2]);
	SideLength[3] = ModuleVector(V2D[3]);



}


Quadrangle::~Quadrangle()
{
}

Point2D Quadrangle::getPointN(int N){
	return P2D[N - 1];
}
double Quadrangle::getS(){
	double S = 0;
	S = 0.5*abs(P2D[0].x* P2D[1].y+ P2D[1].x* P2D[2].y+ P2D[2].x* P2D[3].y- P2D[1].x* P2D[0].y - P2D[2].x* P2D[1].y - P2D[3].x* P2D[2].y);
	return S;
}
void Quadrangle::getVectorSide(Vector2D* v){
	for (int i = 0; i < 4; i++) v[i] = V2D[i];
}
double Quadrangle::getLengthSideN(int N){
	return SideLength[N - 1];
}
Diagonal Quadrangle::getLengthDiagonal(){
	Diagonal d;

	d.d1 = LengthPoint(P2D[1], P2D[3]);
	d.d1 = LengthPoint(P2D[0], P2D[2]);

	return d;
}
double Quadrangle::getAngleN(int N){
	int a, b;
	int n;

	isConvex(n);

	N = N - 1;

	if (N == 3) {
		a = 0;
	}
	else a = N + 1;

	if (N == 0) {
		b = 3;
	}
	else b = N - 1;

	Vector2D A, B;

	A = createVector(P2D[N], P2D[a]);
	B = createVector(P2D[N], P2D[b]);

	if (N == n) {
		return 180+(180-AngleVector2D(A, B));
	}
	return AngleVector2D(A, B);
}
double Quadrangle::getAngleSideAB(int N1, int N2){
	return AngleVector2D(V2D[N1-1],V2D[N2-1]);
}
double Quadrangle::getP(){
	double result=0;
	for (int i = 0; i < 4; i++) {
		result += SideLength[i];
	}
	return result;
}
bool Quadrangle::isConvex(){
	if (IC.flag==false) {
		bool flag;
		bool dynamic;
		// Установка первых значений, с которыми проводится сравнение (если знак изменился, то вогнутый)
		if (ScalarPseudo(V2D[3], V2D[0]) >= 0) {
			dynamic = true;
		}
		else dynamic = false;
		flag = dynamic;

		for (int i = 1; i < 4; i++) {
			//Проверка изменения знака псевдо скалярного произведения
			if (ScalarPseudo(V2D[i-1], V2D[i]) >= 0) {
				dynamic = true;
			}
			else dynamic = false;
			//Если изменений не было
			if (flag != dynamic) return false;
		}
		return true;
	}
	else return IC.value;
	
}

void Quadrangle::isConvex(int &number) {
	IC.flag = true;
	bool flag;
	bool dynamic;
	// Установка первых значений, с которыми проводится сравнение (если знак изменился, то вогнутый)
	if (ScalarPseudo(V2D[3], V2D[0]) >= 0) {
		dynamic = true;
	}
	else dynamic = false;
	flag = dynamic;

	for (int i = 1; i < 4; i++) {
		//Проверка изменения знака псевдоскалярного произведения
		if (ScalarPseudo(V2D[i-1], V2D[i]) >= 0) {
			dynamic = true;
		}
		else dynamic = false;
		//Если изменениt было
		if (flag != dynamic) {
			IC.value = false;
			//Проверим, что дальше;
			if (i == 1) 
			{
				if (ScalarPseudo(V2D[i], V2D[i + 1]) >= 0) {
					dynamic = true;
				}
				else dynamic = false;

				if (dynamic == flag) {
					number = i;
				}
				else number = i - 1;
			} 
			else
			{
				number = i;
			}
			return;
		}
	}
	IC.value = true;

	number = -1;
}
///////////////////////////// Чтобы жить было легче /////////////////////////////////////
Vector2D Quadrangle::createVector(Point2D p1, Point2D p2) {
	Vector2D V;

	V.x = p2.x - p1.x;
	V.y = p2.y - p1.y;

	return V;
}
double  Quadrangle::ModuleVector(Vector2D v) {
	return pow((pow(v.x, 2) + pow(v.y, 2)), 0.5);
}
double  Quadrangle::LengthPoint(Point2D p1, Point2D p2) {
	return pow((pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2)), 0.5);
}
double Quadrangle::AngleVector2D(Vector2D v1, Vector2D v2) {
	return acos((v1.x*v2.x + v1.y*v2.y) / (ModuleVector(v1)*ModuleVector(v2)))*180/PI;
}
double Quadrangle::ScalarPseudo(Vector2D v1, Vector2D v2) {
	return v1.x*v2.y - v2.x*v1.y;
}
double Quadrangle::ScalarMult(Vector2D v1, Vector2D v2) {
	return (v1.x*v2.x + v1.y*v2.y);
}
