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

namespace s3d
{
	namespace s3dLeap
	{
		inline String Gesture::_get_gestureName() const
		{
			const static String gestureNames[]{ L"Undefined", L"Circle", L"Swipe", L"KeyTap", L"ScreenTap" };

			return gestureNames[static_cast<unsigned>(type)];
		}

		inline void LeapMotionController::updateHands()
		{
			m_hands.clear();

			for (int i = 0; i < m_frame.hands().count(); ++i)
			{
				const auto& hand = m_frame.hands()[i];
				const auto direction = hand.direction();
				const auto palmNormal = hand.palmNormal();
				const auto palmPosition = hand.palmPosition();
				const auto stabilizedPalmPosition = hand.stabilizedPalmPosition();
				const auto palmVelocity = hand.palmVelocity();
				const auto sphereCenter = hand.sphereCenter();

				Hand handDetail;
				handDetail.id = hand.id();
				handDetail.direction.set(direction.x, direction.y, -direction.z);
				handDetail.normal.set(palmNormal.x, palmNormal.y, -palmNormal.z);
				handDetail.pos.set(palmPosition.x, palmPosition.y, -palmPosition.z);
				handDetail.stabilizedPos.set(stabilizedPalmPosition.x, stabilizedPalmPosition.y, -stabilizedPalmPosition.z);
				handDetail.velocity.set(palmVelocity.x, palmVelocity.y, -palmVelocity.z);
				handDetail.sphereCenter.set(sphereCenter.x, sphereCenter.y, -sphereCenter.z);
				handDetail.sphereRadius = hand.sphereRadius();
				handDetail.timeVisibleSec = hand.timeVisible();
				handDetail.fingerCount = hand.fingers().count();
				handDetail.toolCount = hand.tools().count();

				handDetail.pointables.reserve(hand.pointables().count());

				for (int k = 0; k < hand.pointables().count(); ++k)
				{
					const auto& pointable = hand.pointables()[k];
					const auto direction = pointable.direction();
					const auto tipPosition = pointable.tipPosition();
					const auto stabilizedTipPosition = pointable.stabilizedTipPosition();
					const auto velocity = pointable.tipVelocity();

					Pointable pointableDetail;
					pointableDetail.id = pointable.id();
					pointableDetail.handID = hand.id();
					pointableDetail.direction.set(direction.x, direction.y, -direction.z);
					pointableDetail.pos.set(tipPosition.x, tipPosition.y, -tipPosition.z);
					pointableDetail.stabilizedPos.set(stabilizedTipPosition.x, stabilizedTipPosition.y, -stabilizedTipPosition.z);
					pointableDetail.velocity.set(velocity.x, velocity.y, -velocity.z);
					pointableDetail.timeVisibleSec = pointable.timeVisible();
					pointableDetail.length = pointable.length();
					pointableDetail.width = pointable.width();
					pointableDetail.isFinger = pointable.isFinger();

					handDetail.pointables.push_back(pointableDetail);
				}

				m_hands.push_back(handDetail);
			}
		}

		inline void LeapMotionController::updatePointables()
		{
			m_pointables.clear();

			for (const auto& hand : m_hands)
			{
				for (const auto& pointable : hand.pointables)
				{
					m_pointables.push_back(pointable);
				}
			}
		}

		inline GestureState LeapMotionController::convertState(Leap::Gesture::State state)
		{
			switch (state)
			{
			case Leap::Gesture::STATE_START:
				return GestureState::Start;
			case Leap::Gesture::STATE_UPDATE:
				return GestureState::Update;
			case Leap::Gesture::STATE_STOP:
				return GestureState::Stop;
			default:
				return GestureState::Invalid;
			}
		}

