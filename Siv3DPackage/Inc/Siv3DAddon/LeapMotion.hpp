//-------------------------------------------------------------------------------
//
//	Copyright (C) 2008-2014 Reputeless
//
//	Licensed under the Apache License, Version 2.0 (the "License");
//	you may not use this file except in compliance with the License.
//	You may obtain a copy of the License at
//
//	http ://www.apache.org/licenses/LICENSE-2.0
//
//	Unless required by applicable law or agreed to in writing, software
//	distributed under the License is distributed on an "AS IS" BASIS,
//	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//	See the License for the specific language governing permissions and
//	limitations under the License.
//
//--------------------------------------------------------------------------------

# pragma once
# include <Leap.h>
# pragma comment (lib, "Leap")

namespace s3d
{
	namespace s3dLeap
	{
		/**
		*	@brief Leap Motion �ɔF�����ꂽ�w�܂��̓c�[��
		*/
		struct Pointable
		{
			/**
			*	�w�܂��̓c�[�����w�������̒P�ʃx�N�g��
			*/
			Vec3 direction;

			/**
			*	��[�̈ʒu [mm]
			*/
			Vec3 pos;

			/**
			*	���肷��悤�������ꂽ��[�̈ʒu [mm]
			*/
			Vec3 stabilizedPos;

			/**
			*	��[�̑��x [mm/s]
			*/
			Vec3 velocity;

			/**
			*	Leap Motion �ɔF������Ă��鎞�� [�b]
			*/
			float timeVisibleSec;

			/**
			*	��������钷�� [mm]
			*/
			float length;

			/**
			*	��������镝 [mm]
			*/
			float width;

			/**
			*	Pointable �� ID
			*/
			int id;

			/**
			*	�֘A�t����ꂽ Hand �� ID
			*/
			int handID;

			/**
			*	�w�Ɛ��������Ȃ� true, �c�[���Ɛ��������Ȃ� false
			*/
			bool isFinger;
		};

		/**
		*	@brief Leap Motion �ɔF�����ꂽ��
		*/
		struct Hand
		{
			/**
			*	��̂Ђ炩��w��ւ̕����̒P�ʃx�N�g��
			*/
			Vec3 direction;

			/**
			*	��̂Ђ�̕����̒P�ʃx�N�g��
			*/
			Vec3 normal;

			/**
			*	��̂Ђ�̒����̈ʒu [mm]
			*/
			Vec3 pos;

			/**
			*	���肷��悤�������ꂽ��̂Ђ�̒����̈ʒu [mm]
			*/
			Vec3 stabilizedPos;

			/**
			*	��̂Ђ�̑��x [mm/s]
			*/
			Vec3 velocity;

			/**
			*	��̘p�ȂɃt�B�b�g���鉼�z�I�ȋ��̒��S�ʒu [mm]
			*/
			Vec3 sphereCenter;

			/**
			*	��̘p�ȂɃt�B�b�g���鉼�z�I�ȋ��̔��a [mm]
			*/
			float sphereRadius;

			/**
			*	Leap Motion �ɔF������Ă��鎞�� [�b]
			*/
			float timeVisibleSec;

			/**
			*	�F�����ꂽ�w�̖{��
			*/
			int fingerCount;

			/**
			*	�F�����ꂽ�c�[���̌�
			*/
			int toolCount;

			/**
			*	Hand �� ID
			*/
			int id;

			/**
			*	���� Hand �Ɋ֘A�t����ꂽ���ׂĂ� Pointable
			*/
			std::vector<Pointable> pointables;
		};

		/**
		*	@brief Leap Motion ���F������W�F�X�`���[�̎��
		*/
		enum class GestureType
		{
			/**
			*	����`
			*/
			Undefined,

			/**
			*	�~��`������
			*/
			Circle,

			/**
			*	����`������
			*/
			Swipe,

			/**
			*	�s�A�m�̌��Ղ��������悤�ȓ���
			*/
			KeyTap,

			/**
			*	���ʂɃ^�b�`����悤�ȓ���
			*/
			ScreenTap
		};

		/**
		*	@brief Leap Motion ���F�������W�F�X�`���[�̏��
		*/
		enum class GestureState
		{
			/**
			*	�s���l
			*/
			Invalid,

			/**
			*	�W�F�X�`���[���n�܂���
			*/
			Start,

			/**
			*	�W�F�X�`���[���p�����ł���
			*/
			Update,

			/**
			*	�W�F�X�`���[���I������
			*/
			Stop,
		};

		/**
		*	@brief Leap Motion ���F������ Circle �W�F�X�`���[�̉�]����
		*/
		enum class CircleClockwiseness
		{
			/**
			*	���v���
			*/
			Clockwise,

			/**
			*	�����v���
			*/
			Counterclockwise,
		};

		/**
		*	@brief Leap Motion �ɔF�����ꂽ�W�F�X�`���[
		*/
		struct Gesture
		{
			/**
			*	�W�F�X�`���[�̎��
			*/
			GestureType type = GestureType::Undefined;

