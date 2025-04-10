#include "Math.h"

#include <cmath>

//加算
Vector3<float> Add(const Vector3<float>& a, const Vector3<float>& b) {

    return { a.x + b.x,a.y + b.y,a.z + b.z };

}

//減算
Vector3<float> Subtract(const Vector3<float>& a, const Vector3<float>& b) {

    return { a.x - b.x,a.y - b.y,a.z - b.z };
}

//スカラー倍
Vector3<float> Multiply(const float scalar, const Vector3<float> vector) {

    return { vector.x * scalar,vector.y * scalar,vector.z * scalar };
}

//内積(a ・ b)
float Dot(const Vector3<float>& a, const Vector3<float>& b) {

    return { a.x * b.x + a.y * b.y + a.z * b.z };
}

//ノルム(長さ)( ||v|| )
float Length(const Vector3<float>& vector) {

    return std::sqrt(Dot(vector, vector));

}