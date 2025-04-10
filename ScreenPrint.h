#pragma once

#include "Vector3.h"

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

void VectorScreenPrintf(int x, int y, const Vector3<float>& vector, const char* label);
