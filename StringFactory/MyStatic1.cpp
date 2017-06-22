// MyStatic1.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "MyStatic1.h"
#include "utility.h"

// CMyStatic1

IMPLEMENT_DYNAMIC(CMyStatic1, CStatic)

CMyStatic1::CMyStatic1()
{
}

CMyStatic1::~CMyStatic1()
{
}


BEGIN_MESSAGE_MAP(CMyStatic1, CStatic)
	//ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyStatic1 message handlers




void CMyStatic1::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	m_imgList.Create(32, 32, ILC_COLOR24, 3, 1);  //用这种方法指定颜色位数！
	CBitmap bmp;
	bmp.LoadBitmap(IDB_printState);
	m_imgList.Add(&bmp, RGB(0, 0, 0));

	DWORD dwStyle = GetStyle();
	SetWindowLong(GetSafeHwnd(), GWL_STYLE, dwStyle | SS_OWNERDRAW);
	//ModifyStyle(0, SS_BITMAP | SS_OWNERDRAW);

	CStatic::PreSubclassWindow();
}

void CMyStatic1::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	CDC *pdc = CDC::FromHandle(lpDIS->hDC);
	CRect rcWnd = lpDIS->rcItem;
	CDC memdc;
	memdc.CreateCompatibleDC(pdc);
	CBitmap bmpBg;
	bmpBg.CreateCompatibleBitmap(pdc, rcWnd.Width(), rcWnd.Height());
	memdc.SelectObject(&bmpBg);
	memdc.BitBlt(0, 0, rcWnd.Width(), rcWnd.Height(), pdc, 0, 0, SRCCOPY);
	memdc.SetBkMode(TRANSPARENT);
	CFont* pFont = GetParent()->GetFont();
	memdc.SelectObject(pFont);

	CBitmap bmp;
	GetListImage(m_imgList, bmp, m_status);
	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo);
	//bmp.LoadBitmap(IDB_right_arrow);

	//绘图区域
	CRect rcDraw = rcWnd;
	rcDraw.left = 0/*(rcWnd.Width() - bmpInfo.bmWidth) / 2*/;
	rcDraw.top = 0/*(rcWnd.Height() - bmpInfo.bmHeight) / 2*/;
	UINT nFlags = DSS_NORMAL | DST_BITMAP;
	memdc.DrawState(CPoint(rcDraw.left, rcDraw.top),
		CSize(32, 32), &bmp, nFlags);
	
	CString strText,str;
	strText.LoadString(IDS_OutputStatus);
	AfxExtractSubString(str, strText, m_status);
	rcDraw.left += 35;
	UINT align = /*DT_CENTER | */DT_VCENTER | DT_SINGLELINE;
	memdc.DrawText(str, &rcDraw, align);

	pdc->BitBlt(0, 0, rcWnd.Width(), rcWnd.Height(), &memdc, 0, 0, SRCCOPY);

	//bmp.DeleteObject();
	ReleaseDC(pdc);
}