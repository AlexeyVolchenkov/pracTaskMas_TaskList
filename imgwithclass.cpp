#include <iostream>
#include <fstream>
using namespace std;

class Image
{
private:
	int mx;
	int my;
	int* points;
public:
	void createImage(int tmx, int tmy) {
		mx = tmx;
		my = tmy;
		points = new int[tmx * tmy]{ 0 };
	}

	void showImage() {
		for (int y = 0; y < my; y++) {
			for (int x = 0; x < mx; x++) {
				cout << points[y * mx + x] << " ";
			}
			cout << endl;
		}
	}

	void setPointImage(int x, int y, int color) {
		points[y * mx + x] = color;
	}

	int getPointImage(int x, int y, int color) {
		return points[y * mx + x] = color;
	}

	void saveToPnmFile(string fileName) {
		fstream file;
		file.open(fileName);
		file << "P1" << endl;
		file << mx << " " << my << endl;
		for (int y = 0; y < my; y++) {
			for (int x = 0; x < mx; x++) {
				file << points[y * mx + x] << " ";
			}
			file << endl;
		}
		file.close();
	}
};

int main() {
	Image img;
	img.createImage(6, 10);
	img.setPointImage(5, 9, 1);
	img.showImage();
	img.saveToPnmFile("pic1.pnm");
}