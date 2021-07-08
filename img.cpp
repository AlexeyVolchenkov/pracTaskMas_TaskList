#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
const int g = 10;

class Image {
    int mx;
    int my;
    int* points;
public:
    ~Image()
    {
        //delete[] points;
    }
    void createImage(int tmx, int tmy)
    {
        mx = tmx;
        my = tmy;
        points = new int[tmx * tmy]{ 0 };
    }

    void showImage()
    {
        for (int y = 0; y < my; y++)
        {
            for (int x = 0; x < mx; x++)
            {
                cout << points[y * mx + x] << " ";
            }
            cout << endl;
        }
    }

    void setPointImage(int x, int y, int color)
    {
        points[y * mx + x] = color;
    }

    int getPointImage(int x, int y)
    {
        return points[y * mx + x];
    }

    void saveToPnmFile(string fileName)
    {
        fstream file;
        file.open(fileName);
        file << "P1" << endl;
        file << mx << " " << my << endl;
        for (int y = 0; y < my; y++)
        {
            for (int x = 0; x < mx; x++)
            {
                file << points[y * mx + x] << " ";
            }
            file << endl;
        }
        file.close();
    }
};

class Ball {
    double m;
    double v = 0;
    double h;
public:
    Ball(double m = 0, double h = 0)
    {
        this->m = m;
        this->h = h;
    }

    void show()
    {
        cout << "h=" << round(h) << endl;
        cout << "v=" << round(v) << endl;
        cout << "=====" << endl;
    }

    void foo(double percent, int n, Image& img, int w)
    {
        double E = m * g * h;
        v = sqrt((2 * E) / m);

        for (int i = 0; i < n; i++)
        {
            show();
            for (int j = 0; j <= w; j++)
            {
                if (j >= abs(round(h) - w))
                {
                    img.setPointImage(i, j, 1);
                }
            }

            if (i != n - 1)
            {
                E -= E * (percent / 100);
                h = E / (m * g);
                v = sqrt((2 * E) / m);
            }
        }
    }
};


int main()
{
    Image img;
    int w = 10;
    img.createImage(5, w);
    Ball ball(10, 10);
    ball.foo(50, 3, img, w);

    img.showImage();
    img.saveToPnmFile("pic1.pnm");
    return 0;
}
