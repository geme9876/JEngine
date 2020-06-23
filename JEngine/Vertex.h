#pragma once
#include <vector>
#include <type_traits>
#include "pch.h"
#include "Graphics.h"

class VertexLayout
{
public:
	enum ElementType
	{
		Position2D,
		Position3D,
		Texture2D,
		Normal,
		Float3Color,
		Float4Color,
		BGRAColor,
		Count,
	};
	class VertexElement
	{
	public:
		VertexElement(ElementType type, size_t offset);
		size_t GetOffsetAfter() const noxnd;
		size_t GetOffset() const;
		size_t Size() const noxnd;
		static constexpr size_t SizeOf(ElementType type) noxnd;
		ElementType GetType() const noexcept;
		D3D11_INPUT_ELEMENT_DESC GetDesc() const noxnd;
	private:
		ElementType type;
		size_t offset;
	};


private:
	std::vector<VertexElement> elements;
};

class Vertex
{
	

};

