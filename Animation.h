#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <vector>
#include "SDL.h"

using namespace std;

class Animation
{
public:
	float speed;
	vector<SDL_Rect> frames;

private:
	float current_frame;

public:
	Animation() : frames(), speed(1.0f), current_frame(0.0f)
	{}

	SDL_Rect& GetCurrentFrame()
	{
		current_frame += speed;
		if(current_frame >= frames.size())
			current_frame = 0.0f;
		return frames[(int)current_frame];
	}

	SDL_Rect& GetPreviousFrame()
	{
		current_frame -= speed;
		if (current_frame <= 0)
			current_frame = 0.0f;
		return frames[(int)current_frame];
	}

	inline void SetFrame(int frame_number)
	{
		if (frame_number >= frames.size())
		{
			current_frame = frames.size();
		}
		else
		{
			current_frame = frame_number;
		}
	}

	inline int GetCurrentFrameNumber()
	{
		return (int)current_frame;
	}

	inline bool IsLastFrame()
	{
		if (current_frame >= frames.size() - 1)
			return true;
		return false;
	}

	inline void ResetAnimation() 
	{
		current_frame = 0.0f;
	}

	inline int GetNumberOfFrames() 
	{
		return frames.size();
	}
};

#endif //__ANIMATION_H__