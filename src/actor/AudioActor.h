#ifndef AE_AUDIOACTOR_H
#define AE_AUDIOACTOR_H

#include "../System.h"
#include "../audio/AudioStream.h"
#include "Actor.h"

#include <mutex>

namespace Atlas {

	namespace Actor {

		class AudioActor : public Actor, public Audio::AudioStream {

		public:
			AudioActor(Audio::AudioData* data);

			std::vector<int16_t> GetChunk(int32_t length) override;

			void Update(Camera camera, float deltaTime, 
				mat4 parentTransform, bool parentUpdate) override;

			float cutoff = 0.001f;

		private:
			float leftChannelVolume = 1.0f;
			float rightChannelVolume = 1.0f;

			float velocity = 0.0f;

			bool audible = true;

			std::mutex mutex;

		};

	}

}

#endif