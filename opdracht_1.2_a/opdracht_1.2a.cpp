#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {

	string imagePath = "../Resources/example_photo.jpg";
	Mat img = imread(imagePath);
	Mat imgResize, imgCrop;

	resize(img, imgResize, Size(1280, 720)); // Decrease from 1080p to 720p

	Rect roi(1475, 75, 300, 400); // Select the green plume 
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);
	waitKey(0);
}