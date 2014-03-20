

#include "CFaceDetector.h"

namespace fr
{
	CFaceDetector::CFaceDetector(String faceClassifierPath)
	{
		try
		{
			faceClassifier.load(faceClassifierPath);
		}
		catch(...)
		{
			cerr << "Unhandled Error Catched!" << endl;
		}
	}
	void CFaceDetector::detect()
	{
		std::vector<Rect> faces;
		Mat frame_gray;

		cvtColor( lastImage, frame_gray, CV_RGB2GRAY );
		equalizeHist( frame_gray, frame_gray );

		//-- Detect faces
		faceClassifier.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

		lastFace=faces[0];
	}
	void CFaceDetector::Detect(String imagePath)
	{
		lastImage = imread(imagePath,1);
		this->detect();
	}
	void CFaceDetector::StoreLastFace(String path)
	{
		Mat dst;
		lastImage(Rect(lastFace.x,lastFace.y,lastFace.width,lastFace.height)).copyTo(dst);
		imwrite(path , dst );
	}
}