#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;



//////////// Color Detection //////////////////
///hsv space - hui saturation and value

Mat imgHSV, mask;
int hmin = 0, smin = 100, vmin = 100;
int hmax = 19, smax = 255, vmax = 255;

int main() {

	string path = "Resources/lambo.png";
	Mat img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	namedWindow("Trackbars", (640, 200));

	//Below are object detection and color using trackbar. Move it until you get desired color
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);
	while (true) {

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);
		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image mask", mask);
		waitKey(1);
	}

	return 0;
	
}