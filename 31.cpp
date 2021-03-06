#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image;
  Vec3b val;
  CvPoint p1, p2;

  image= imread("biel.png",CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data)
    cout << "nao abriu bolhas.png" << endl;


  namedWindow("janela",WINDOW_AUTOSIZE);

  cout << "Tamanho da imagem: " << image.rows << " x " << image.cols << endl;
  cout << "Digite coordenada 1: " << endl;
  cin >> p1.x >> p1.y;
  cout << "Digite coordenada 2: " << endl;
  cin >> p2.x >> p2.y;

  for(int i=p1.x;i<p2.x;i++){
    for(int j=p1.y;j<p2.y;j++){
      image.at<uchar>(i,j) = 255 - image.at<uchar>(i,j);
    }
  }


  imshow("janela", image);
  waitKey();


  return 0;
}
