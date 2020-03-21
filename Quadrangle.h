#pragma once
#include"Data.h"

class Quadrangle
{
private:
	Point2D P2D[4];
	Vector2D V2D[4];
	Side2D S2D[4];
	IsConvex IC;
	double Angle[4];
	double SideLength[4];
	int indexConvex;
	

public:
	Quadrangle(Point2D, Point2D, Point2D, Point2D);
	Quadrangle(Vector2D, Vector2D, Vector2D);
	Quadrangle(double[4], double);
	Quadrangle();


	~Quadrangle();

	Point2D getPointN(int N); // Получение координаты точек по номеру
	double getS(); // Получение площади
	void getVectorSide(Vector2D*); // получение векторов сторон
	double getLengthSideN(int N); // Возращение длины стороны по номеру
	Diagonal getLengthDiagonal(); // Длины диагоналей
	double getAngleN(int N); // Получение угла по номеру вершины
	double getAngleSideAB(int N1, int N2); // Угол между указанными сторонами 
	double getP(); // Получение периметра 
	bool isConvex();
	void isConvex(int&);
	////////////////////////////////


	Vector2D createVector(Point2D, Point2D); // Создание вектора (вектора стороны) по двум точкам
	double ModuleVector(Vector2D); // Длина вектора, стороны
	double LengthPoint(Point2D, Point2D);
	double AngleVector2D(Vector2D, Vector2D);
	double ScalarMult(Vector2D, Vector2D);

	double ScalarPseudo(Vector2D v1, Vector2D v2);

};

