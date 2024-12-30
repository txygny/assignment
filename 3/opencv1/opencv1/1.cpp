#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
	Mat tx,tx1,tx11,tx2,tx3,tx4;
	Point temp = Point(0, 0);
	int shibieyanse = 1;//=1时为红色，=2时为蓝色

	if (shibieyanse == 1) 
	{ 
		int thecolor[6] = {0,35,45,180,230,255};
		

		VideoCapture capture("1.avi"); 


		while (true)
		{
			capture.read(tx);
			int w = (tx.cols) / 2;
			int h = (tx.rows) / 2;
			resize(tx, tx11, Size(w,h), 0, 0);
		
				
			cvtColor(tx11, tx1, COLOR_BGR2HSV);
			//blur(tx1, tx2, Size(3,3), Point(-1, -1));
			bilateralFilter(tx1, tx2, 0,90, 1.6);
			//GaussianBlur(tx1, tx2,Size(0,0), 2);
			inRange(tx2, Scalar(thecolor[0], thecolor[2], thecolor[4]), Scalar(thecolor[1], thecolor[3], thecolor[5]), tx3);

			//Mat kl = getStructuringElement(MORPH_RECT, Size(5, 5));
			//erode(tx3, tx4, kl);


			vector<vector<Point>> ct;
			vector<Point> a;
			findContours(tx3, ct, RETR_EXTERNAL, CHAIN_APPROX_NONE);
			
			for (int i = 0; i < ct.size(); i++)
			{
				 Rect rect = boundingRect(ct[i]);
				 if (contourArea(ct[i]) < 1) continue;
				 rectangle(tx11, rect, Scalar(0, 0, 255), 3, 8, 0);
				 a.push_back(rect.tl());
				 a.push_back(rect.br());
			}

			Rect bigRect = boundingRect(a);
			Point b, c, d,f;
			b = bigRect.tl();
			c = bigRect.br();
			d = (b + c) / 2;
			if (temp == Point(0, 0)) temp = d;
			f.x = d.x - temp.x + d.x;
			f.y = d.y - temp.y + d.y;
			Rect rect2;
			rect2.x = f.x - (bigRect.size().width / 2);
			rect2.y = f.y - (bigRect.size().height / 2);
			rect2.width = bigRect.size().width;
			rect2.height = bigRect.size().height;
			rectangle(tx11, rect2, Scalar(255, 0, 0), 3, 8, 0);
			circle(tx11, f, 2, Scalar(255, 0, 0), 2);
			rectangle(tx11, bigRect, Scalar(0, 0, 255), 3, 8, 0);
			circle(tx11, d, 2, Scalar(0, 0, 255), 2);
			temp = d;

			imshow("红色实时，蓝色预测", tx11);
			int i = waitKey(3);
			if (i == 27) break;
		}
		return 0;
	}
	else if (shibieyanse == 2) 
	{ 
		int thecolor[6] = { 89,164,40,174,230,255 };

		VideoCapture capture("2.avi");

		while (true)
		{
			capture.read(tx);
			int w = (tx.cols) / 2;
			int h = (tx.rows) / 2;
			resize(tx, tx11, Size(w, h), 0, 0);


			cvtColor(tx11, tx1, COLOR_BGR2HSV);
			//blur(tx1, tx2, Size(3,3), Point(-1, -1));
			bilateralFilter(tx1, tx2, 0, 90, 1.6);
			//GaussianBlur(tx1, tx2,Size(0,0), 2);
			inRange(tx2, Scalar(thecolor[0], thecolor[2], thecolor[4]), Scalar(thecolor[1], thecolor[3], thecolor[5]), tx3);

			//Mat kl = getStructuringElement(MORPH_RECT, Size(5, 5));
			//erode(tx3, tx4, kl);


			vector<vector<Point>> ct;
			vector<Point> a;
			findContours(tx3, ct, RETR_EXTERNAL, CHAIN_APPROX_NONE);

			for (int i = 0; i < ct.size(); i++)
			{
				Rect rect = boundingRect(ct[i]);
				if (contourArea(ct[i]) < 1) continue;
				rectangle(tx11, rect, Scalar(0, 0, 255), 3, 8, 0);
				a.push_back(rect.tl());
				a.push_back(rect.br());
			}

			Rect bigRect = boundingRect(a);
			Point b, c, d, f;
			b = bigRect.tl();
			c = bigRect.br();
			d = (b + c) / 2;
			if (temp == Point(0, 0)) temp = d;
			f.x = d.x - temp.x + d.x;
			f.y = d.y - temp.y + d.y;
			Rect rect2;
			rect2.x = f.x - (bigRect.size().width / 2);
			rect2.y = f.y - (bigRect.size().height / 2);
			rect2.width = bigRect.size().width;
			rect2.height = bigRect.size().height;
			rectangle(tx11, rect2, Scalar(255, 0, 0), 3, 8, 0);
			circle(tx11, f, 2, Scalar(255, 0, 0), 2);
			rectangle(tx11, bigRect, Scalar(0, 0, 255), 3, 8, 0);
			circle(tx11, d, 2, Scalar(0, 0, 255), 2);
			temp = d;

			imshow("红色实时，蓝色预测", tx11);
			int i = waitKey(3);
			if (i == 27) break;
		}
		return 0;
	}

}