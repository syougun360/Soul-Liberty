//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

# pragma once
# include <vector>
# include "SivForward.hpp"
# include "SivOptional.hpp"
# include "SivPropertyMacro.hpp"
# include "SivPointVector.hpp"

namespace s3d
{
	/**
	*	@brief キー
	*
	*	キーボードの特定のキーを示します。
	*/
	class Key
	{
	private:

		unsigned char m_virtualKeyCode = 0;
		
		friend struct Input;

	public:

		/**
		*
		*/
		Key(){}

		/**
		*
		*	@param alnum
		*/
		explicit Key(wchar_t alnum);

		/**
		*
		*/
		Property_Get(bool, clicked) const;

		/**
		*
		*/
		Property_Get(bool, pressed) const;

		/**
		*
		*/
		Property_Get(bool, released) const;

		/**
		*
		*/
		Property_Get(unsigned char, code) const;
	};

	/**
	*
	*/
	inline bool operator == (const Key& key1, const Key& key2)
	{
		return key1.code == key2.code;
	}

	/**
	*
	*/
	inline bool operator != (const Key& key1, const Key& key2)
	{
		return !(key1 == key2);
	}

	struct Touch
	{
		Point pos;
		
		Point screenPos;
		
		optional<Point> previousPos;
		
		optional<Point> previousScreenPos;
		
		unsigned id;

		Property_Get(bool, clicked) const { return !previousPos; }
	};

	/**
	*	@brief
	*/
	struct Input
	{
		/**
		*	マウス左ボタン
		*/
		static Key MouseL;

		/**
		*	マウス右ボタン
		*/
		static Key MouseR;

		/**
		*	マウス中央ボタン
		*/
		static Key MouseM; 

		/**
		*	マウス X1 ボタン
		*/
		static Key MouseX1;			

		/**
		*	マウス X2 ボタン
		*/
		static Key MouseX2;

		/**
		*	Ctrl + break
		*/
		static Key KeyCancel; 

		/**
		*	Backspace
		*/
		static Key KeyBackspace;

		/**
		*	Tab
		*/
		static Key KeyTab;

		/**
		*	[Clear](NumLock を外した状態のテンキー5)
		*/
		static Key KeyClear;

		/**
		*	Enter
		*/
		static Key KeyEnter;

		/**
		*	Shift
		*/
		static Key KeyShift;

		/**
		*
		*/
		static Key KeyControl;

		/**
		*
		*/
		static Key KeyAlt;

		/**
		*
		*/
		static Key KeyPause;

		/**
		*
		*/
		static Key KeyEscape;

		/**
		*
		*/
		static Key KeySpace;

		/**
		*
		*/
		static Key KeyPageUp;

		/**
		*
		*/
		static Key KeyPageDown;

		/**
		*
		*/
		static Key KeyEnd;

		/**
		*
		*/
		static Key KeyHome;

		/**
		*
		*/
		static Key KeyLeft;

		/**
		*
		*/
		static Key KeyUp;

		/**
		*
		*/
		static Key KeyRight;

		/**
		*
		*/
		static Key KeyDown;

		/**
		*
		*/
		static Key KeyPrintScreen;

		/**
		*
		*/
		static Key KeyInsert;

		/**
		*
		*/
		static Key KeyDelete;

		/**
		*
		*/
		static Key KeyLShift;

		/**
		*
		*/
		static Key KeyRShift;

		/**
		*
		*/
		static Key KeyLControl;

		/**
		*
		*/
		static Key KeyRControl;

		/**
		*
		*/
		static Key KeyLAlt;

		/**
		*
		*/
		static Key KeyRAlt;

		/**
		*
		*/
		static Key Key0;

		/**
		*
		*/
		static Key Key1;

		/**
		*
		*/
		static Key Key2;

		/**
		*
		*/
		static Key Key3;

		/**
		*
		*/
		static Key Key4;

		/**
		*
		*/
		static Key Key5;

		/**
		*
		*/
		static Key Key6;

		/**
		*
		*/
		static Key Key7;

		/**
		*
		*/
		static Key Key8;

		/**
		*
		*/
		static Key Key9;

		/**
		*
		*/
		static Key KeyA;

		/**
		*
		*/
		static Key KeyB;

		/**
		*
		*/
		static Key KeyC;

		/**
		*
		*/
		static Key KeyD;

		/**
		*
		*/
		static Key KeyE;

		/**
		*
		*/
		static Key KeyF;

		/**
		*
		*/
		static Key KeyG;

		/**
		*
		*/
		static Key KeyH;

		/**
		*
		*/
		static Key KeyI;

		/**
		*
		*/
		static Key KeyJ;

		/**
		*
		*/
		static Key KeyK;

		/**
		*
		*/
		static Key KeyL;

		/**
		*
		*/
		static Key KeyM;

		/**
		*
		*/
		static Key KeyN;

		/**
		*
		*/
		static Key KeyO;

		/**
		*
		*/
		static Key KeyP;

