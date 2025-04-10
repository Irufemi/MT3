#pragma once

#include "Vector3.h"

/// <summary>
/// 加算
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
Vector3<float> Add(const Vector3<float>& a, const Vector3<float>& b);

/// <summary>
/// 減算
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
Vector3<float> Subtract(const Vector3<float>& a, const Vector3<float>& b);

/// <summary>
/// スカラー倍
/// </summary>
/// <param name="scalar"></param>
/// <param name="vector"></param>
/// <returns></returns>
Vector3<float> Multiply(const float scalar, const Vector3<float> vector);

/// <summary>
/// 内積
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
float Dot(const Vector3<float>& a, const Vector3<float>& b);


/// <summary>
/// ノルム(長さ)
/// </summary>
/// <param name="vector"></param>
/// <returns></returns>
float Length(const Vector3<float>& vector);

/// <summary>
/// 正規化
/// </summary>
/// <param name="vector"></param>
/// <returns></returns>
Vector3<float> Normalize(const Vector3<float>& vector);

