#include "MathCalculations.h"

#include <cmath>

float Length(const Vector2& v) {
	return std::sqrtf(v.x * v.x + v.y * v.y);
}
