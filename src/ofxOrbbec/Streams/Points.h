#pragma once

#include "Base.h"

namespace ofxOrbbec {
	namespace Streams {
		class Points : public TemplateBaseImage<astra::pointstream, astra::pointframe, float> {
		public:
			StreamType getType() const override {
				return StreamType::PointStreamType;
			}

			void update() override;
			const ofMesh & getMesh();
		protected:
			int getNumChannels() override {
				return 3;
			}

			ofMesh mesh;
		};
	}
}