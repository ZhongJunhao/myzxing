#pragma once
#include <zxing/LuminanceSource.h>

class GrayImgSource :
	public zxing::LuminanceSource
{
	zxing::ArrayRef<char> matrix;
public:
	GrayImgSource(char *p_img ,int height,int width);
	~GrayImgSource(void);
	zxing::ArrayRef<char> getRow(int y, zxing::ArrayRef<char> row) const;
	zxing::ArrayRef<char> getMatrix() const;
};

