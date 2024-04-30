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

	// Apply Gaussian blur
	Mat gaussianSigma3, gaussianSigma5, gaussianSigma10, gaussianSigma20;
	GaussianBlur(grayscale, gaussianSigma3, Size(5, 5), 3);
	GaussianBlur(grayscale, gaussianSigma5, Size(5, 5), 5);
	GaussianBlur(grayscale, gaussianSigma10, Size(5, 5), 10);
	GaussianBlur(grayscale, gaussianSigma20, Size(5, 5), 20);

	// Display the result
	namedWindow("Image sigma=3", WINDOW_NORMAL);
	imshow("Image sigma=3", gaussianSigma3);

	namedWindow("Image sigma=5", WINDOW_NORMAL);
	imshow("Image sigma=5", gaussianSigma3);

	namedWindow("Image sigma=10", WINDOW_NORMAL);
	imshow("Image sigma=10", gaussianSigma10);

	namedWindow("Image sigma=20", WINDOW_NORMAL);
	imshow("Image sigma=20", gaussianSigma10);

	waitKey(0);
}