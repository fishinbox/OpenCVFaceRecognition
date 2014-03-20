#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;

namespace fr
{
	class CFaceDetector
	{
	private: 
		CascadeClassifier faceClassifier;
		Mat lastImage;
		Rect lastFace;
		void detect();
	public: 
		CFaceDetector(String faceClassifierPath);
		void Detect(String imagePath);
		void Detect(Mat image);
		void StoreLastFace(String path);
	}
}