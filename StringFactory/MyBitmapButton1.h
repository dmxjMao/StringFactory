#pragma once


// CMyButton

class CMyBitmapButton1 : public CBitmapButton
{
	DECLARE_DYNAMIC(CMyBitmapButton1)
	DECLARE_MESSAGE_MAP()
public:
	CMyBitmapButton1();
	virtual ~CMyBitmapButton1();

protected:
	//CToolTipCtrl m_tip;

public:
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void PreSubclassWindow();
};


