#pragma once

#include "Vector3.h"
#include "Matrix4x4.h"

#pragma region 3次元ベクトル関数

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



#pragma endregion

#pragma region 4x4行列関数

/// <summary>
/// 4x4行列の加法
/// </summary>
/// <param name="m1"></param>
/// <param name="m2"></param>
/// <returns></returns>
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

/// <summary>
/// 4x4行列の減法
/// </summary>
/// <param name="m1"></param>
/// <param name="m2"></param>
/// <returns></returns>
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

/// <summary>
/// 4x4行列の積
/// </summary>
/// <param name="vector"></param>
/// <param name="m"></param>
/// <returns></returns>
Matrix4x4 Multiply(const Matrix4x4& vector, const Matrix4x4& m);

/// <summary>
/// 4x4逆行列を求める
/// </summary>
/// <param name="m"></param>
/// <returns></returns>
Matrix4x4 Inverse(const Matrix4x4& m);

/// <summary>
/// 4x4転置行列を求める 
/// </summary>
/// <param name="m"></param>
/// <returns></returns>
Matrix4x4 Transpose(const Matrix4x4& m);

/// <summary>
/// 4x4単位行列の作成
/// </summary>
/// <returns></returns>
Matrix4x4 MakeIdentity4x4();

/// <summary>
/// 4x4平行移動行列の作成
/// </summary>
/// <param name="translate"></param>
/// <returns></returns>
Matrix4x4 MakeTranslateMatrix(const Vector3<float>& translate);

/// <summary>
/// 4x4拡大縮小行列の作成
/// </summary>
/// <param name="scale"></param>
/// <returns></returns>
Matrix4x4 MakeScaleMatrix(const Vector3<float>& scale);

/// <summary>
/// 3次元ベクトルを同次座標として変換
/// </summary>
/// <param name="vector"></param>
/// <param name="matrix"></param>
/// <returns></returns>
Vector3<float> Transform(const Vector3<float>& vector, const Matrix4x4& matrix);

/// <summary>
/// 4x4 X軸周り回転行列の作成
/// </summary>
/// <param name="theta"></param>
/// <returns></returns>
Matrix4x4 MakeRotateXMatrix(const float& theta);

/// <summary>
/// 4x4 Y軸周り回転行列の作成
/// </summary>
/// <param name="theta"></param>
/// <returns></returns>
Matrix4x4 MakeRotateYMatrix(const float& theta);

/// <summary>
/// 4x4 Z軸周り回転行列の作成
/// </summary>
/// <param name="theta"></param>
/// <returns></returns>
Matrix4x4 MakeRotateZMatrix(const float& theta);

/// <summary>
/// 4x4 3次元回転行列の作成
/// </summary>
/// <param name="thetaX"></param>
/// <param name="thetaY"></param>
/// <param name="thetaZ"></param>
/// <returns></returns>
Matrix4x4 MakeRotateXYZMatrix(const float& thetaX, const float& thetaY, const float& thetaZ);

/// <summary>
/// 4x4アフィン変換行列を高速に生成
/// </summary>
/// <param name="scale"></param>
/// <param name="rotate"></param>
/// <param name="translate"></param>
/// <returns></returns>
Matrix4x4 MakeAffineMatrix(const Vector3<float>& scale, const Vector3<float>& rotate, const Vector3<float>& translate);
#pragma endregion