			/**
			*	�W�F�X�`���[�̖��O
			*/
			Property_Get(String, gestureName) const;

			/**
			*	�W�F�X�`���[�̈ʒu�ACircle �̏ꍇ�͉~�̒��S�ʒu [mm]
			*/
			Vec3 pos;

			/**
			*	�W�F�X�`���[�̕����̒P�ʃx�N�g��
			*/
			Vec3 direction;

			/**
			*	�W�F�X�`���[�̑��� [mm/s] �iSwipe �̂݁j
			*/
			double speed = 0.0;

			/**
			*	�W�F�X�`���[�̊J�n�ʒu [mm]�iSwipe �̂݁j
			*/
			Vec3 startPos = { 0.0, 0.0, 0.0 };

			/**
			*	�W�F�X�`���[�̎��񐔁iCircle �̂݁j
			*/
			double progress = 0.0;

			/**
			*	�W�F�X�`���[�̔��a�iCircle �̂݁j
			*/
			double radius = 0.0;

			/**
			*	�W�F�X�`���[�̉�]�����iCircle �̂݁j
			*/
			CircleClockwiseness clockwiseness = CircleClockwiseness::Clockwise;

			/**
			*	�W�F�X�`���[�̏��
			*/
			GestureState state = GestureState::Invalid;

			/**
			*	�W�F�X�`���[�� ID
			*/
			int id;

			/**
			*	�W�F�X�`���[�Ɋ֘A�t����ꂽ Hand �� ID
			*/
			int handID;

			/**
			*	�W�F�X�`���[�Ɋ֘A�t����ꂽ Pointable �� ID
			*/
			int pointableID;
		};

		/**
		*	@brief Leap Motion �R���g���[��
		*/
		class LeapMotionController : public ISiv3DAddon
		{
		private:

			Leap::Controller m_controller;

			Leap::Frame m_frame;

			std::vector<Hand> m_hands;

			std::vector<Pointable> m_pointables;

			std::vector<Gesture> m_gestures;

			void updateHands();

			void updatePointables();

			GestureState convertState(Leap::Gesture::State state);

			void updateGestures();

		public:

			static const String& name()
			{
				static const String name = L"LeapMotionSiv3D";
				return name;
			}

			String getName() const override;

			bool init() override;

			bool update() override;

			Property_Get(bool, isConnected) const;

			const std::vector<Hand>& hands() const;

			const std::vector<Pointable>& pointables() const;

			const std::vector<Gesture>& gestures() const;

			void enableGesture(GestureType type, bool enable = true);
		};
	}

	/**
	*	@brief Leap Motion
	*/
	namespace LeapMotion
	{
		/**
		*	LeapMotionSiv3D �A�h�I����o�^���āALeapMotion API �𗘗p�\�ɂ��܂��B
		*	@return �o�^�ɐ��������ꍇ true, ����ȊO�̏ꍇ false
		*/
		inline
		bool
			RegisterAddon(
			);

		/**
		*	Leap Motion �f�o�C�X���ڑ�����Ă��邩��Ԃ��܂��B
		*	@return Leap Motion �f�o�C�X���ڑ�����Ă���ꍇ true, ����ȊO�̏ꍇ false
		*/
		inline
		bool
			IsConnected(
			);

		/**
		*	Leap Motion ���F������ Hand �̈ꗗ��Ԃ��܂��B
		*	@return Leap Motion ���F������ Hand �̈ꗗ
		*/
		inline
		std::vector<s3dLeap::Hand>
			Hands(
			);

		/**
		*	Leap Motion ���F������ Pointable �̈ꗗ��Ԃ��܂��B
		*	@return Leap Motion ���F������ Pointable �̈ꗗ
		*/
		inline
		std::vector<s3dLeap::Pointable>
			Pointables(
			);

		/**
		*	Leap Motion ���F�������W�F�X�`���[�̈ꗗ��Ԃ��܂��B
		*	@return Leap Motion ���F�������W�F�X�`���[�̈ꗗ
		*	@note EnableGesture() �ɂ���ėL���ɂ����W�F�X�`���[�̂ݔF�����܂��B
		*	�f�t�H���g�ł͂��ׂẴW�F�X�`���[�������ł��B
		*/
		inline
		std::vector<s3dLeap::Gesture>
			Gestures(
			);

		/**
		*	Leap Motion �̃W�F�X�`���[�F����ݒ肵�܂��B
		*	@param type �W�F�X�`���[�̎��
		*	@param enable �L���ɂ���ꍇ true, �����ɂ���ꍇ false
		*	@note ���̊֐��ŗL���ɂ����W�F�X�`���[�̂ݔF�����܂��B�f�t�H���g�ł͂��ׂẴW�F�X�`���[�������ł��B
		*/
		inline
		void
			EnableGesture(
				s3dLeap::GestureType type,
				bool enable = true
				);
	}
}

# include "LeapMotion.inl"
