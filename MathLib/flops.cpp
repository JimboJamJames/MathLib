#include "flops.h"
#include <cmath>

// FLT_EPSILON in <cfloat> is an okay threshold.
// float equivalence
// We want to see if two floats are negligbly close
// enough to be considered the same.
bool fequals(float lhs, float rhs)
{
	return fabsf(lhs - rhs) <= 0.00001f;
}

float deg2rad(float deg)
{
	return 0.0174533 * deg;
}

float rad2deg(float rad)
{
	return 57.2958 * rad;
}

float linerarHalf(float x)
{
	return 0.5f*x;
}

float growFast(float x)
{
	return x*x;
}

float bounce(float x)
{
	return abs(cos(x * 10 * (1 - x)));
}

float bounceFlip(float x)
{
	return 1 - bounce(x);
}

float lerp(float start, float end, float alpha)
{
	return (1 - alpha)*start + (alpha)*end;
}
float quadBezier(float start, float mid, float end, float alpha)
{
	return
		lerp(
			lerp(start, mid, alpha),
			lerp(mid, end, alpha),
			alpha);
}