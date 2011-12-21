#include "s3e.h"
#include "Iw2D.h"
#include "transitions2d.h"

CIw2DImage* image1;
CIw2DImage* image2;

void DrawOnRed()
{
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	Iw2DSurfaceClear(0xFF0000FF);
	Iw2DDrawImage(image1, CIwSVec2(w / 2 - image1->GetWidth() / 2, h / 2 - image1->GetHeight() / 2));
}

void DrawOnBlue()
{
	int w = Iw2DGetSurfaceWidth();
	int h = Iw2DGetSurfaceHeight();
	Iw2DSurfaceClear(0xFFFF0000);
	Iw2DDrawImage(image2, CIwSVec2(w / 2 - image2->GetWidth() / 2, h / 2 - image2->GetHeight() / 2));
}

int main()
{
	Iw2DInit();

	image1 = Iw2DCreateImage("image1.png");
	image2 = Iw2DCreateImage("image2.png");

	while (!s3eDeviceCheckQuitRequest())
	{
		// Transition #1
		// Fade in from black
		Iw2DSurfaceClear(0xff000000);
		Transitions2D::CaptureStartScreen();
		DrawOnRed();
		Transitions2D::CaptureEndScreen();
		Transitions2D::Fade();

		s3eDeviceYield(1000);
		if (s3eDeviceCheckQuitRequest()) break;
		
		// Transition #2
		// Cross fade from red image to blue image
		DrawOnRed();
		Transitions2D::CaptureStartScreen();
		DrawOnBlue();
		Transitions2D::CaptureEndScreen();
		Transitions2D::Fade();
		
		s3eDeviceYield(1000);
		if (s3eDeviceCheckQuitRequest()) break;
		
		// Transition #3
		// Slide left
		DrawOnBlue();
		Transitions2D::CaptureStartScreen();
		DrawOnRed();
		Transitions2D::CaptureEndScreen();
		Transitions2D::SlideLeft();

		s3eDeviceYield(1000);
		if (s3eDeviceCheckQuitRequest()) break;
		
		// Transition #4
		// Slide right
		DrawOnRed();
		Transitions2D::CaptureStartScreen();
		DrawOnBlue();
		Transitions2D::CaptureEndScreen();
		Transitions2D::SlideRight();

		s3eDeviceYield(1000);
		if (s3eDeviceCheckQuitRequest()) break;

		// Transition #5
		// Slide up
		DrawOnBlue();
		Transitions2D::CaptureStartScreen();
		DrawOnRed();
		Transitions2D::CaptureEndScreen();
		Transitions2D::SlideUp();

		s3eDeviceYield(1000);
		if (s3eDeviceCheckQuitRequest()) break;

		// Transition #6
		// Slide down
		DrawOnRed();
		Transitions2D::CaptureStartScreen();
		DrawOnBlue();
		Transitions2D::CaptureEndScreen();
		Transitions2D::SlideDown();
		
		s3eDeviceYield(1000);
		if (s3eDeviceCheckQuitRequest()) break;

		// Transition #7
		// Fade out to black
		DrawOnBlue();
		Transitions2D::CaptureStartScreen();
		Iw2DSurfaceClear(0xff000000);
		Transitions2D::CaptureEndScreen();
		Transitions2D::Fade();

		s3eDeviceYield(1000);
	}

	delete image1;
	delete image2;

	Iw2DTerminate();
}
