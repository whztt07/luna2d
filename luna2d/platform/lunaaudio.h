//-----------------------------------------------------------------------------
// luna2d engine
// Copyright 2014-2015 Stepan Prokofjev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#pragma once

#include "lunaengine.h"
#include "lunaaudiosource.h"

namespace luna2d{

//------------------------------
// Helper audio player interface
//------------------------------
class LUNAAudioPlayer
{
public:
	virtual ~LUNAAudioPlayer() {}

protected:
	size_t bufferId = 0;

public:
	virtual size_t GetBufferId();

	virtual bool IsUsing() = 0;

	virtual void SetSource(const std::shared_ptr<LUNAAudioSource>& source) = 0;

	virtual void SetLoop(bool loop) = 0;

	virtual void Play() = 0;

	virtual void Pause() = 0;

	virtual void Stop() = 0;

	virtual void SetVolume(float volume) = 0;

	virtual void SetMute(bool mute) = 0;
};


//----------------
// Audio interface
//----------------
class LUNAAudio
{
public:
	virtual ~LUNAAudio() {}

protected:
	std::vector<std::shared_ptr<LUNAAudioPlayer>> players;

protected:
	std::shared_ptr<LUNAAudioPlayer> FindFreePlayer(const std::shared_ptr<LUNAAudioSource>& source);

public:
	// Create audio buffer from given audio data
	// In case of success return id of created buffer, else return 0
	virtual size_t CreateBuffer(const std::vector<unsigned char>& data) = 0;

	// Release buffer with given id
	// All plyers using same buffer should be stopped
	virtual void ReleaseBuffer(size_t bufferId) = 0;

	// Play sound from given source
	void PlaySound(const std::weak_ptr<LUNAAudioSource>& source);
};

}
