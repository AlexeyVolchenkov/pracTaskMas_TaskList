#include <iostream>
#include <cmath>
using namespace std;

const float g = 9.8;

struct Ball {
	double m;
	double v = 0;
	double h;
};

void init(Ball* ball, double m, double h){
	ball->m = m;
	ball->h = h;
	ball->v = 0;
}
void show(Ball* ball) {
	cout << "h = " << round(ball->h) << endl;
	cout << "v = " << round(ball->v) << endl;
	cout << "------" << endl;
}
void foo(Ball* ball, double m, double h, double percent, int n) {
	percent /= 100;
	init(ball, m, h);
	double E = m * g * h;
	ball->v = sqrt((2 * E) / ball->m);
	//while (round(ball->h) > 0)
	for (; n != 0; n--) {
		show(ball);
		if (n != 1) {
			E -= E * percent;
			ball->h = E / (ball->m * g);
			ball->v = sqrt((2 * E) / ball->m);
		}
	}
}
bool compare(Ball* ball, double h, double v) {
	return round(ball->h) == h && round(ball->v) == v;
}
void test(double start_h, double m, double predict_h, double predict_v, int n, double percent) {
	Ball* ball = new Ball();
	foo(ball, start_h, m, percent, n);
	cout << (compare(ball, predict_h, predict_v) ? "OK" : "FAIL") << endl;
}
int main(){
	test(10, 10, 7, 12, 2, 30);
}