		/**
		*
		*/
		static Key KeyQ;

		/**
		*
		*/
		static Key KeyR;

		/**
		*
		*/
		static Key KeyS;

		/**
		*
		*/
		static Key KeyT;

		/**
		*
		*/
		static Key KeyU;

		/**
		*
		*/
		static Key KeyV;

		/**
		*
		*/
		static Key KeyW;

		/**
		*
		*/
		static Key KeyX;

		/**
		*
		*/
		static Key KeyY;

		/**
		*
		*/
		static Key KeyZ;

		/**
		*
		*/
		static Key KeyNum0;

		/**
		*
		*/
		static Key KeyNum1;

		/**
		*
		*/
		static Key KeyNum2;

		/**
		*
		*/
		static Key KeyNum3;

		/**
		*
		*/
		static Key KeyNum4;

		/**
		*
		*/
		static Key KeyNum5;

		/**
		*
		*/
		static Key KeyNum6;

		/**
		*
		*/
		static Key KeyNum7;

		/**
		*
		*/
		static Key KeyNum8;

		/**
		*
		*/
		static Key KeyNum9;

		/**
		*
		*/
		static Key KeyNumMultiply;

		/**
		*
		*/
		static Key KeyNumAdd;

		/**
		*
		*/
		static Key KeyNumSeparator;

		/**
		*
		*/
		static Key KeyNumSubtract;

		/**
		*
		*/
		static Key KeyNumDecimal;

		/**
		*
		*/
		static Key KeyNumDivide;

		/**
		*
		*/
		static Key KeyNumLock;

		/**
		*
		*/
		static Key KeyF1;

		/**
		*
		*/
		static Key KeyF2;

		/**
		*
		*/
		static Key KeyF3;

		/**
		*
		*/
		static Key KeyF4;

		/**
		*
		*/
		static Key KeyF5;

		/**
		*
		*/
		static Key KeyF6;

		/**
		*
		*/
		static Key KeyF7;

		/**
		*
		*/
		static Key KeyF8;

		/**
		*
		*/
		static Key KeyF9;

		/**
		*
		*/
		static Key KeyF10;

		/**
		*
		*/
		static Key KeyF11;

		/**
		*
		*/
		static Key KeyF12;

		/**
		*
		*/
		static Key KeyColon;

		/**
		*
		*/
		static Key KeySemicolon;

		/**
		*
		*/
		static Key KeyComma;

		/**
		*
		*/
		static Key KeyMinus;

		/**
		*
		*/
		static Key KeyPeriod;

		/**
		*
		*/
		static Key KeySlash;

		/**
		*
		*/
		static Key KeyAt;

		/**
		*
		*/
		static Key KeyLBracket;

		/**
		*
		*/
		static Key KeyRBracket;

		/**
		*
		*/
		static Key KeyYen;

		/**
		*
		*/
		static Key KeyCaret;

		/**
		*
		*/
		static Key KeyBackslash;

		/**
		*
		*	@return
		*/
		static bool
			AnyKeyClicked(
			);

		/**
		*
		*	@return
		*/
		static bool
			AnyKeyPressed(
			);

		/**
		*
		*	@return
		*/
		static bool
			AnyKeyReleased(
			);

		/**
		*
		*	@return
		*/
		static std::vector<Key>
			GetActiveKeys(
			);

		/**
		*
		*	@return
		*/
		static String
			GetChars(
			);

		/**
		*
		*	@param text
		*/
		static void
			GetCharsHelper(
			String& text
			);

		/**
		*	マルチタッチをサポートしているかを返します。
		*	@return
		*/
		static bool
			SupportsMultiTouch(
			);

		/**
		*	マルチタッチの状態を返します。
		*	@return
		*/
		static std::vector<Touch>
			GetTouches(
			);
	};

	/**
	*	@brief マウス
	*/
	namespace Mouse
	{
		/**
		*
		*	@return
		*/
		bool
			OnClient(
			);

		/**
		*
		*	@return
		*/
		bool
			LeftClicked(
			);

		/**
		*
		*	@return
		*/
		bool
			RightClicked(
			);

		/**
		*
		*	@return
		*/
		Point
			Pos(
			);

		/**
		*
		*	@return
		*/
		Point
			PreviousPos(
			);

		/**
		*
		*	@return
		*/
		Point
			Delta(
			);

		/**
		*
		*	@return
		*/
		Point
			HalfPreviousPos(
			);

		/**
		*
		*	@return
		*/
		Point
			ScreenPos(
			);

		/**
		*
		*	@return
		*/
		Point
			PreviousScreenPos(
			);

		/**
		*
		*	@return
		*/
		Point
			ScreenDelta(
			);

		/**
		*
		*	@return
		*/
		int
			Wheel(
			);

		/**
		*
		*	@return
		*/
		int
			WheelH(
			);

		/**
		*
		*	@return
		*/
		const s3d::Ray&
			Ray(
			);
	}
}
