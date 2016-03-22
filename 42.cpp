#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image, mask;
  int width, height;
  int nobjects, aux;
  
  CvPoint p;
  image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
  imshow("Original", image);

  if(!image.data){
    cout << "Imagem nao carregou corretamente\n";
    return(-1);
  }

  width=image.size().width;
  height=image.size().height;
  cout << "Tamanho: " << height << " x " << width << endl;
  p.x=0;
  p.y=0;

  floodFill(image, p, 50);
  
  for(int i=0; i<width; i++){
	if(image.at<uchar>(0,i) == 255 || image.at<uchar>(0,i) == 0){
		p.x = i;
		p.y = 0;
		floodFill(image, p, 100);
	}
	if(image.at<uchar>(height-1,i) == 255 || image.at<uchar>(height-1,i) == 0){
		p.x = i;
		p.y = height - 1;
		floodFill(image, p, 100);
	}
	if(image.at<uchar>(i,0) == 255 || image.at<uchar>(i,0) == 0){
		p.x = 0;
		p.y = i;
		floodFill(image, p, 100);
	}
	if(image.at<uchar>(i, height-1) == 255 || image.at<uchar>(i, height-1) == 0){
		p.x = height - 1;
		p.y = i;
		floodFill(image, p, 100);
	}
  }

/*

  // busca objetos com buracos presentes
  nobjects = 1;
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(image.at<uchar>(i,j) == 255){
	      nobjects++;
	      p.x=j;
	      p.y=i;
	      floodFill(image,p,nobjects);	
      }
    }
  }
*/


  imshow("Final", image);
  //imwrite("labeling.png", image);
  waitKey();
  return 0;
}

