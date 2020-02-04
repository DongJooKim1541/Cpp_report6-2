#include <iostream>
using namespace std;
#define NAME_LEN 21
class Point {
	int x, y;
public:
	Point() { x = 0; y = 0; }
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};
class ColorPoint :public Point {
	char* color;
public:
	ColorPoint() {
		color = new char[NAME_LEN];
		color = "BLACK";
	}
	ColorPoint(int x1, int y1, char* name1)
		:Point(x1, y1) 
	{
		color = new char[strlen(name1) + 1];
		strcpy_s(color, strlen(name1) + 1, name1);
	}
	~ColorPoint() {
		if (color) {
			delete[] color;
			color = NULL;
		}
	}
	void setPoint(int x1, int y1) {
		move(x1, y1);
	}
	void setColor(char* name1) {
		color = new char[strlen(name1) + 1];
		strcpy_s(color, strlen(name1) + 1, name1);
	}
	void show() {
		cout << color << "색으로 " << "<" << getX() << ", " << getY() << "> 에 위치한 점입니다." << endl;
	}
};
int main() {
	ColorPoint zeroPoint;
	zeroPoint.show();
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("Blue");
	cp.show();
	return 0;
}