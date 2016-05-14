#include "GrayImgSource.h"


GrayImgSource::GrayImgSource(char * pimg,int _height,int _width)
	:LuminanceSource(_width,_height)
{
	this->matrix = zxing::ArrayRef<char>(_width*_height);
	memcpy(&this->matrix[0],pimg,_width*_height);
}

GrayImgSource::~GrayImgSource(void)
{
	this->matrix->release();
}

zxing::ArrayRef<char> GrayImgSource::getRow(int y, zxing::ArrayRef<char> row)const
{
	const char * prow = (char *)&this->matrix[0] + y*this->getWidth();
	if(!row){
		row = zxing::ArrayRef<char>(this->getWidth());
	}
	for(int i=0 ; i<this->getWidth() ; i++)
	{
		row[i] = prow[i];
	}
	return row;
}


zxing::ArrayRef<char> GrayImgSource::getMatrix() const
{
	return this->matrix;
}
