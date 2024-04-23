#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Warp Images  //////////////////////

void main() {
	string path = "../Resources/warped.jpg"; // Warped image
	Mat imgWarped = imread(path);
	Mat matrix, imgFlat;
	float w = 794, h = 1123; // Resolution of the original file

	// Maping the edges of the paper onto the image
	Point2f src[4] = { {221, 11},{1308, 6}, {7, 1338}, {1576, 1317}};
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	// flatten the image
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(imgWarped, imgFlat, matrix, Point(w, h));

	// Display dots on the edges of the paper
	for (int i = 0; i < 4; i++)
	{
		circle(imgWarped, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	// Show the results
	imshow("Image Warped", imgWarped);
	imshow("Image Flat", imgFlat);
	waitKey(0);
}