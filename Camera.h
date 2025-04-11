#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix4x4.h"

class Camera {

    //カメラの位置。ワールド座標。
    Vector3<float> translate_;

    //カメラの回転角度
    Vector3<float> rotate_;

    //カメラの拡縮(ここはいじらない。)
    const Vector3<float> scale_ = { 1.0f,1.0f,1.0f };

    //正射影行列を構成する変数
    //カメラで映す空間の範囲

    // カメラで映す空間の左端のX座標
    float left_;

    //カメラで映す空間の右端のX座標
    float right_;

    //カメラで映す空間の上端のY座標
    float top_;

    //カメラで映す空間の下端のY座標
    float bottom_;

    //近平面。ここではz軸が奥行きになるため一番手前(面なので0だと面が点になって映らない。できるだけ全部が映る遠いところがいい。大体目安は0.1程度)。
    float nearClip_;

    //遠平面。ここではz軸が奥行きになるため遠さを表す。
    float farClip_;

    //ビューポート行列を構成する変数
    //ウィンドウ上で映す範囲

    //画面上で映す横幅
    float width_;

    //画面上で映す高さ
    float height_;

    //ウィンドウに映す範囲の左上の座標
    Vector2<float> leftTop_;

    //mindepth(最小深度値)
    float minD_;

    //maxDepth(最大深度値)
    float maxD_;

    //ワールド行列
    Matrix4x4 cameraMatrix_;

    //ビュー行列
    Matrix4x4 viewMatrix_;

    //正射影行列
    Matrix4x4 projectionMatrix_;

    //透視投影行列
    Matrix4x4 perspectiveFovMatrix_;

    //ビューポート行列
    Matrix4x4 viewportMatrix_;

public:
    //コンストラクタ
    Camera();

    //デストラクタ
    ~Camera();

    //初期化
    void Initialize();

    /// <summary>
    /// 透視投影行列の作成
    /// </summary>
    /// <param name="fovY"></param>
    /// <param name="aspectRatio"></param>
    /// <param name="nearClip"></param>
    /// <param name="farClip"></param>
    void MakePerspectiveFovMatrix(float fovY = 0.63f, float aspectRatio = 1.33f, float nearClip, float farClip);


    /// <summary>
    /// 正射行列の作成
    /// </summary>
    /// <param name="left"></param>
    /// <param name="top"></param>
    /// <param name="right"></param>
    /// <param name="bottom"></param>
    /// <param name="nearClip"></param>
    /// <param name="farClip"></param>
    void MakeOrthographicMatrix(float left = -160.0f, float top = 160.0f, float right = 200.0f, float bottom = 300.0f, float nearClip = 0.1f, float farClip = 1000.0f);

    /// <summary>
    /// ビューポート変換行列の作成
    /// </summary>
    /// <param name="left"></param>
    /// <param name="top"></param>
    /// <param name="width"></param>
    /// <param name="height"></param>
    /// <param name="minDepth"></param>
    /// <param name="maxDepth"></param>
    void MakeViewportMatrix(float left = 100.0f, float top = 200.0f, float width = 600.0f, float height = 300.0f, float minDepth = 0.0f, float maxDepth = 1.0f);

    /// <summary>
    /// 透視投影行列の更新
    /// </summary>
    void UpdatePerspectiveFovMatrix();

    /// <summary>
    /// 正射行列の更新
    /// </summary>
    void UpdateOrthographicMatrix();

    /// <summary>
    /// 透視投影行列の更新
    /// </summary>
    void UpdateViewportMatrix();
};

