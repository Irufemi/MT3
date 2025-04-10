#include "Math.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

#pragma region 3次元ベクトル関数

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

//正規化
Vector3<float> Normalize(const Vector3<float>& vector) {

    return Multiply(1.0f / Length(vector), vector);

}

#pragma endregion


#pragma region 4x4行列関数

// 4x4行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
    Matrix4x4 addResult = { 0 };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            addResult.m[i][j] = m1.m[i][j] + m2.m[i][j];
        }
    }

    return addResult;
}

// 4x4行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
    Matrix4x4 subtractResult = { 0 };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            subtractResult.m[i][j] = m1.m[i][j] - m2.m[i][j];
        }
    }

    return subtractResult;
}

// 4x4行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
    struct Matrix4x4 multiplyResult = { 0 };
    multiplyResult.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
    multiplyResult.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
    multiplyResult.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
    multiplyResult.m[0][3] = m1.m[1][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];
    multiplyResult.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
    multiplyResult.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
    multiplyResult.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
    multiplyResult.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];
    multiplyResult.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
    multiplyResult.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
    multiplyResult.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
    multiplyResult.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];
    multiplyResult.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
    multiplyResult.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
    multiplyResult.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
    multiplyResult.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];
    return multiplyResult;
}

// 4x4逆行列を求める 
Matrix4x4 Inverse(const Matrix4x4& m) {
	static float realizeA;
	realizeA = +m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3]
		+ m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1]
		+ m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][0]
		- m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1]
		- m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3]
		- m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2]
		- m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3]
		- m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1]
		- m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2]
		+ m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1]
		+ m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3]
		+ m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2]
		+ m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3]
		+ m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1]
		+ m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2]
		- m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1]
		- m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3]
		- m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2]
		- m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0]
		- m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0]
		- m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0]
		+ m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0]
		+ m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0]
		+ m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0];

	Matrix4x4 ex;

	ex.m[0][0] = 1 / realizeA * (
		+m.m[1][1] * m.m[2][2] * m.m[3][3]
		+ m.m[1][2] * m.m[2][3] * m.m[3][1]
		+ m.m[1][3] * m.m[2][1] * m.m[3][2]
		- m.m[1][3] * m.m[2][2] * m.m[3][1]
		- m.m[1][2] * m.m[2][1] * m.m[3][3]
		- m.m[1][1] * m.m[2][3] * m.m[3][2]
		);
	ex.m[0][1] = 1 / realizeA * (
		-m.m[0][1] * m.m[2][2] * m.m[3][3]
		- m.m[0][2] * m.m[2][3] * m.m[3][1]
		- m.m[0][3] * m.m[2][1] * m.m[3][2]
		+ m.m[0][3] * m.m[2][2] * m.m[3][1]
		+ m.m[0][2] * m.m[2][1] * m.m[3][3]
		+ m.m[0][1] * m.m[2][3] * m.m[3][2]
		);
	ex.m[0][2] = 1 / realizeA * (
		+m.m[0][1] * m.m[1][2] * m.m[3][3]
		+ m.m[0][2] * m.m[1][3] * m.m[3][1]
		+ m.m[0][3] * m.m[1][1] * m.m[3][2]
		- m.m[0][3] * m.m[1][2] * m.m[3][1]
		- m.m[0][2] * m.m[1][1] * m.m[3][3]
		- m.m[0][1] * m.m[1][3] * m.m[3][2]
		);
	ex.m[0][3] = 1 / realizeA * (
		-m.m[0][1] * m.m[1][2] * m.m[2][3]
		- m.m[0][2] * m.m[1][3] * m.m[2][1]
		- m.m[0][3] * m.m[1][1] * m.m[2][2]
		+ m.m[0][3] * m.m[1][2] * m.m[2][1]
		+ m.m[0][2] * m.m[1][1] * m.m[2][3]
		+ m.m[0][1] * m.m[1][3] * m.m[2][2]
		);
	ex.m[1][0] = 1 / realizeA * (
		-m.m[1][0] * m.m[2][2] * m.m[3][3]
		- m.m[1][2] * m.m[2][3] * m.m[3][0]
		- m.m[1][3] * m.m[2][0] * m.m[3][2]
		+ m.m[1][3] * m.m[2][2] * m.m[3][0]
		+ m.m[1][2] * m.m[2][0] * m.m[3][3]
		+ m.m[1][0] * m.m[2][3] * m.m[3][2]
		);
	ex.m[1][1] = 1 / realizeA * (
		+m.m[0][0] * m.m[2][2] * m.m[3][3]
		+ m.m[0][2] * m.m[2][3] * m.m[3][0]
		+ m.m[0][3] * m.m[2][0] * m.m[3][2]
		- m.m[0][3] * m.m[2][2] * m.m[3][0]
		- m.m[0][2] * m.m[2][0] * m.m[3][3]
		- m.m[0][0] * m.m[2][3] * m.m[3][2]
		);
	ex.m[1][2] = 1 / realizeA * (
		-m.m[0][0] * m.m[1][2] * m.m[3][3]
		- m.m[0][2] * m.m[1][3] * m.m[3][0]
		- m.m[0][3] * m.m[1][0] * m.m[3][2]
		+ m.m[0][3] * m.m[1][2] * m.m[3][0]
		+ m.m[0][2] * m.m[1][0] * m.m[3][3]
		+ m.m[0][0] * m.m[1][3] * m.m[3][2]
		);
	ex.m[1][3] = 1 / realizeA * (
		+m.m[0][0] * m.m[1][2] * m.m[2][3]
		+ m.m[0][2] * m.m[1][3] * m.m[2][0]
		+ m.m[0][3] * m.m[1][0] * m.m[2][2]
		- m.m[0][3] * m.m[1][2] * m.m[2][0]
		- m.m[0][2] * m.m[1][0] * m.m[2][3]
		- m.m[0][0] * m.m[1][3] * m.m[2][2]
		);
	ex.m[2][0] = 1 / realizeA * (
		+m.m[1][0] * m.m[2][1] * m.m[3][3]
		+ m.m[1][1] * m.m[2][3] * m.m[3][0]
		+ m.m[1][3] * m.m[2][0] * m.m[3][1]
		- m.m[1][3] * m.m[2][1] * m.m[3][0]
		- m.m[1][1] * m.m[2][0] * m.m[3][3]
		- m.m[1][0] * m.m[2][3] * m.m[3][1]
		);
	ex.m[2][1] = 1 / realizeA * (
		-m.m[0][0] * m.m[2][1] * m.m[3][3]
		- m.m[0][1] * m.m[2][3] * m.m[3][0]
		- m.m[0][3] * m.m[2][0] * m.m[3][1]
		+ m.m[0][3] * m.m[2][1] * m.m[3][0]
		+ m.m[0][1] * m.m[2][0] * m.m[3][3]
		+ m.m[0][0] * m.m[2][3] * m.m[3][1]
		);
	ex.m[2][2] = 1 / realizeA * (
		+m.m[0][0] * m.m[1][1] * m.m[3][3]
		+ m.m[0][1] * m.m[1][3] * m.m[3][0]
		+ m.m[0][3] * m.m[1][0] * m.m[3][1]
		- m.m[0][3] * m.m[1][1] * m.m[3][0]
		- m.m[0][1] * m.m[1][0] * m.m[3][3]
		- m.m[0][0] * m.m[1][3] * m.m[3][1]
		);
	ex.m[2][3] = 1 / realizeA * (
		-m.m[0][0] * m.m[1][1] * m.m[3][3]
		- m.m[0][1] * m.m[1][3] * m.m[3][0]
		- m.m[0][3] * m.m[1][0] * m.m[3][1]
		+ m.m[0][3] * m.m[1][1] * m.m[3][0]
		+ m.m[0][1] * m.m[1][0] * m.m[3][3]
		+ m.m[0][0] * m.m[1][3] * m.m[3][1]
		);
	ex.m[3][0] = 1 / realizeA * (
		-m.m[1][0] * m.m[2][1] * m.m[3][2]
		- m.m[1][1] * m.m[2][2] * m.m[3][0]
		- m.m[1][2] * m.m[2][0] * m.m[3][1]
		+ m.m[1][2] * m.m[2][1] * m.m[3][0]
		+ m.m[1][1] * m.m[2][0] * m.m[3][2]
		+ m.m[1][0] * m.m[2][2] * m.m[3][1]
		);
	ex.m[3][1] = 1 / realizeA * (
		+m.m[0][0] * m.m[2][1] * m.m[3][2]
		+ m.m[0][1] * m.m[2][2] * m.m[3][0]
		+ m.m[0][2] * m.m[2][0] * m.m[3][1]
		- m.m[0][2] * m.m[2][1] * m.m[3][0]
		- m.m[0][1] * m.m[2][0] * m.m[3][2]
		- m.m[0][0] * m.m[2][2] * m.m[3][1]
		);
	ex.m[3][2] = 1 / realizeA * (
		-m.m[0][0] * m.m[1][1] * m.m[3][2]
		- m.m[0][1] * m.m[1][2] * m.m[3][0]
		- m.m[0][2] * m.m[1][0] * m.m[3][1]
		+ m.m[0][2] * m.m[1][1] * m.m[3][0]
		+ m.m[0][1] * m.m[1][0] * m.m[3][2]
		+ m.m[0][0] * m.m[1][2] * m.m[3][1]
		);
	ex.m[3][3] = 1 / realizeA * (
		+m.m[0][0] * m.m[1][1] * m.m[2][2]
		+ m.m[0][1] * m.m[1][2] * m.m[2][0]
		+ m.m[0][2] * m.m[1][0] * m.m[2][1]
		- m.m[0][2] * m.m[1][1] * m.m[2][0]
		- m.m[0][1] * m.m[1][0] * m.m[2][2]
		- m.m[0][0] * m.m[1][2] * m.m[2][1]
		);

	return ex;
}

