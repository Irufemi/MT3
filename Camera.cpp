#include "Camera.h"

#include <cmath>

//�R���X�g���N�^
Camera::Camera(){}

//�f�X�g���N�^
Camera::~Camera(){}

//������
void Camera::Initialize() {

}

//�������e�s��̍쐬
void Camera::MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
    
    perspectiveFovMatrix_.m[0][0] = 1.0f / aspectRatio * (1.0f / std::tan(fovY / 2.0f));
    perspectiveFovMatrix_.m[0][1] = 0.0f;
    perspectiveFovMatrix_.m[0][2] = 0.0f;
    perspectiveFovMatrix_.m[0][3] = 0.0f;
    perspectiveFovMatrix_.m[1][0] = 0.0f;
    perspectiveFovMatrix_.m[1][1] = 1.0f / std::tan(fovY * 2.0f);
    perspectiveFovMatrix_.m[1][2] = 0.0f;
    perspectiveFovMatrix_.m[1][3] = 0.0f;
    perspectiveFovMatrix_.m[2][0] = 0.0f;
    perspectiveFovMatrix_.m[2][1] = 0.0f;
    perspectiveFovMatrix_.m[2][2] = farClip / (farClip - nearClip);
    perspectiveFovMatrix_.m[2][3] = 1.0f;
    perspectiveFovMatrix_.m[3][0] = 0.0f;
    perspectiveFovMatrix_.m[3][1] = 0.0f;
    perspectiveFovMatrix_.m[3][2] = (-nearClip * farClip) / (farClip - nearClip);
    perspectiveFovMatrix_.m[3][3] = 0.0f;
}

//���ˍs��̍쐬
void Camera::MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {
    //�ϐ��Ɉ�������
    left_ = left;
    top_ = top;
    right_ = right;
    bottom_ = bottom;
    nearClip_ = nearClip;
    farClip_ = farClip;
    
    //�s����쐬
    projectionMatrix_.m[0][0] = 2.0f / (right_ - left_);
    projectionMatrix_.m[0][1] = 0.0f;
    projectionMatrix_.m[0][2] = 0.0f;
    projectionMatrix_.m[0][3] = 0.0f;
    projectionMatrix_.m[1][0] = 0.0f;
    projectionMatrix_.m[1][1] = 2.0f / (top_ - bottom_);
    projectionMatrix_.m[1][2] = 0.0f;
    projectionMatrix_.m[1][3] = 0.0f;
    projectionMatrix_.m[2][0] = 0.0f;
    projectionMatrix_.m[2][1] = 0.0f;
    projectionMatrix_.m[2][2] = 1.0f / (farClip_ - nearClip_);
    projectionMatrix_.m[2][3] = 0.0f;
    projectionMatrix_.m[3][0] = (left_ + right_) / (left_ - right_);
    projectionMatrix_.m[3][1] = (top_ + bottom_) / (bottom_ - top_);
    projectionMatrix_.m[3][2] = nearClip_ / (nearClip_ - farClip_);
    projectionMatrix_.m[3][3] = 1.0f;
}

//�r���[�|�[�g�ϊ��s��̍쐬
void Camera::MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {
    //������ϐ��ɑ��
    leftTop_.x = left;
    leftTop_.y = top;
    width_ = width;
    height_ = height;
    minD_ = minDepth;
    maxD_ = maxDepth;

    //�s����쐬
    viewportMatrix_.m[0][0] = width_ / 2.0f;
    viewportMatrix_.m[0][1] = 0.0f;
    viewportMatrix_.m[0][2] = 0.0f;
    viewportMatrix_.m[0][3] = 0.0f;
    viewportMatrix_.m[1][0] = 0.0f;
    viewportMatrix_.m[1][1] = -height_ / 2.0f;
    viewportMatrix_.m[1][2] = 0.0f;
    viewportMatrix_.m[1][3] = 0.0f;
    viewportMatrix_.m[2][0] = 0.0f;
    viewportMatrix_.m[2][1] = 0.0f;
    viewportMatrix_.m[2][2] = maxD_ - minD_;
    viewportMatrix_.m[2][3] = 0.0f;
    viewportMatrix_.m[3][0] = leftTop_.x + width_ / 2.0f;
    viewportMatrix_.m[3][1] = leftTop_.y + height_ / 2.0f;
    viewportMatrix_.m[3][2] = minD_;
    viewportMatrix_.m[3][3] = 1.0f;

}

