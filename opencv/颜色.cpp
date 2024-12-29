#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture capture(0);
	Mat tx,mh,tx1;
	int thecolor[][6] =
	{
		{0,10,43,255,46,255},//red
		{156,180,43,255,46,255},//red
		{35,77,150,255,200,255},//green
		{100,124,43,255,46,255},//blue
	};
	while (true) 
	{
		capture.read(tx);
		flip(tx, tx, 1);
		

		cvtColor(tx, tx1, COLOR_BGR2HSV);
		GaussianBlur(tx1,tx1,Size(0,0),7);

		Mat red, blue, green,kl;
		inRange(tx1, Scalar(thecolor[0][0], thecolor[0][2], thecolor[0][4]), Scalar(thecolor[0][1], thecolor[0][3], thecolor[0][5]), red);
		inRange(tx1, Scalar(thecolor[1][0], thecolor[1][2], thecolor[1][4]), Scalar(thecolor[1][1], thecolor[1][3], thecolor[1][5]), red);
		inRange(tx1, Scalar(thecolor[2][0], thecolor[2][2], thecolor[2][4]), Scalar(thecolor[2][1], thecolor[2][3], thecolor[2][5]), green);
		inRange(tx1, Scalar(thecolor[3][0], thecolor[3][2], thecolor[3][4]), Scalar(thecolor[3][1], thecolor[3][3], thecolor[3][5]), blue);
		

		kl = getStructuringElement(MORPH_RECT, Size(3, 3));
		morphologyEx(red, red, MORPH_CLOSE, kl);
		morphologyEx(red, red, MORPH_OPEN, kl);
		morphologyEx(green, green, MORPH_CLOSE, kl);
		morphologyEx(green, green, MORPH_OPEN, kl);
		morphologyEx(blue, blue, MORPH_CLOSE, kl);
		morphologyEx(blue, blue, MORPH_OPEN, kl);

		imshow("red", red);
		imshow("green", green);
		imshow("blue", blue);

		vector<vector<Point>> redcs;
		vector<vector<Point>> greencs;
		vector<vector<Point>> bluecs;
		findContours(red, redcs, RETR_EXTERNAL,CHAIN_APPROX_NONE);
		findContours(green, greencs, RETR_EXTERNAL, CHAIN_APPROX_NONE);
		findContours(blue, bluecs, RETR_EXTERNAL, CHAIN_APPROX_NONE);
		
		drawContours(tx, redcs, -1, Scalar(0, 0, 255), 3);
		drawContours(tx, greencs, -1, Scalar(255, 0, 0), 3);
		drawContours(tx, bluecs, -1, Scalar(255, 0, 0), 3);

		imshow("tx", tx);
		int c = waitKey(100);
		if (c == 27)
		{
			break;
		}
	}
	destroyAllWindows();
	capture.release();
	
	return 0;
}