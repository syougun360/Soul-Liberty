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
# include <memory>
# include "SivHandle.hpp"
# include "SivColor.hpp"
# include "SivHSV.hpp"
# include "SivPointVector.hpp"
# include "SivRectangle.hpp"
# include "SivPropertyMacro.hpp"
# include "SivTexture.hpp"
# include "SivFont.hpp"
# include "SivOptional.hpp"
# include "SivGUIWidget.hpp"


namespace s3d
{
	struct GUISkin
	{
		Color frame0;

		Color frame1;

		Color frame2;

		Color frameHL;
		
		Color line;

		Color itemFrame;

		Color disabledItem;

		Color toggleLeftColor;
		
		Color toggleRightColor;
		
		Color base;
		
		Color baseHL;
		
		Color mouseOver;
		
		Color mouseOverHL;
		
		Color mouseOverGlow;
		
		Color pressed;
		
		Color pressedHL;
				
		Color checkBoxColor;
		
		Color checkBoxMouseOverColor;
		
		optional<Color> backgroundColor;
		
		optional<Color> unactiveColor;
		
		Color textColor;

		optional<Color> textShadowColor;
		
		optional<Texture> backgroundTexture;
		
		bool repeatBackgroundTexture;

		static GUISkin Default(const Color& color = { 0, 140, 220 })
		{
			const HSV baseHSV(color);
			GUISkin skin;
			skin.frame0 = baseHSV - HSV(0, 0.0, 0.5);
			skin.frame1 = Color(color + HSV(0, -0.05, -0.05));
			skin.frame2 = baseHSV - HSV(0, 0.0, 0.5);
			skin.frameHL = baseHSV + HSV(0, -0.2, 0.25);
			skin.line = baseHSV - HSV(0, 0.0, 0.5);
			skin.itemFrame = baseHSV - HSV(0, 0.0, 0.5);
			skin.disabledItem = baseHSV - HSV(0, 0.6, -0.1);
			skin.toggleLeftColor = baseHSV - HSV(0, 0.35, 0.25);
			skin.toggleRightColor = baseHSV + HSV(8, 0.25, 0.2);
			skin.base = baseHSV;
			skin.baseHL = baseHSV + HSV(0, -0.2, 0.25);
			skin.mouseOver = baseHSV + HSV(0, -0.3, 0.15);
			skin.mouseOverHL = baseHSV + HSV(0, -0.5, 0.35);
			skin.mouseOverGlow = (baseHSV + HSV(0, -0.1, 0.6)).toColor().setAlpha(80);
			skin.pressed = baseHSV + HSV(8, -0.3, 0.15);
			skin.pressedHL = baseHSV + HSV(8, -0.5, 0.35);
			skin.checkBoxColor = HSV(baseHSV.h, 0.1, 1.0);
			skin.checkBoxMouseOverColor = Palette::White;
			skin.backgroundColor = Color(color + HSV(0, -0.5, 0.2)).setAlpha(240);
			skin.unactiveColor = Color(color + HSV(0, -0.8, 0.2)).setAlpha(140);
			skin.textColor = Palette::White;
			skin.textShadowColor = none;
			skin.repeatBackgroundTexture = true;
			return skin;
		}
	};

	
	class GUI
	{
	private:

		class Handle{};

		typedef Siv3DHandle<Handle> GUIHandle;

		std::shared_ptr<GUIHandle> m_handle;

	public:

		GUI(
			);

		explicit GUI(
			const GUISkin& skin
			);

		GUI(
			const GUISkin& skin,
			const Font& font
			);

		virtual ~GUI(
			);

		void
			release(
			);

		explicit operator bool() const;

		Property_Get(HandleIDType, id) const;

		Property_Get(bool, isEmpty) const;

		Property_Get(Rect, rect) const;

		Property_Get(GUISkin, skin) const;

		Property_Get(bool, isActive) const;

		Property_Get(bool, isVisible) const;

		Property_Get(int, zPos) const;

		bool operator == (const GUI& gui) const;

		bool operator != (const GUI& gui) const;

		void setActive(bool active);

		void setVisible(bool visible);

		void show(bool show)
		{
			setActive(show);

			setVisible(show);
		}

		void setPos(int x, int y);

		void setPos(const Point& pos);

		// 数字が大きいほど手前、デフォルトは 0
		void setZPos(int z);

		void setSkin(const GUISkin& skin);

		void setMargin(int margin);

		void setMargin(int x, int y);

		void setMargin(int top, int right, int bottom, int left);

		void setSpacing(int spacing);

		void setSpacing(int x, int y);


		void addText(const Widget::Text& text);

		void addText(const String& name, const Widget::Text& text);

		void addNewLine(const Widget::NewLine& newLine = {});

		void addTexture(const Widget::Texture& texture);

		void addTexture(const String& name, const Widget::Texture& texture);

