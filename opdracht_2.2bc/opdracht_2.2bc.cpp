#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Basic Functions  //////////////////////

void main() {
	// Load in an image
	string path = "../Resources/example_photo.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil;

	// Convert to grayscale
	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	// Trackbars blur
	int kernelsize = 3, sigma = 1;
	namedWindow("Trackbars blur", (960, 540));
	createTrackbar("Kernel Size", "Trackbars blur", &kernelsize, 25);
	createTrackbar("Sigma", "Trackbars blur", &sigma, 150);

	// Trackbar Kenny
	int thresholdLow = 0, thresholdHigh = 255, appature = 3;
	namedWindow("Trackbars Kenny", (960, 540));
	createTrackbar("Threshold Low", "Trackbars Kenny", &thresholdLow, 255);
	createTrackbar("Threshold Hight", "Trackbars Kenny", &thresholdHigh, 255);
	createTrackbar("Appature", "Trackbars Kenny", &appature, 25);

	while (true) {

		// Blur the image
		GaussianBlur(imgGray, imgBlur, Size(kernelsize * 2 - 1, kernelsize * 2 - 1), sigma);

		// Detect edges
		Canny(imgBlur, imgCanny, thresholdLow, thresholdHigh, appature * 2 - 1);

		// Dilate the image
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imgCanny, imgDil, kernel);

		// Show the results
		namedWindow("Image Blur", WINDOW_NORMAL);
		imshow("Image Blur", imgBlur);
		namedWindow("Image Canny + Dilate", WINDOW_NORMAL);
		imshow("Image Canny + Dilate", imgDil);
		waitKey(1);
	}
}


