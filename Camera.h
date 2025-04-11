#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix4x4.h"

class Camera {

    //�J�����̈ʒu�B���[���h���W�B
    Vector3<float> translate_;

    //�J�����̉�]�p�x
    Vector3<float> rotate_;

    //�J�����̊g�k(�����͂�����Ȃ��B)
    const Vector3<float> scale_ = { 1.0f,1.0f,1.0f };

    //���ˉe�s����\������ϐ�
    //�J�����ŉf����Ԃ͈̔�

    // �J�����ŉf����Ԃ̍��[��X���W
    float left_;

    //�J�����ŉf����Ԃ̉E�[��X���W
    float right_;

    //�J�����ŉf����Ԃ̏�[��Y���W
    float top_;

    //�J�����ŉf����Ԃ̉��[��Y���W
    float bottom_;

    //�ߕ��ʁB�����ł�z�������s���ɂȂ邽�߈�Ԏ�O(�ʂȂ̂�0���Ɩʂ��_�ɂȂ��ĉf��Ȃ��B�ł��邾���S�����f�鉓���Ƃ��낪�����B��̖ڈ���0.1���x)�B
    float nearClip_;

    //�����ʁB�����ł�z�������s���ɂȂ邽�߉�����\���B
    float farClip_;

    //�r���[�|�[�g�s����\������ϐ�
    //�E�B���h�E��ŉf���͈�

    //��ʏ�ŉf������
    float width_;

    //��ʏ�ŉf������
    float height_;

    //�E�B���h�E�ɉf���͈͂̍���̍��W
    Vector2<float> leftTop_;

    //mindepth(�ŏ��[�x�l)
    float minD_;

    //maxDepth(�ő�[�x�l)
    float maxD_;

    //���[���h�s��
    Matrix4x4 cameraMatrix_;

    //�r���[�s��
    Matrix4x4 viewMatrix_;

    //���ˉe�s��
    Matrix4x4 projectionMatrix_;

    //�������e�s��
    Matrix4x4 perspectiveFovMatrix_;

    //�r���[�|�[�g�s��
    Matrix4x4 viewportMatrix_;

public:
    //�R���X�g���N�^
    Camera();

    //�f�X�g���N�^
    ~Camera();

    //������
    void Initialize();

    /// <summary>
    /// �������e�s��̍쐬
    /// </summary>
    /// <param name="fovY"></param>
    /// <param name="aspectRatio"></param>
    /// <param name="nearClip"></param>
    /// <param name="farClip"></param>
    void MakePerspectiveFovMatrix(float fovY = 0.63f, float aspectRatio = 1.33f, float nearClip, float farClip);


    /// <summary>
    /// ���ˍs��̍쐬
    /// </summary>
    /// <param name="left"></param>
    /// <param name="top"></param>
    /// <param name="right"></param>
    /// <param name="bottom"></param>
    /// <param name="nearClip"></param>
    /// <param name="farClip"></param>
    void MakeOrthographicMatrix(float left = -160.0f, float top = 160.0f, float right = 200.0f, float bottom = 300.0f, float nearClip = 0.1f, float farClip = 1000.0f);

    /// <summary>
    /// �r���[�|�[�g�ϊ��s��̍쐬
    /// </summary>
    /// <param name="left"></param>
    /// <param name="top"></param>
    /// <param name="width"></param>
    /// <param name="height"></param>
    /// <param name="minDepth"></param>
    /// <param name="maxDepth"></param>
    void MakeViewportMatrix(float left = 100.0f, float top = 200.0f, float width = 600.0f, float height = 300.0f, float minDepth = 0.0f, float maxDepth = 1.0f);

    /// <summary>
    /// �������e�s��̍X�V
    /// </summary>
    void UpdatePerspectiveFovMatrix();

    /// <summary>
    /// ���ˍs��̍X�V
    /// </summary>
    void UpdateOrthographicMatrix();

    /// <summary>
    /// �������e�s��̍X�V
    /// </summary>
    void UpdateViewportMatrix();
};

