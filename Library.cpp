//Finds the intersection point of two line segments
//segment 1 from (x0, y0) to (x1, y1)
//segment 2 from (x2, y2) to (x3, y3)
//returns 0 if 0 intersection point
//returns 1 if 1 intersection point, and returns intersection point (ix, iy)
//returns 2 if infinite intersection point
int intersect(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, double& ix, double& iy)
{
	
	double s0x = x1-x0;
	double s0y = y1-y0;
	double s1x = x3-x2;
	double s1y = y3-y2;
	double det = s0x*s1y-s1x*s0y;
	if(det==0)
	{
		//collinear
		return 2;
	}
	double c0 = (s0x*(y0-y2)-s0y*(x0-x2))/det;
	double c1 = (s1x*(y0-y2)-s1y*(x0-x2))/det;
	if(c0>=0&&c0<=1&&c1>=0&&c1<=1)
	{
		ix = x0 + c1*s0x;
		iy = y0 + c1*s0y;
		return 1;
	}
	return 0;
}
