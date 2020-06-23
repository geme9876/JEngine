#include "pch.h"
#include "Vertex.h"

VertexLayout::VertexElement::VertexElement(ElementType type, size_t offset) :type(type), offset(offset)
{
}

size_t VertexLayout::VertexElement::GetOffset() const
{
	return offset;
}

VertexLayout::ElementType VertexLayout::VertexElement::GetType() const noexcept
{
	return type;
}
size_t VertexLayout::VertexElement::GetOffsetAfter() const noxnd
{
	return offset + Size();
};

size_t VertexLayout::VertexElement::Size() const noxnd
{
	return SizeOf(type);
};
constexpr size_t VertexLayout::VertexElement::SizeOf(ElementType type) noxnd
{

};

D3D11_INPUT_ELEMENT_DESC VertexLayout::VertexElement::GetDesc() const noxnd
{
};