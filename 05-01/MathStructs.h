#pragma once

struct Vector2 {
	float x;
	float y;

	float Length(const Vector2& other);

	Vector2& operator+=(const Vector2& other);
};

Vector2 operator+(const Vector2& v1, const Vector2& v2);
Vector2 operator-(const Vector2& v1, const Vector2& v2);

struct Vector2Int {
	int x;
	int y;
};