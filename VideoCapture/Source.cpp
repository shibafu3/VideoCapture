#ifdef _DEBUG
//Debugモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300d.lib")            // opencv_core
#else
//Releaseモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300.lib") 
#endif
#pragma warning(disable:4996)

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(){
	VideoCapture capture_l(1);
	VideoCapture capture_r(1);

	if (!capture_l.isOpened()) { return -1; }
	if (!capture_r.isOpened()) { return -1;	}

	Mat image_l;
	Mat image_r;
	char image_name_l[100];
	char image_name_r[100];

	int count = 0;
	while (waitKey(10) != 27){
		capture_l >> image_l;
		capture_r >> image_r;

		imshow("image_l", image_l);
		imshow("image_r", image_r);

		if (waitKey(10) != -1){
			sprintf(image_name_l, "C:\\Users\\0133752\\Desktop\\l_%02d.jpg", count);
			sprintf(image_name_r, "C:\\Users\\0133752\\Desktop\\r_%02d.jpg", count);
			imwrite(image_name_l, image_l);
			imwrite(image_name_r, image_r);

			count++;
		}
	}
	return 0;
}