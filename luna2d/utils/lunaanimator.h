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

#include "lunalua.h"
#include "lunavector2.h"

namespace luna2d{

class LUNAAction
{
protected:
	LUNAAction(float time);

protected:
	float time;
	float totalTime;

public:
	bool IsDone();
	void Update(float deltaTime);
	virtual void OnUpdate() = 0;
};


class LUNASequence
{
private:
	std::vector<std::shared_ptr<LUNAAction>> actions;
	size_t curAction = 0;

public:
	void AddAction(const std::shared_ptr<LUNAAction>& action);
	/*void Start();
	void Pause();
	void Stop();*/
	void Update(float deltaTime);
};


class LUNAAnimator
{
	LUNA_USERDATA(LUNAAnimator)

public:
	LUNAAnimator(const LuaTable& params);

private:
	std::vector<std::shared_ptr<LUNASequence>> sequences;

public:
	/*void Start();
	void Pause();
	void Stop();*/
	void Update(float deltaTime);
};

}
