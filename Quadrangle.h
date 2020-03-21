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

	Point2D getPointN(int N); // ��������� ���������� ����� �� ������
	double getS(); // ��������� �������
	void getVectorSide(Vector2D*); // ��������� �������� ������
	double getLengthSideN(int N); // ���������� ����� ������� �� ������
	Diagonal getLengthDiagonal(); // ����� ����������
	double getAngleN(int N); // ��������� ���� �� ������ �������
	double getAngleSideAB(int N1, int N2); // ���� ����� ���������� ��������� 
	double getP(); // ��������� ��������� 
	bool isConvex();
	void isConvex(int&);
	////////////////////////////////


	Vector2D createVector(Point2D, Point2D); // �������� ������� (������� �������) �� ���� ������
	double ModuleVector(Vector2D); // ����� �������, �������
	double LengthPoint(Point2D, Point2D);
	double AngleVector2D(Vector2D, Vector2D);
	double ScalarMult(Vector2D, Vector2D);

	double ScalarPseudo(Vector2D v1, Vector2D v2);

};