// 4x4転置行列を求める 
Matrix4x4 Transpose(const Matrix4x4& m) {
	static Matrix4x4 tMatrix;
	tMatrix.m[0][0] = m.m[0][0];
	tMatrix.m[0][1] = m.m[1][0];
	tMatrix.m[0][2] = m.m[2][0];
	tMatrix.m[0][3] = m.m[3][0];
	tMatrix.m[1][0] = m.m[0][1];
	tMatrix.m[1][1] = m.m[1][1];
	tMatrix.m[1][2] = m.m[2][1];
	tMatrix.m[1][3] = m.m[3][1];
	tMatrix.m[2][0] = m.m[0][2];
	tMatrix.m[2][1] = m.m[1][2];
	tMatrix.m[2][2] = m.m[2][2];
	tMatrix.m[2][3] = m.m[3][2];
	tMatrix.m[3][0] = m.m[0][3];
	tMatrix.m[3][1] = m.m[1][3];
	tMatrix.m[3][2] = m.m[2][3];
	tMatrix.m[3][3] = m.m[2][3];
	return tMatrix;
}

//4x4単位行列の作成
Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 m = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
	return m;
}

// 4x4平行移動行列の作成関数 
Matrix4x4 MakeTranslateMatrix(const Vector3<float>& translate) {
	static Matrix4x4 resultTranslateMatrix;
	resultTranslateMatrix.m[0][0] = 1.0f;
	resultTranslateMatrix.m[0][1] = 0.0f;
	resultTranslateMatrix.m[0][2] = 0.0f;
	resultTranslateMatrix.m[0][3] = 0.0f;
	resultTranslateMatrix.m[1][0] = 0.0f;
	resultTranslateMatrix.m[1][1] = 1.0f;
	resultTranslateMatrix.m[1][2] = 0.0f;
	resultTranslateMatrix.m[1][3] = 0.0f;
	resultTranslateMatrix.m[2][0] = 0.0f;
	resultTranslateMatrix.m[2][1] = 0.0f;
	resultTranslateMatrix.m[2][2] = 1.0f;
	resultTranslateMatrix.m[2][3] = 0.0f;
	resultTranslateMatrix.m[3][0] = translate.x;
	resultTranslateMatrix.m[3][1] = translate.y;
	resultTranslateMatrix.m[3][2] = translate.z;
	resultTranslateMatrix.m[3][3] = 1.0f;
	return resultTranslateMatrix;
}

