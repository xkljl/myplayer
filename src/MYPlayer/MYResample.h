#ifndef MYRESAMPLE_H
#define MYRESAMPLE_H

#include <mutex>


struct AVCodecParameters;
struct AVFrame;
struct SwrContext;

class MYResample
{
public:
    //输出参数和输入参数一致除了采样格式，输出为S16 ,会释放para
    virtual bool Open(AVCodecParameters *para, bool isClearPara = false);
    virtual void Close();

    //返回重采样后大小,不管成功与否都释放indata空间
    virtual int Resample(AVFrame *indata, unsigned char *data);

    MYResample();
    virtual ~MYResample();

    //AV_SAMPLE_FMT_S16
    int outFormat = 1;
protected:
    std::mutex mux;
    SwrContext *actx = 0;
};

#endif // MYRESAMPLE_H
