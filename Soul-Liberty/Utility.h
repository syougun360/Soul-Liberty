
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once

#include <cmath>
#include <Siv3D.hpp>

///	���p�I�֐�
namespace utility
{
	//	�w�肵���{�b�N�X���Ƀ}�E�X�����݂��邩�ǂ���
	bool IsMouseIncludeRectPointer(const Point& pos, const Point& size);

	bool IsMouseIncludeCirclePointer(const Point& pos, const int radius);

	//�@�����𑪂�
	float Distance(const Float3 goal_pos, const Float3 start_pos);
	float Distance(const float goal_pos, const float start_pos);

	//�@�b�w�肵���͈͂Ɋ܂܂�Ă��邩�ǂ���
	template<typename T>
	bool IsInclude(const T value, const T value2, const T include_value)
	{
		if (abs(value - value2) < include_value)
		{
			return true;
		}
		return false;
	}

	//�@�w�肵�������Ɉړ�����
	Float3 MoveBy(const Float3 &pos, const Float3 &goal_pos, const float speed);

	//�@�w��ʒu�Ɉړ�
	void MoveTo(const Float3 goal_pos, Float3 &pos, const Float3 velocity);
	void MoveTo(const Float2 goal_pos, Float2 &pos, const Float2 velocity);

	// �~�^��
	void CircleRotation(float &pos1, float &pos2, const float ang, const float targetpos1, const float targetpos2);

	// �W�I���g���Ƀ}�b�s���O�����e�N�X�`���𔽓]
	Mesh CreateMirroredBox(const Float3& size, const int dir);

	//�@ID���擾����ꍇ�g�p����
	template<typename T>
	static int GetId()
	{
		static int id;
		return id++;
	}
}

