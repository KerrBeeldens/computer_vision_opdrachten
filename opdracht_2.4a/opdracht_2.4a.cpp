#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

/*	IMPORTANT: The code below is not made by me, but adapted code from ChatGPT.
	
	USED PROMT: "OpenCV in C++: Convert an image to HSV and then save the Hue value 
	to a CSV file with a count for eacht value (0 - 179) so I can make a histogram" 
	and "Can you repeat the same for Saturation and Value, only this time values 
	range from 0 to 255".

	The results of these two prompts were combined by me to create the code below.
*/

int main() {
	// Read the image
	Mat image = imread("../Resources/kerstballen.jpg");

	// Convert the image to HSV
	Mat hsvImage;
	cvtColor(image, hsvImage, COLOR_BGR2HSV);

	// Split the HSV image into separate channels
	vector<Mat> channels;
	split(hsvImage, channels);

	// Extract the Hue channel
	Mat hue = channels[0];

	// Extract the Saturation channel
	Mat saturation = channels[1];

	// Extract the Value channel
	Mat value = channels[2];

	// Create histograms for Hue, Saturation and Value channels
	int histSize_hue = 180; // Hue varies from 0 to 179
	float range_hue[] = { 0, 180 };
	const float* histRange_hue = { range_hue };

	int histSize_saturation_value = 256; // Saturation and Value vary from 0 to 255
	float range_saturation_value[] = { 0, 256 };
	const float* histRange_saturation_value = { range_saturation_value };

	bool uniform = true, accumulate = false;

	Mat hist_hue, hist_saturation, hist_value;
	calcHist(&hue, 1, 0, Mat(), hist_hue, 1, &histSize_hue, &histRange_hue, uniform, accumulate);
	calcHist(&saturation, 1, 0, Mat(), hist_saturation, 1, &histSize_saturation_value, &histRange_saturation_value, uniform, accumulate);
	calcHist(&value, 1, 0, Mat(), hist_value, 1, &histSize_saturation_value, &histRange_saturation_value, uniform, accumulate);

	// Save histograms to CSV files
	ofstream outFileSaturation("saturation_histogram.csv");
	ofstream outFileValue("value_histogram.csv");
	ofstream outFileHue("hue_histogram.csv");

	if (!outFileSaturation.is_open() || !outFileValue.is_open() || !outFileHue.is_open()) {
		cerr << "Error: Unable to open file for writing!" << endl;
		return -1;
	}

	for (int i = 0; i < histSize_hue; ++i) {
		outFileHue << i << "," << hist_hue.at<float>(i, 0) << endl;
	}

	for (int i = 0; i < histSize_saturation_value; ++i) {
		outFileSaturation << i << "," << hist_saturation.at<float>(i, 0) << endl;
		outFileValue << i << "," << hist_value.at<float>(i, 0) << endl;
	}

	outFileHue.close();
	outFileSaturation.close();
	outFileValue.close();

	cout << "Histograms saved to 'hue_histogram.csv', 'saturation_histogram.csv' and 'value_histogram.csv'" << endl;

	return 0;
}
