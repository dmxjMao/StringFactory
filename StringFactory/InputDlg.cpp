// InputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "InputDlg.h"
#include "afxdialogex.h"

using std::vector;

#define IDC_btn_InputSample   100
#define IDC_btn_FmtSample	  101
#define IDC_edt_Tip			  102
#define IDC_tbInt 103

//工具条按钮ID
UINT g_intBtns[] = { IDM_intRange , IDM_intRegular, IDM_intFix };
//UINT g_floatBtns[] = { IDM_intRange , IDM_intRegular, IDM_intFix };
//vector<UINT*> = { g_intBtns };
//工具条按钮个数
vector<int> g_btnNumVec = { sizeof(g_intBtns) / sizeof(g_intBtns[0]) };

// CInputDlg dialog

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Input, pParent)
{
	m_tbmuVec.resize(TB_NUM);
	for (int i = 0; i < TB_NUM; ++i) {
		m_tbmuVec[i].resize(g_btnNumVec[i]);
		auto& v = m_tbmuVec[i];
		for (int k = 0; k < (int)v.size(); ++k) {
			v[k] = std::make_shared<CMenu>();
		}
	}
}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_edt_Input, m_edtInput);
	//DDX_Control(pDX, IDC_btn_InputSample, m_btnInputSample);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_BN_CLICKED(IDC_btn_InputSample, &CInputDlg::OnBtnClickInputSample)
	
END_MESSAGE_MAP()


// CInputDlg message handlers

BOOL CInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	extern CSize g_whDlg;//主界面宽高，即tab客户区宽高
	MoveWindow(CRect(CPoint(0, 0), g_whDlg));
	//GET_DLG_WH;

	//布局
	const int DIVIDE = 20;
	int xUnit = g_whDlg.cx / DIVIDE;
	int yUnit = g_whDlg.cy / DIVIDE;
	int l, t, w, h;//左上 和 宽高
	int r, b;//右下
	//输入框
	l = xUnit; t = yUnit; w = xUnit * 17; h = yUnit * 3;
	CRect rc(CPoint(l, t), CSize(w, h));
	r = rc.right; b = rc.bottom;
	CMyEdit1* pEdit = (CMyEdit1*)GetDlgItem(IDC_edt_Input);
	pEdit->MoveWindow(&rc, FALSE);

	//提示按钮
	l = r;
	//rc.SetRectEmpty();
	m_btnInputSample.Create(0, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rc, this, IDC_btn_InputSample);
	m_btnInputSample.LoadBitmaps(IDB_right_arrow);
	m_btnInputSample.SizeToContent();
	m_btnInputSample.ShowWindow(SW_NORMAL);
	m_btnInputSample.SetWindowPos(0, l, t, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
	CBitmapButton* pBtn = (CBitmapButton*)GetDlgItem(IDC_btn_InputSample);
	pBtn->GetClientRect(&rc);
	t += rc.Height() + yUnit;
	m_btnFmtSample.Create(0, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rc, this, IDC_btn_FmtSample);
	m_btnFmtSample.LoadBitmaps(IDB_right_arrow);
	m_btnFmtSample.SizeToContent();
	m_btnFmtSample.ShowWindow(SW_NORMAL);
	m_btnFmtSample.SetWindowPos(0, l, t, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
	//tooltip
	if (m_tip.Create(this, TTS_ALWAYSTIP)) {
		m_tip.SetDelayTime(TTDT_AUTOPOP, 10000);
		m_tip.SetDelayTime(TTDT_INITIAL, 100);
		m_tip.SetDelayTime(TTDT_RESHOW, 100);
		CString str;
		//编辑框
		str.LoadString(IDS_InputEditTip);
		m_tip.AddTool(pEdit, str);
		//输入提示
		str.LoadString(IDS_InputSample);
		m_tip.AddTool(pBtn, str);
		m_tip.SetMaxTipWidth(300);
		//格式控制提示
		str.LoadString(IDS_FmtSymbolSample);
		m_tip.AddTool(GetDlgItem(IDC_btn_FmtSample), str);	
	}
	
	//预加载工具条
	CMFCToolBar& tb = m_tb[TB_INT];
	if (tb.Create(this, WS_CHILD | WS_VISIBLE | TBSTYLE_TOOLTIPS | TBSTYLE_TRANSPARENT, IDC_tbInt)) {
		int btnNum = g_btnNumVec[TB_INT];
		tb.SetButtons(g_intBtns, btnNum);
		tb.CleanUpLockedImages();
		tb.LoadBitmap(IDB_tbInt_16px);
		tb.SetPaneStyle(tb.GetPaneStyle() &~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_ANY));
		int i = 0;
		for (; i < btnNum; ++i) {
			auto& spMenu = m_tbmuVec[TB_INT][i];
			spMenu->CreatePopupMenu();
			CMFCToolBarMenuButton tbmu(g_intBtns[i], spMenu->GetSafeHmenu(), -1);
			tb.ReplaceButton(g_intBtns[i], tbmu);
		}
	}
	//GetDlgItem(IDC_edt_Input)->GetWindowRect(&rc);
	//ScreenToClient(&rc);
	//l = rc.left; t = rc.bottom + yUnit;
	//CSize sz = tb.CalcFixedLayout(FALSE, TRUE);
	//tb.SetWindowPos(0, l, t, sz.cx, sz.cy, SWP_NOACTIVATE | SWP_NOZORDER);

	return TRUE;
}


BOOL CInputDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	m_tip.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}

//点击提示框
void CInputDlg::OnBtnClickInputSample()
{
	/*if (!m_edtTip.GetSafeHwnd()) {
		BOOL bRet = m_edtTip.Create(
			ES_READONLY | WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_WANTRETURN,
			CRect(0, 0, 0, 0), this, IDC_edt_Tip);
		if (!bRet) return;	
		
	}

	CString str;
	str.LoadString(IDS_InputSample);
	m_edtTip.SetWindowText(str);

	CPoint pt(GetMessagePos());
	ScreenToClient(&pt);
	m_edtTip.SetWindowPos(0, pt.x, pt.y, 100, 100, SWP_NOZORDER);
	m_edtTip.ShowWindow(SW_SHOW);*/

}