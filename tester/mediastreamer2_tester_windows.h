﻿#pragma once

#include "mediastreamer2/mscommon.h"
#include "mediastreamer2_tester.h"

namespace BelledonneCommunications
{
	namespace Mediastreamer2
	{
		namespace Tester
		{
			public interface class OutputTraceListener
			{
			public:
				void outputTrace(Platform::String^ lev, Platform::String^ msg);
			};

			public ref class NativeTester sealed
			{
			public:
				void setOutputTraceListener(OutputTraceListener^ traceListener);
				unsigned int nbTestSuites();
				unsigned int nbTests(Platform::String^ suiteName);
				Platform::String^ testSuiteName(int index);
				Platform::String^ testName(Platform::String^ suiteName, int testIndex);
				void initialize(Windows::Storage::StorageFolder^ writableDirectory, Platform::Boolean ui);
				bool run(Platform::String^ suiteName, Platform::String^ caseName, Platform::Boolean verbose);
				void runAllToXml();
				void initVideo();
				void uninitVideo();
				void startVideoStream(Platform::Object^ CaptureElement, Platform::Object^ MediaElement, Platform::String^ camera, Platform::String^ codec, Platform::String^ videoSize, unsigned int frameRate, unsigned int bitRate);
				void stopVideoStream();
				int getOrientation() { return _deviceRotation; }
				void setOrientation(int degrees);
				void changeCamera(Platform::String^ camera);

				static property NativeTester^ Instance
				{
					NativeTester^ get() { return _instance; }
				}
				property Windows::Foundation::IAsyncAction^ AsyncAction
				{
					Windows::Foundation::IAsyncAction^ get() { return _asyncAction; }
				}
				property Windows::Foundation::Collections::IVector<Platform::String^>^ VideoDevices
				{
					Windows::Foundation::Collections::IVector<Platform::String^>^ get();
				}
			private:
				NativeTester();
				~NativeTester();

				static NativeTester^ _instance;
				Windows::Foundation::IAsyncAction^ _asyncAction;
				VideoStream *_videoStream;
				int _deviceRotation;
			};
		}
	}
}
