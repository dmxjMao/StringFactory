#pragma once
#include "define.h"

// CMyStatic1

class CMyStatic1 : public CStatic
{
	DECLARE_DYNAMIC(CMyStatic1)
	DECLARE_MESSAGE_MAP()
public:
	CMyStatic1();
	virtual ~CMyStatic1();

protected:
	CImageList m_imgList;
	OUTPUT_STATUS m_status = OUTPUT_NOTYET;

	virtual void PreSubclassWindow();
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	//afx_msg void OnPaint();
};