//4x4拡大縮小行列の作成関数
Matrix4x4 MakeScaleMatrix(const Vector3<float>& scale) {
	static Matrix4x4 resultScaleMtrix;
	resultScaleMtrix.m[0][0] = scale.x;
	resultScaleMtrix.m[0][1] = 0.0f;
	resultScaleMtrix.m[0][2] = 0.0f;
	resultScaleMtrix.m[0][3] = 0.0f;
	resultScaleMtrix.m[1][0] = 0.0f;
	resultScaleMtrix.m[1][1] = scale.y;
	resultScaleMtrix.m[1][2] = 0.0f;
	resultScaleMtrix.m[1][3] = 0.0f;
	resultScaleMtrix.m[2][0] = 0.0f;
	resultScaleMtrix.m[2][1] = 0.0f;
	resultScaleMtrix.m[2][2] = scale.z;
	resultScaleMtrix.m[2][3] = 0.0f;
	resultScaleMtrix.m[3][0] = 0.0f;
	resultScaleMtrix.m[3][1] = 0.0f;
	resultScaleMtrix.m[3][2] = 0.0f;
	resultScaleMtrix.m[3][3] = 1.0f;
	return resultScaleMtrix;
}

// 3次元ベクトルを同次座標として変換する 
Vector3<float> Transform(const Vector3<float>& vector, const Matrix4x4& m) {
	static Vector3<float> transformResult = { 0.0f,0.0f,0.0f };
	transformResult.x = vector.x * m.m[0][0] + vector.y * m.m[1][0] + vector.z * m.m[2][0] + 1.0f * m.m[3][0];
	transformResult.y = vector.x * m.m[0][1] + vector.y * m.m[1][1] + vector.z * m.m[2][1] + 1.0f * m.m[3][1];
	transformResult.z = vector.x * m.m[0][2] + vector.y * m.m[1][2] + vector.z * m.m[2][2] + 1.0f * m.m[3][2];
	float w = vector.x * m.m[0][3] + vector.y * m.m[1][3] + vector.z * m.m[2][3] + 1.0f * m.m[3][3];
	if (w != 0.0f) { ///ベクトルに対して基本的な操作を行う行列でwが0になることはありえない
		transformResult.x /= w; //w=1がデカルト座標系であるので、w除算することで同時座標をデカルト座標に戻す
		transformResult.y /= w;
		transformResult.z /= w;
		return transformResult;
	}
	else {
		return { 0 };
	}
}

