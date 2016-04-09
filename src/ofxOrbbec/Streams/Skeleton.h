#pragma once

#include "Base.h"
#include "Points.h"
#include "../Converters.h"

#include <skeleton/skeleton.hpp>

namespace ofxOrbbec {
	namespace Streams {
		namespace os = orbbec::skeleton;

		class Skeleton : public Base {
		public:
			Skeleton();

			StreamType getType() const override;
			void init(astra::stream_reader & streamReader) override;
			void update() override;

			shared_ptr<os::body_tracker> getBodyTracker();

			//Warning : these functions are not safe to call until you've called init...
			void enableUpscaling(bool);
			bool getUpscalingEnabled() const;
			ofPixels getUserMask(bool copy = false) const;
			ofPixels getLabelsImage(bool copy = false) const;
			
		protected:
			void newFrameArrived(astra::frame &) override;

			mutex pointFrameLock;

			os::bitmap_vector3f pointFrame;
			bool pointFrameNew = true;
			shared_ptr<os::body_tracker> bodyTracker;
		};
	}
}