#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;



//////////// Basic Functions //////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 50, 150); //Edge Detector and track bars
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
	dilate(imgCanny, imgDil, kernel);//Dilate - Increase its thickness and errode - decrease its thickness an image
	erode(imgDil, imgErode, kernel);

	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);
	
}

