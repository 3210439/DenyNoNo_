#include <jni.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_denynono_1_1_Camera_ConvertRGBtoGray(JNIEnv *env, jobject instance,
                                                      jlong matAddrInput, jlong matAddrResult) {


    Mat &matInput = *(Mat *)matAddrInput;
    Mat &matResult = *(Mat *)matAddrResult;
    //jstring result_tip = (jstring) "hello";
//    int myFontFace = 2;
//    int myFontScale = 3;
    Point_<float> p1(matResult.cols/4, 3*matResult.rows/8);
    Point_<float> p2(3*matResult.cols/4, 5*matResult.rows/8);
//    Point_<float> textP(matResult.cols/4, 2*matResult.rows/8);
    Rect_<float> r(p1, Size_<float>(matResult.cols/2, matResult.rows/4));
    rectangle(matInput,p1,p2,Scalar(0,255,0),5);
    cvtColor(matInput, matResult, COLOR_RGBA2GRAY);
    Mat ROI = matResult(r);

//    str_ = (jstring)"성공";

    //putText(matInput, result_tip ,textP ,myFontFace,  myFontScale, Scalar(0,200,0) );
   // return result_tip;
    //return (jstring )"sdjfsf";

    std::string hello = "Hello from C++ 번호판";
    return env->NewStringUTF(hello.c_str());
}