// 4x4 X軸周り回転行列の作成関数
Matrix4x4 MakeRotateXMatrix(const float& theta) {
	static Matrix4x4 matrix;
	matrix.m[0][0] = 1.0f;
	matrix.m[0][1] = 0.0f;
	matrix.m[0][2] = 0.0f;
	matrix.m[0][3] = 0.0f;
	matrix.m[1][0] = 0.0f;
	matrix.m[1][1] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[1][2] = std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[1][3] = 0.0f;
	matrix.m[2][0] = 0.0f;
	matrix.m[2][1] = -std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[2][2] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[2][3] = 0.0f;
	matrix.m[3][0] = 0.0f;
	matrix.m[3][1] = 0.0f;
	matrix.m[3][2] = 0.0f;
	matrix.m[3][3] = 1.0f;
	return matrix;
}

// 4x4 Y軸周り回転行列の作成関数
Matrix4x4 MakeRotateYMatrix(const float& theta) {
	static Matrix4x4 matrix;
	matrix.m[0][0] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[0][1] = 0.0f;
	matrix.m[0][2] = std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[0][3] = 0.0f;
	matrix.m[1][0] = 0.0f;
	matrix.m[1][1] = 1.0f;
	matrix.m[1][2] = 0.0f;
	matrix.m[1][3] = 0.0f;
	matrix.m[2][0] = -std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[2][1] = 0.0f;
	matrix.m[2][2] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[2][3] = 0.0f;
	matrix.m[3][0] = 0.0f;
	matrix.m[3][1] = 0.0f;
	matrix.m[3][2] = 0.0f;
	matrix.m[3][3] = 1.0f;
	return matrix;
}

// 4x4 Z軸周り回転行列の作成関数
Matrix4x4 MakeRotateZMatrix(const float& theta) {
	static Matrix4x4 matrix;
	matrix.m[0][0] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[0][1] = std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[0][2] = 0.0f;
	matrix.m[0][3] = 0.0f;
	matrix.m[1][0] = -std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[1][1] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[1][2] = 0.0f;
	matrix.m[1][3] = 0.0f;
	matrix.m[2][0] = 0.0f;
	matrix.m[2][1] = 0.0f;
	matrix.m[2][2] = 1.0f;
	matrix.m[2][3] = 0.0f;
	matrix.m[3][0] = 0.0f;
	matrix.m[3][1] = 0.0f;
	matrix.m[3][2] = 0.0f;
	matrix.m[3][3] = 1.0f;
	return matrix;
}

// 3次元回転行列の作成関数
Matrix4x4 MakeRotateXYZMatrix(const float& thetaX, const float& thetaY, const float& thetaZ) {
	Matrix4x4 matrix = Multiply(MakeRotateXMatrix(thetaX), Multiply(MakeRotateYMatrix(thetaY), MakeRotateZMatrix(thetaZ)));
	return matrix;
}

#pragma endregion
