#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int, char**){
	Mat image;
	int metade;

	image = imread("biel.png",CV_LOAD_IMAGE_GRAYSCALE);

	imshow("Entrada", image);

	if(!image.data)
		cout << "nao abriu imagem" << endl;

	metade = image.size().width/2;

	cout <<  metade << " X " << metade << endl;
	  
	Mat m1(image,Rect(0, 0, metade, metade) );
	Mat m2(image,Rect(metade, 0, metade, metade) );
	Mat m3(image,Rect(0, metade, metade, metade) );
	Mat m4(image,Rect(metade, metade, metade, metade) );
		
	Mat imageOut;
	imageOut = image.clone();

	m1.copyTo(imageOut(Rect(metade, 0, metade, metade)));
	m2.copyTo(imageOut(Rect(metade, metade, metade, metade)));
	m3.copyTo(imageOut(Rect(0, metade, metade, metade)));
	m4.copyTo(imageOut(Rect(0, 0, metade, metade)));


	Mat saida;
	equalizeHist(image, imageOut);
	imshow("Saida", imageOut);  

	waitKey();
  return 0;
}


