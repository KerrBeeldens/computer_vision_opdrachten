#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {
	/* Note: loading in an image, video or webcamfeed can not be done at the same time.
	comment out everything except for the operation you want to perform. */

	// Load in an image
	string imagePath = "../Resources/example_photo.jpg";
	Mat img = imread(imagePath);
	imshow("Image", img);
	waitKey(0);

	// Load in a video
	string videoPath = "../Resources/example_video.mp4";
	VideoCapture cap(videoPath);
	Mat video_frame;

	while (true) {

		cap.read(video_frame);
		imshow("Video Frame", video_frame);
		waitKey(40); // 1000 / framerate (25 fps) 
	}

	// Load in a webcam feed
	VideoCapture cap(0);
	Mat webcam;

	while (true) {

		cap.read(webcam);
		imshow("Webcam Feed", webcam);
		waitKey(1);
	}
}