		void addSpace(const Widget::Space& space);

		void addHorizontalLine(const Widget::HorizontalLine& horizontalLine = { 1 });

		void addButton(const Widget::Button& button);

		void addButton(const String& name, const Widget::Button& button);

		void addToggleSwitch(const Widget::ToggleSwitch& toggleSwitch);

		void addToggleSwitch(const String& name, const Widget::ToggleSwitch& toggleSwitch);

		void addSlider(const Widget::Slider& slider);

		void addSlider(const String& name, const Widget::Slider& slider);

		void addCheckBox(const Widget::CheckBox& checkBox);

		void addCheckBox(const String& name, const Widget::CheckBox& checkBox);

		void addRadioButton(const String& name, const Widget::RadioButton& radioButton);

		GUIButton button(const String& name) const;

		GUIText text(const String& name) const;

		GUIToggleSwitch toggleSwitch(const String& name) const;

		GUISlider slider(const String& name) const;

		GUICheckBox checkBox(const String& name) const;

		GUIRadioButton radioButton(const String& name) const;
	};


	class GUIText
	{
	private:

		GUI m_gui;

		String m_name;

	public:

		GUIText(){}

		GUIText(const GUI& gui, const String& name)
			: m_gui{ gui }, m_name(name) {}

		void setText(const String& text);

		Property_Get(Rect, rect) const;
		
		Property_Get(String, text) const;
	};


	class GUIButton
	{
	private:

		GUI m_gui;
		
		String m_name;

	public:

		GUIButton(){}

		GUIButton(const GUI& gui, const String& name)
			: m_gui{ gui }, m_name(name) {}
		
		void setEnabled(bool enabled);

		Property_Get(Rect, rect) const;
		
		Property_Get(bool, isEnabled) const;
		
		Property_Get(bool, mouseOver) const;
		
		Property_Get(bool, pressed) const;
		
		Property_Get(bool, pushed) const;
	};


	class GUIToggleSwitch
	{
	private:

		GUI m_gui;

		String m_name;

	public:

		GUIToggleSwitch(){}
		
		GUIToggleSwitch(const GUI& gui, const String& name)
			: m_gui{ gui }, m_name(name) {}

		void setEnabled(bool enabled);
		
		void setSwitch(bool right);

		Property_Get(Rect, rect) const;
		
		Property_Get(Rect, switchRect) const;
		
		Property_Get(bool, isEnabled) const;
		
		Property_Get(bool, isRight) const;
		
		Property_Get(bool, hasChanged) const;
	};


	class GUISlider
	{
	private:

		GUI m_gui;

		String m_name;

	public:

		GUISlider(){}
		
		GUISlider(const GUI& gui, const String& name)
			: m_gui{ gui }, m_name(name) {}
	
		void setEnabled(bool enabled);
		
		void setValue(double value);
		
		void setSliderPos(int pos);

		Property_Get(Rect, rect) const;
		
		Property_Get(Rect, switchRect) const;
		
		Property_Get(int, sliderWidth) const;
		
		Property_Get(int, sliderPos) const;
		
		Property_Get(bool, isEnabled) const;
		
		Property_Get(double, value) const;
		
		Property_Get(int, valueInt) const;
		
		Property_Get(bool, hasChanged) const;
	};


	class GUICheckBox
	{
	private:

		GUI m_gui;

		String m_name;

	public:

		GUICheckBox(){}

		GUICheckBox(const GUI& gui, const String& name)
			: m_gui{ gui }, m_name(name) {}

		void setEnabled(bool enabled);
		
		bool _get_checked(int index) const;
		
		bool _set_checked(int index, bool checked);
		
		bool _get_enabled(int index) const;
		
		bool _set_enabled(int index, bool enabled);
		
		__declspec(property(get = _get_checked, put = _set_checked)) bool checked[];
		
		__declspec(property(get = _get_enabled, put = _set_enabled)) bool enabled[];
		
		Property_Get(size_t, size) const;
		
		Property_Get(Rect, rect) const;
		
		Property_Get(bool, isEnabled) const;
		
		Property_Get(bool, hasChanged) const;
	};


	class GUIRadioButton
	{
	private:

		GUI m_gui;

		String m_name;

	public:

		GUIRadioButton(){}

		GUIRadioButton(const GUI& gui, const String& name)
			: m_gui{ gui }, m_name(name) {}

		void setEnabled(bool enabled);

		optional<unsigned> getCheckedItem() const;

		void setCheckedItem(unsigned item);

		void clearCheckedItem();

		bool _get_enabled(int index) const;

		bool _set_enabled(int index, bool enabled);

		__declspec(property(get = _get_enabled, put = _set_enabled)) bool enabled[];

		Property_Get(size_t, size) const;

		Property_Get(Rect, rect) const;

		Property_Get(bool, isEnabled) const;

		Property_Get(bool, hasChanged) const;
	};
}
