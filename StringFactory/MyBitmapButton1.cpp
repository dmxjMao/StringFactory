// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "MyBitmapButton1.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyBitmapButton1, CBitmapButton)

CMyBitmapButton1::CMyBitmapButton1()
{

}

CMyBitmapButton1::~CMyBitmapButton1()
{
}


BEGIN_MESSAGE_MAP(CMyBitmapButton1, CBitmapButton)
	ON_WM_MOUSEHOVER()
END_MESSAGE_MAP()



// CMyButton message handlers


void CMyBitmapButton1::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	//if (m_tip.Create(this)) {
	//	m_tip.Activate(TRUE);
	//}	

	CBitmapButton::PreSubclassWindow();
}

BOOL CMyBitmapButton1::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	//if (m_tip.GetSafeHwnd()) {
	//	m_tip.RelayEvent(pMsg);
	//}

	return CBitmapButton::PreTranslateMessage(pMsg);
}


void CMyBitmapButton1::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//AfxMessageBox(_T("HELLO"));
	CBitmapButton::OnMouseHover(nFlags, point);
}