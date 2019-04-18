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

namespace s3d
{
	/**
	*	@brief Perlin Noise ¶¬
	*	@note ƒŠƒtƒ@ƒŒƒ“ƒXÀ‘• http://mrl.nyu.edu/~perlin/noise/
	*/
	class Noise
	{
	public:

		Noise(unsigned seed = 0);

		double noise(double x) const;

		double noise(double x, double y) const;

		double noise(double x, double y, double z) const;

		double octaveNoise(double x, int octaves) const;

		double octaveNoise(double x, double y, int octaves) const;

		double octaveNoise(double x, double y, double z, int octaves) const;

	private:

		double fade(double t) const;

		double lerp(double t, double a, double b) const;

		double grad(int hash, double x, double y, double z) const;

		int p[512];
	};
}
