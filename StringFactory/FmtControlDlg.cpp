// FmtControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "FmtControlDlg.h"
#include "afxdialogex.h"


#define ID_tbInt 100

// CFmtControlDlg dialog

IMPLEMENT_DYNAMIC(CFmtControlDlg, CDialogEx)

CFmtControlDlg::CFmtControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Fmt, pParent)
{

}

CFmtControlDlg::~CFmtControlDlg()
{
}

void CFmtControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFmtControlDlg, CDialogEx)
END_MESSAGE_MAP()


// CFmtControlDlg message handlers


BOOL CFmtControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CMFCToolBar& tb = m_tb[TB_INT];
	//if (tb.Create(this, WS_CHILD | WS_VISIBLE | TBSTYLE_TOOLTIPS | TBSTYLE_TRANSPARENT, ID_tbInt)) {
	//	UINT btns[] = { IDM_intRange , IDM_intRegular, IDM_intFix };
	//	tb.SetButtons(btns, sizeof(btns) / sizeof(btns[0]));
	//	tb.CleanUpLockedImages();
	//	tb.LoadBitmap(IDB_tbInt_16px);
	//	tb.SetPaneStyle(tb.GetPaneStyle() &~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_ANY));
	//	int i = 0;
	//	for (; i < TB_NUM; ++i) {
	//		m_tbmu[i].CreatePopupMenu();
	//		CMFCToolBarMenuButton tbmu(btns[i], m_tbmu[i].GetSafeHmenu(), -1);
	//		tb.ReplaceButton(btns[i], tbmu);
	//	}	
	//}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
