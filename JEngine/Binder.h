#pragma once
#include "GraphicsResource.h"

class Drawable;
class TechniqueProbe;
class Graphics;

class Binder :public GraphicsResource
{
public:
	virtual void Bind(Graphics& gfx) noxnd = 0;
	virtual ~Binder() = default;
	virtual void InitializeParentReference(const Drawable&) noexcept
	{}
	virtual void Accept(TechniqueProbe&)
	{}
	virtual std::string GetUID() const noexcept
	{
		assert(false);
		return "";
	}
};


class CloningBinder : public Binder
{
public:
	virtual std::unique_ptr<CloningBinder> Clone() const noexcept = 0;
};