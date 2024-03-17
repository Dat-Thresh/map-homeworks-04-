#pragma once
#include"shape.h"
class transform
{
public:
	transform(const Shape& sh);
	void shift(int m, int n, int k);
	void scaleX(int a, int os =0);
	void scaleY(int d, int os=1);
	void scaleZ(int e, int os=2);
	void scale_down(int s);

private:
	Shape shape;
};


//#pragma once
//#include"shape.h"
//class transform
//{
//public:
//	transform(const Shape& sh);
//	Shape shift(int m, int n, int k);
//	Shape scaleX(int a);
//	Shape scaleY(int d);
//	Shape scaleZ(int e);
//	Shape scale(int s);
//
//private:
//	Shape shape;
//};

