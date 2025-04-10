#include <Novice.h>

#include "ScreenPrint.h"
#include "Vector3.h"
#include "Matrix4x4.h"
#include "Math.h"


const char kWindowTitle[] = "LE2B_11_スエヒロ_コウイチ_タイトル";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    Vector3<float> translate = { 4.1f,2.6f,0.0f };
    Vector3<float> scale = { 1.5f,5.2f,7.3f };
    Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);
    Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);
    Vector3<float> point = { 2.3f,3.0f,1.4f };
    Matrix4x4 transformMatrix = {
        1.0f, 2.0f, 3.0f, 4.0f,
        3.0f, 1.0f, 1.0f, 2.0f,
        1.0f, 4.0f, 2.0f, 3.0f,
        2.0f, 2.0f, 1.0f, 3.0f
    };
    Vector3<float> transformed = Transform(point, transformMatrix);

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        ///
        /// ↓更新処理ここから
        ///

        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///

        VectorScreenPrintf(0, 0, transformed, "transformed");
        MatrixScreenPrintf(0, 20, transformMatrix, "transformMatrix");
        MatrixScreenPrintf(0, 20 + kRowHeight * 5, scaleMatrix, "scaleMatrix");

        ///
        /// ↑描画処理ここまで
        ///

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}

