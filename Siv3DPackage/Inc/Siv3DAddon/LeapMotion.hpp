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
		*	@brief Leap Motion に認識された指またはツール
		*/
		struct Pointable
		{
			/**
			*	指またはツールが指す方向の単位ベクトル
			*/
			Vec3 direction;

			/**
			*	先端の位置 [mm]
			*/
			Vec3 pos;

			/**
			*	安定するよう調整された先端の位置 [mm]
			*/
			Vec3 stabilizedPos;

			/**
			*	先端の速度 [mm/s]
			*/
			Vec3 velocity;

			/**
			*	Leap Motion に認識されている時間 [秒]
			*/
			float timeVisibleSec;

			/**
			*	推測される長さ [mm]
			*/
			float length;

			/**
			*	推測される幅 [mm]
			*/
			float width;

			/**
			*	Pointable の ID
			*/
			int id;

			/**
			*	関連付けられた Hand の ID
			*/
			int handID;

			/**
			*	指と推測されるなら true, ツールと推測されるなら false
			*/
			bool isFinger;
		};

		/**
		*	@brief Leap Motion に認識された手
		*/
		struct Hand
		{
			/**
			*	手のひらから指先への方向の単位ベクトル
			*/
			Vec3 direction;

			/**
			*	手のひらの方向の単位ベクトル
			*/
			Vec3 normal;

			/**
			*	手のひらの中央の位置 [mm]
			*/
			Vec3 pos;

			/**
			*	安定するよう調整された手のひらの中央の位置 [mm]
			*/
			Vec3 stabilizedPos;

			/**
			*	手のひらの速度 [mm/s]
			*/
			Vec3 velocity;

			/**
			*	手の湾曲にフィットする仮想的な球の中心位置 [mm]
			*/
			Vec3 sphereCenter;

			/**
			*	手の湾曲にフィットする仮想的な球の半径 [mm]
			*/
			float sphereRadius;

			/**
			*	Leap Motion に認識されている時間 [秒]
			*/
			float timeVisibleSec;

			/**
			*	認識された指の本数
			*/
			int fingerCount;

			/**
			*	認識されたツールの個数
			*/
			int toolCount;

			/**
			*	Hand の ID
			*/
			int id;

			/**
			*	この Hand に関連付けられたすべての Pointable
			*/
			std::vector<Pointable> pointables;
		};

		/**
		*	@brief Leap Motion が認識するジェスチャーの種類
		*/
		enum class GestureType
		{
			/**
			*	未定義
			*/
			Undefined,

			/**
			*	円を描く動作
			*/
			Circle,

			/**
			*	線を描く動作
			*/
			Swipe,

			/**
			*	ピアノの鍵盤をたたくような動作
			*/
			KeyTap,

			/**
			*	正面にタッチするような動作
			*/
			ScreenTap
		};

		/**
		*	@brief Leap Motion が認識したジェスチャーの状態
		*/
		enum class GestureState
		{
			/**
			*	不正値
			*/
			Invalid,

			/**
			*	ジェスチャーが始まった
			*/
			Start,

			/**
			*	ジェスチャーが継続中である
			*/
			Update,

			/**
			*	ジェスチャーが終了した
			*/
			Stop,
		};

		/**
		*	@brief Leap Motion が認識した Circle ジェスチャーの回転方向
		*/
		enum class CircleClockwiseness
		{
			/**
			*	時計回り
			*/
			Clockwise,

			/**
			*	反時計回り
			*/
			Counterclockwise,
		};

		/**
		*	@brief Leap Motion に認識されたジェスチャー
		*/
		struct Gesture
		{
			/**
			*	ジェスチャーの種類
			*/
			GestureType type = GestureType::Undefined;

			/**
			*	ジェスチャーの名前
			*/
			Property_Get(String, gestureName) const;

			/**
			*	ジェスチャーの位置、Circle の場合は円の中心位置 [mm]
			*/
			Vec3 pos;

			/**
			*	ジェスチャーの方向の単位ベクトル
			*/
			Vec3 direction;

			/**
			*	ジェスチャーの速さ [mm/s] （Swipe のみ）
			*/
			double speed = 0.0;

			/**
			*	ジェスチャーの開始位置 [mm]（Swipe のみ）
			*/
			Vec3 startPos = { 0.0, 0.0, 0.0 };

			/**
			*	ジェスチャーの周回数（Circle のみ）
			*/
			double progress = 0.0;

			/**
			*	ジェスチャーの半径（Circle のみ）
			*/
			double radius = 0.0;

			/**
			*	ジェスチャーの回転方向（Circle のみ）
			*/
			CircleClockwiseness clockwiseness = CircleClockwiseness::Clockwise;

			/**
			*	ジェスチャーの状態
			*/
			GestureState state = GestureState::Invalid;

			/**
			*	ジェスチャーの ID
			*/
			int id;

			/**
			*	ジェスチャーに関連付けられた Hand の ID
			*/
			int handID;

			/**
			*	ジェスチャーに関連付けられた Pointable の ID
			*/
			int pointableID;
		};

		/**
		*	@brief Leap Motion コントローラ
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
		*	LeapMotionSiv3D アドオンを登録して、LeapMotion API を利用可能にします。
		*	@return 登録に成功した場合 true, それ以外の場合 false
		*/
		inline
		bool
			RegisterAddon(
			);

		/**
		*	Leap Motion デバイスが接続されているかを返します。
		*	@return Leap Motion デバイスが接続されている場合 true, それ以外の場合 false
		*/
		inline
		bool
			IsConnected(
			);

		/**
		*	Leap Motion が認識した Hand の一覧を返します。
		*	@return Leap Motion が認識した Hand の一覧
		*/
		inline
		std::vector<s3dLeap::Hand>
			Hands(
			);

		/**
		*	Leap Motion が認識した Pointable の一覧を返します。
		*	@return Leap Motion が認識した Pointable の一覧
		*/
		inline
		std::vector<s3dLeap::Pointable>
			Pointables(
			);

		/**
		*	Leap Motion が認識したジェスチャーの一覧を返します。
		*	@return Leap Motion が認識したジェスチャーの一覧
		*	@note EnableGesture() によって有効にしたジェスチャーのみ認識します。
		*	デフォルトではすべてのジェスチャーが無効です。
		*/
		inline
		std::vector<s3dLeap::Gesture>
			Gestures(
			);

		/**
		*	Leap Motion のジェスチャー認識を設定します。
		*	@param type ジェスチャーの種類
		*	@param enable 有効にする場合 true, 無効にする場合 false
		*	@note この関数で有効にしたジェスチャーのみ認識します。デフォルトではすべてのジェスチャーが無効です。
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
