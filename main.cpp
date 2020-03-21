#include <iostream>
#include <cstdlib>
#include "Quadrangle.h"
using namespace std;

void OutLine();

int main() {
	setlocale(0, "");
	Point2D P_Arr[4];
	Vector2D V_Arr[3];
	Quadrangle Q;


	for (/*Бесконечность*/;/*не*/;/*предел*/) {


		cout << "Введите способ создания четырехугольника:" << endl;
		cout << "1 - По 4 точкам" << endl;
		cout << "2 - По 3 векторам" << endl;
		cout << "3 - По 4 сторонам и углу" << endl;
		int Num;
		cout << "\nСпособ: "; cin >> Num;

		if (Num == 1) {
			cout << "Введите точки:\n";

			for (int i = 0; i < 4; i++) {
				cout << i + 1 << ": "; cin >> P_Arr[i].x >> P_Arr[i].y;
			}
			Q = Quadrangle(P_Arr[0], P_Arr[1], P_Arr[2], P_Arr[3]);
		}
		if (Num == 2) {
			cout << "Введите вектора:\n";

			for (int i = 0; i < 3; i++) {
				cout << i + 1 << ": "; cin >> V_Arr[i].x >> V_Arr[i].y;
			}
			Q = Quadrangle(V_Arr[0], V_Arr[1], V_Arr[2]);
		}
		if (Num == 3) {
			double L[4]; double angle;
			cout << "Введите угол: "; cin >> angle;
			cout << "Введиет длины сторон:\n";

			for (int i = 0; i < 4; i++) {
				cout << i + 1 << ": "; cin >> L[i];
			}
			Q = Quadrangle(L, angle);
		}
		cout << "||| ВЫВОД ДАННЫХ КЛАССА |||\n" << endl; OutLine();
		cout << "Площадь = " << Q.getS() << endl; OutLine();
		cout << "Углы: " << endl;

		for (int i = 1; i <= 4; i++) {
			cout << i << ": " << Q.getAngleN(i) << endl;
		} OutLine();

		cout << "Точки:\n";
		for (int i = 1; i <= 4; i++) {
			Point2D P = Q.getPointN(i);
			double Eps = 0.001;
			if (abs(P.x) - Eps < 0) P.x = 0;
			if (abs(P.y) - Eps < 0) P.y = 0;

			cout << i << ": x=" << P.x << "  y=" << P.y << endl;
		}OutLine();

		if (Q.isConvex()) {
			cout << "Выпуклый\n";
			OutLine();
		}
		else {
			cout << "Вогнутый\n";
			OutLine();
		}
		system("pause");
	}

	return 0;
}

void OutLine() {
	cout<<"======================="<<endl;
}