//�������e�s��̍X�V
void Camera::UpdatePerspectiveFovMatrix() {
    perspectiveFovMatrix_.m[0][0] = 1.0f / aspectRatio * (1.0f / std::tan(fovY / 2.0f));
    perspectiveFovMatrix_.m[0][1] = 0.0f;
    perspectiveFovMatrix_.m[0][2] = 0.0f;
    perspectiveFovMatrix_.m[0][3] = 0.0f;
    perspectiveFovMatrix_.m[1][0] = 0.0f;
    perspectiveFovMatrix_.m[1][1] = 1.0f / std::tan(fovY * 2.0f);
    perspectiveFovMatrix_.m[1][2] = 0.0f;
    perspectiveFovMatrix_.m[1][3] = 0.0f;
    perspectiveFovMatrix_.m[2][0] = 0.0f;
    perspectiveFovMatrix_.m[2][1] = 0.0f;
    perspectiveFovMatrix_.m[2][2] = farClip / (farClip - nearClip);
    perspectiveFovMatrix_.m[2][3] = 1.0f;
    perspectiveFovMatrix_.m[3][0] = 0.0f;
    perspectiveFovMatrix_.m[3][1] = 0.0f;
    perspectiveFovMatrix_.m[3][2] = (-nearClip * farClip) / (farClip - nearClip);
    perspectiveFovMatrix_.m[3][3] = 0.0f;
}

//���ˍs��̍X�V
void Camera::UpdateOrthographicMatrix() {
    projectionMatrix_.m[0][0] = 2.0f / (right_ - left_);
    projectionMatrix_.m[0][1] = 0.0f;
    projectionMatrix_.m[0][2] = 0.0f;
    projectionMatrix_.m[0][3] = 0.0f;
    projectionMatrix_.m[1][0] = 0.0f;
    projectionMatrix_.m[1][1] = 2.0f / (top_ - bottom_);
    projectionMatrix_.m[1][2] = 0.0f;
    projectionMatrix_.m[1][3] = 0.0f;
    projectionMatrix_.m[2][0] = 0.0f;
    projectionMatrix_.m[2][1] = 0.0f;
    projectionMatrix_.m[2][2] = 1.0f / (farClip_ - nearClip_);
    projectionMatrix_.m[2][3] = 0.0f;
    projectionMatrix_.m[3][0] = (left_ + right_) / (left_ - right_);
    projectionMatrix_.m[3][1] = (top_ + bottom_) / (bottom_ - top_);
    projectionMatrix_.m[3][2] = nearClip_ / (nearClip_ - farClip_);
    projectionMatrix_.m[3][3] = 1.0f;
}

//�������e�s��̍X�V
void Camera::UpdateViewportMatrix() {
    viewportMatrix_.m[0][0] = width_ / 2.0f;
    viewportMatrix_.m[0][1] = 0.0f;
    viewportMatrix_.m[0][2] = 0.0f;
    viewportMatrix_.m[0][3] = 0.0f;
    viewportMatrix_.m[1][0] = 0.0f;
    viewportMatrix_.m[1][1] = -height_ / 2.0f;
    viewportMatrix_.m[1][2] = 0.0f;
    viewportMatrix_.m[1][3] = 0.0f;
    viewportMatrix_.m[2][0] = 0.0f;
    viewportMatrix_.m[2][1] = 0.0f;
    viewportMatrix_.m[2][2] = maxD_ - minD_;
    viewportMatrix_.m[2][3] = 0.0f;
    viewportMatrix_.m[3][0] = leftTop_.x + width_ / 2.0f;
    viewportMatrix_.m[3][1] = leftTop_.y + height_ / 2.0f;
    viewportMatrix_.m[3][2] = minD_;
    viewportMatrix_.m[3][3] = 1.0f;
}