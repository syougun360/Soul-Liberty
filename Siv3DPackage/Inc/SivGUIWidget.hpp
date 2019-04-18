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
# include "SivString.hpp"
# include "SivOptional.hpp"
# include "SivTexture.hpp"

namespace s3d
{
	enum class Align
	{
		Left,

		Center,

		Right
	};

	namespace Widget
	{
		struct Text
		{
			Text(
			const String& _text = L"text",
			optional<int> _width = unspecified,
			Align _align = Align::Left
			)
			: text(_text),
			width(_width),
			align(_align) {}

			String text = L"text";
			
			optional<int> width = unspecified;
			
			Align align = Align::Left;
		};

		struct NewLine
		{
			NewLine() = default;
		};

		struct Texture
		{
			Texture(
			const TextureRegion& _texture,
			optional<int> _width = unspecified,
			Align _align = Align::Left
			)
			: texture(_texture),
			width(_width),
			align(_align) {}

			TextureRegion texture;
			
			optional<int> width = unspecified;
			
			Align align = Align::Left;
		};

		struct Space
		{
			Space(
			int width,
			int height
			)
			: size(width, height) {}

			Space(
				const Point& _size = { 0, 0 }
			)
				: size(_size) {}

			Point size = { 0, 0 };
		};

		struct HorizontalLine
		{
			HorizontalLine(
			int _thickness = 1,
			optional<int> _width = unspecified
			)
			: thickness(_thickness),
			width(_width){}

			int thickness = 1;

			optional<int> width = unspecified;
		};


		struct Button
		{
			Button(
			const String& _text = L"Button",
			optional<int> _width = unspecified,
			bool _enabled = true
			)
			: text(_text),
			width{ _width },
			enabled{ _enabled } {}

			String text = L"Button";

			optional<int> width = unspecified;

			bool enabled = true;
		};


		struct ToggleSwitch
		{
			ToggleSwitch(
			bool _isRight = false,
			const String& left = L"OFF",
			const String& right = L"ON",
			bool _enabled = true,
			optional<int> _width = unspecified
			)
			: textLeft(left),
			textRight(right),
			isRight{ _isRight },
			enabled{ _enabled },
			width(_width){}

			String textLeft = L"OFF";
			
			String textRight = L"ON";
			
			bool isRight = false;
			
			bool enabled = true;
			
			optional<int> width = unspecified;
		};


		struct Slider
		{
			Slider(
			double left = 0.0,
			double right = 100.0,
			double current = 50.0,
			optional<int> _width = unspecified,
			bool _enabled = true
			)
			: leftValue(left),
			rightValue(right),
			currentValue(current),
			width(_width),
			enabled(_enabled) {}

			double leftValue = 0.0;

			double rightValue = 100.0;

			double currentValue = 50.0;

			optional<int> width = unspecified;

			bool enabled = true;
		};


		struct CheckBox
		{
			struct Content
			{
				Content(String _label, bool _checked = false, bool _enabled = true)
				: label(_label),
				checked{ _checked },
				enabled{ _enabled }{}

				String label = L"label";

				bool checked = false;

				bool enabled = true;
			};

			CheckBox(
				const std::vector<String>& text,
				optional<int> _width = unspecified,
				bool _enabled = true
				)
				: width(_width),
				enabled(_enabled)
			{
				for (auto const& t : text)
				{
					m_contents.emplace_back(t, false, true);
				}
			}

			CheckBox(
				const std::vector<Content>& contents,
				optional<int> _width = unspecified,
				bool _enabled = true
				)
				: m_contents(contents),
				width(_width),
				enabled(_enabled) {}

			std::vector<Content> m_contents;

			optional<int> width = unspecified;

			bool enabled = true;
		};


		struct RadioButton
		{
			struct Content
			{
				Content(String _label, bool _enabled = true)
				: label(_label),
				  enabled(_enabled){}

				String label = L"label";

				bool enabled = true;
			};

			RadioButton(
				const std::vector<String>& text,
				optional<int> _checkedItem = none,
				optional<int> _width = unspecified,
				bool _enabled = true
				)
				: checkedItem(_checkedItem),
				  width(_width),
				  enabled(_enabled)
			{
				for (auto const& t : text)
				{
					m_contents.emplace_back(t, true);
				}
			}

			RadioButton(
				const std::vector<Content>& contents,
				optional<int> _checkedItem = none,
				optional<int> _width = unspecified,
				bool _enabled = true
				)
				: m_contents(contents),
				  checkedItem(_checkedItem),
				  width(_width),
				  enabled(_enabled) {}

			std::vector<Content> m_contents;

			optional<int> checkedItem;

			optional<int> width = unspecified;

			bool enabled = true;
		};
	}
}
