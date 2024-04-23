#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	// Create the image
	Mat img(1024, 1024, CV_8UC3, Scalar(255, 255, 255));

	// Draw the ladybug
	circle(img, Point(674, 350), 128, Scalar(0, 0, 0), FILLED); // Head
	line(img, Point(674, 350), Point(725, 200), Scalar(0, 0, 0), 20); // Antenna left
	line(img, Point(674, 350), Point(824, 324), Scalar(0, 0, 0), 20); // Antenna right

	circle(img, Point(700, 275), 16, Scalar(255, 255, 255), FILLED); // Eye left
	circle(img, Point(752, 336), 16, Scalar(255, 255, 255), FILLED); // Eye right
				
	circle(img, Point(512, 512), 256, Scalar(48, 0, 192), FILLED); // Body
	line(img, Point(384, 640), Point(640, 384), Scalar(0, 0, 0), 20); // Wings

	// Dots
	circle(img, Point(350, 550), 24, Scalar(255, 255, 255), FILLED);
	circle(img, Point(550, 350), 24, Scalar(255, 255, 255), FILLED);
	circle(img, Point(450, 500), 24, Scalar(255, 255, 255), FILLED);
	circle(img, Point(400, 400), 24, Scalar(255, 255, 255), FILLED);

	circle(img, Point(674, 474), 24, Scalar(255, 255, 255), FILLED);
	circle(img, Point(474, 674), 24, Scalar(255, 255, 255), FILLED);
	
	circle(img, Point(524, 574), 24, Scalar(255, 255, 255), FILLED);
	circle(img, Point(624, 624), 24, Scalar(255, 255, 255), FILLED);

	// Text with frame
	rectangle(img, Point(128, 800), Point(896, 900), Scalar(48, 0, 192), 5); // Frame
	putText(img, "I <3 Computer Vision", Point(170, 870), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 0), 6);

	// Show the image
	imshow("Ladybug", img);
	waitKey(0);
}

