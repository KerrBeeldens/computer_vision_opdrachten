#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {
	// Load in an image
	string imagePath = "../Resources/example_photo.jpg";
	Mat img = imread(imagePath);
	
	// Convert to grayscale
	Mat grayscale;
	cvtColor(img, grayscale, COLOR_BGR2GRAY);

	// Display the result
	namedWindow("Image", WINDOW_NORMAL);
	imshow("Image", grayscale);
	waitKey(0);
}