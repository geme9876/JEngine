#pragma once
#include "GraphicsResource.h"
class Binder :public GraphicsResource
{
public:
	virtual void Bind(Graphics& gfx) noxnd = 0;
	virtual ~Binder() = default;


};

