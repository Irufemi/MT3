#include "ScreenPrint.h"

#include <Novice.h>

void VectorScreenPrintf(int x, int y, const Vector3<float>& vector, const char* label) {

    Novice::ScreenPrintf(x, y, "%.02f", vector.x);

    Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);

    Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);

    Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);

}

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {
    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {
            Novice::ScreenPrintf(
                x, y,
                "%s", label
            );
            Novice::ScreenPrintf(
                x + column * kColumnWidth, y + (row + 1) * kRowHeight,
                "%6.02f", matrix.m[row][column]
            );
        }
    }
}