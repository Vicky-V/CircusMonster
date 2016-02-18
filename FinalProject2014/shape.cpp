#include "Shape.h"

CShape::CShape(const LOGPEN & pen, const LOGBRUSH & brush, const CPrecisionPoint start, const CPrecisionPoint end)
	: m_PreviousPen(0), m_PreviousBrush(0), m_Pen (CreatePenIndirect(&pen)), m_Brush(CreateBrushIndirect(&brush)), m_Start(start), m_End(end)
{
	
}

CShape::~CShape()
{
	DeleteObject(m_Pen);
	DeleteObject(m_Brush);
}
