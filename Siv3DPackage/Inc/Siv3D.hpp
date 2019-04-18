//-------------------------------------------------------------------------------
//
//    Copyright (C) 2008-2014 Reputeless, Waseda Computer Entertainment.
//
//    Permission is hereby granted, free of charge, to any person
//    obtaining a copy of this software and associated documentation
//    files (the "Software"), to deal in the Software without restriction,
//    including without limitation the rights to use, copy, modify, merge,
//    publish, distribute, sublicense, and/or sell copies of the Software,
//    and to permit persons to whom the Software is furnished to do so,
//    subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be
//    included in all copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
//    ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
//    TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
//    PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
//    SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
//    ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
//    ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
//    OR OTHER DEALINGS IN THE SOFTWARE.
//
//--------------------------------------------------------------------------------

# pragma once
# pragma comment (linker, "/entry:\"wWinMainCRTStartup\"")

# if(_MSC_VER<1800)
#  error Siv3D ‚Í Visual Studio 2013 ‚Ì‚Ý‘Î‰ž‚µ‚Ä‚¢‚Ü‚·
# endif

# ifdef _DEBUG
#  pragma comment (lib, "Siv3D_d")
# else
#  pragma comment (lib, "Siv3D")
# endif

# include "Siv3DVersion.hpp"
# include "SivForward.hpp"
# include "SivUtility.hpp"
# include "SivOptional.hpp"
# include "SivChar.hpp"
# include "SivString.hpp"
# include "SivCharacterSet.hpp"
# include "SivInteger.hpp"
# include "SivFloat.hpp"
# include "SivFormat.hpp"
# include "SivParse.hpp"
# include "SivDuration.hpp"
# include "SivCalendar.hpp"
# include "SivDate.hpp"
# include "SivTime.hpp"
# include "SivTimer.hpp"
# include "SivEventTimer.hpp"
# include "SivFileSystem.hpp"
# include "SivBinaryWriter.hpp"
# include "SivBinaryReader.hpp"
# include "SivBlob.hpp"
# include "SivTextWriter.hpp"
# include "SivTextReader.hpp"
# include "SivBase64.hpp"
# include "SivMessageDigest.hpp"
//# include "SivZip.hpp"
//# include "SivFileArchive.hpp"
# include "SivRegex.hpp"
# include "SivLogger.hpp"
# include "SivCSVReader.hpp"
# include "SivINIReader.hpp"
# include "SivXMLReader.hpp"
//# include "SivJSONReader.hpp"
# include "SivSerial.hpp"
# include "SivMathConstants.hpp"
# include "SivPointVector.hpp"
# include "SivCircular.hpp"
# include "SivLine.hpp"
# include "SivRectangle.hpp"
# include "SivCircle.hpp"
# include "SivEllipse.hpp"
# include "SivTriangle.hpp"
# include "SivQuad.hpp"
# include "SivLineString.hpp"
# include "SivPolygon.hpp"
# include "SivGeometry.hpp"
# include "SivRoundRect.hpp"
# include "SivMath.hpp"
# include "SivRandom.hpp"
# include "SivRandomPointVector.hpp"
# include "SivNoise.hpp"
# include "SivSpline.hpp"
# include "SivColor.hpp"
# include "SivHSV.hpp"
# include "SivImage.hpp"
# include "SivWaveSample.hpp"
# include "SivWave.hpp"
# include "SivFFT.hpp"
# include "SivVideoWriter.hpp"
# include "SivInternet.hpp"
# include "SivTwitter.hpp"
# include "SivMidi.hpp"
//# include "SivScript.hpp"
# include "SivWindow.hpp"
# include "SivMessageBox.hpp"
# include "SivSystem.hpp"
# include "SivClipboard.hpp"
# include "SivDragdrop.hpp"
# include "SivDialog.hpp"
# include "SivProfiler.hpp"
# include "SivProfilerUtility.hpp"
# include "SivRecorder.hpp"
# include "SivInput.hpp"
# include "SivCombinedKey.hpp"
# include "SivPentablet.hpp"
# include "SivGamePad.hpp"
# include "SivWebcam.hpp"
# include "SivARMarker.hpp"
# include "SivKinect.hpp"
# include "SivSound.hpp"
# include "SivGraphics.hpp"
# include "SivGraphics2D.hpp"
# include "SivTexture.hpp"
# include "SivSprite.hpp"
# include "SivFont.hpp"
# include "SivGUIWidget.hpp"
# include "SivGUI.hpp"
# include "SivQuaternion.hpp"
# include "SivAlignedAllocator.hpp"
# include "SivMatrix.hpp"
# include "SivMesh.hpp"
# include "SivPlane.hpp"
# include "SivSphere.hpp"
# include "SivBox.hpp"
# include "SivDisc.hpp"
# include "SivCylinder.hpp"
# include "SivCone.hpp"
# include "SivRay.hpp"
# include "SivGeometry3D.hpp"
# include "SivModel.hpp"
# include "SivGraphics3D.hpp"
# include "SivRenderer.hpp"
# include "SivAsset.hpp"
# include "SivAddon.hpp"
# include "SivApplicationUtility.hpp"
# include "Siv3DDeprecated.hpp"

# ifndef NO_S3D_USING
	using namespace s3d;
# endif

#ifndef NO_MATH_USING
	using namespace s3d::Math;
#endif
