
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once

///	コピーガード
class Noncopyable
{
	Noncopyable() = default;
	Noncopyable(const Noncopyable&) = delete;
	Noncopyable& operator=(const Noncopyable&) = delete;
};