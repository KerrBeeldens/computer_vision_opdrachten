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

	// Create a kernel (blur)
	Mat_<float> kernelBlur(3, 3);
	kernelBlur << 0.11, 0.11, 0.11, 0.11, 0.11, 0.11, 0.11, 0.11, 0.11;

	// Apply the kernel
	Mat dstBlur;
	filter2D(grayscale, dstBlur, -1, kernelBlur);

	// Create a kernel (edge detection)
	Mat_<float> kernelEdge(3, 3);
	kernelEdge << -1, -1, -1, -1, 8, -1, -1, -1, -1;

	// Apply the kernel
	Mat dstEdge;
	filter2D(dstBlur, dstEdge, -1, kernelEdge);

	// Create a kernel (dilation)
	Mat_<float> kernelDilate(3, 3);
	kernelDilate << 0, 1, 0, 1, 1, 1, 0, 1, 0;

	// Apply the kernel
	Mat dstDilate;
	filter2D(dstEdge, dstDilate, -1, kernelDilate);

	// Display the results
	namedWindow("Blur", WINDOW_NORMAL);
	imshow("Blur", dstBlur);

	namedWindow("Edge Detection", WINDOW_NORMAL);
	imshow("Edge Detection", dstEdge);

	namedWindow("Dilation", WINDOW_NORMAL);
	imshow("Dilation", dstDilate);
	waitKey(0);
}