		inline void LeapMotionController::updateGestures()
		{
			m_gestures.clear();

			for (int i = 0; i < m_frame.gestures().count(); ++i)
			{
				const auto& gesture = m_frame.gestures()[i];

				Gesture gestureDetail;
				gestureDetail.id = gesture.id();
				gestureDetail.handID = gesture.hands().isEmpty() ? -1 : gesture.hands()[0].id();
				gestureDetail.pointableID = gesture.pointables().isEmpty() ? -1 : gesture.pointables()[0].id();
				gestureDetail.state = convertState(gesture.state());

				switch (gesture.type())
				{
				case Leap::Gesture::TYPE_CIRCLE:
				{
					const Leap::CircleGesture& circleGesture = gesture;
					const auto center = circleGesture.center();
					const auto normal = circleGesture.normal();

					gestureDetail.type = GestureType::Circle;
					gestureDetail.pos.set(center.x, center.y, -center.z);
					gestureDetail.direction.set(normal.x, normal.y, -normal.z);
					gestureDetail.progress = circleGesture.progress();
					gestureDetail.radius = circleGesture.radius();
					gestureDetail.clockwiseness =
						circleGesture.pointable().direction().angleTo(circleGesture.normal()) <= Leap::PI / 4
						? CircleClockwiseness::Clockwise : CircleClockwiseness::Counterclockwise;

					break;
				}
				case Leap::Gesture::TYPE_SWIPE:
				{
					const Leap::SwipeGesture& swipeGesture = gesture;
					const auto position = swipeGesture.position();
					const auto direction = swipeGesture.direction();
					const auto startPos = swipeGesture.startPosition();

					gestureDetail.type = GestureType::Swipe;
					gestureDetail.pos.set(position.x, position.y, -position.z);
					gestureDetail.direction.set(direction.x, direction.y, -direction.z);
					gestureDetail.speed = swipeGesture.speed();
					gestureDetail.startPos.set(startPos.x, startPos.y, -startPos.z);

					break;
				}
				case Leap::Gesture::TYPE_KEY_TAP:
				{
					const Leap::KeyTapGesture& keytapGesture = gesture;
					const auto position = keytapGesture.position();
					const auto direction = keytapGesture.direction();

					gestureDetail.type = GestureType::KeyTap;
					gestureDetail.pos.set(position.x, position.y, -position.z);
					gestureDetail.direction.set(direction.x, direction.y, -direction.z);

					break;
				}
				case Leap::Gesture::TYPE_SCREEN_TAP:
				{
					const Leap::ScreenTapGesture& screentapGesture = gesture;
					const auto position = screentapGesture.position();
					const auto direction = screentapGesture.direction();

					gestureDetail.type = GestureType::ScreenTap;
					gestureDetail.pos.set(position.x, position.y, -position.z);
					gestureDetail.direction.set(direction.x, direction.y, -direction.z);

					break;
				}
				default:
					gestureDetail.type = GestureType::Undefined; break;
				}

				m_gestures.push_back(gestureDetail);
			}
		}

		inline String LeapMotionController::getName() const
		{
			return name();
		}

		inline bool LeapMotionController::init()
		{
			return true;
		}

		inline bool LeapMotionController::update()
		{
			if (!isConnected)
			{
				return true;
			}

			m_frame = m_controller.frame();

			updateHands();

			updatePointables();

			updateGestures();

			return true;
		}

		inline bool LeapMotionController::_get_isConnected() const
		{
			return m_controller.isConnected();
		}

		inline const std::vector<Hand>& LeapMotionController::hands() const
		{
			return m_hands;
		}

		inline const std::vector<Pointable>& LeapMotionController::pointables() const
		{
			return m_pointables;
		}

		inline const std::vector<Gesture>& LeapMotionController::gestures() const
		{
			return m_gestures;
		}

		inline void LeapMotionController::enableGesture(GestureType type, bool enable)
		{
			switch (type)
			{
			case s3d::s3dLeap::GestureType::Circle:
				m_controller.enableGesture(Leap::Gesture::TYPE_CIRCLE, enable); break;
			case s3d::s3dLeap::GestureType::Swipe:
				m_controller.enableGesture(Leap::Gesture::TYPE_SWIPE, enable); break;
			case s3d::s3dLeap::GestureType::KeyTap:
				m_controller.enableGesture(Leap::Gesture::TYPE_KEY_TAP, enable); break;
			case s3d::s3dLeap::GestureType::ScreenTap:
				m_controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP, enable); break;
			default:
				break;
			}
		}
	}

	namespace LeapMotion
	{
		inline
			bool RegisterAddon()
		{
			return Addon::Register<s3dLeap::LeapMotionController>();
		}

		inline
			bool IsConnected()
		{
			if (auto p = Addon::GetAddon<s3dLeap::LeapMotionController>())
			{
				return p->isConnected;
			}
			else
			{
				return false;
			}
		}

		inline
			std::vector<s3dLeap::Hand> Hands()
		{
			if (auto p = Addon::GetAddon<s3dLeap::LeapMotionController>())
			{
				return p->hands();
			}
			else
			{
				return{};
			}
		}

		inline
			std::vector<s3dLeap::Pointable> Pointables()
		{
			if (auto p = Addon::GetAddon<s3dLeap::LeapMotionController>())
			{
				return p->pointables();
			}
			else
			{
				return{};
			}
		}

		inline
			std::vector<s3dLeap::Gesture> Gestures()
		{
			if (auto p = Addon::GetAddon<s3dLeap::LeapMotionController>())
			{
				return p->gestures();
			}
			else
			{
				return{};
			}
		}

		inline
			void EnableGesture(s3dLeap::GestureType type, bool enable)
		{
			if (auto p = Addon::GetAddon<s3dLeap::LeapMotionController>())
			{
				return p->enableGesture(type, enable);
			}
		}
	}
}

