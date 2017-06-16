// InputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "InputDlg.h"
#include "afxdialogex.h"

#define IDC_btn_InputSample   100
#define IDC_btn_FmtSample	  101
#define IDC_edt_Tip			  102

// CInputDlg dialog

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Input, pParent)
{

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
	
	extern CSize g_whDlg;//�������ߣ���tab�ͻ������
	MoveWindow(CRect(CPoint(0, 0), g_whDlg));
	//GET_DLG_WH;

	//����
	const int DIVIDE = 10;
	int xUnit = g_whDlg.cx / DIVIDE;
	int yUnit = g_whDlg.cy / DIVIDE;
	int l, t, w, h;//���� �� ���
	int r, b;//����
	//�����
	l = xUnit; t = yUnit; w = xUnit * 7; h = yUnit * 3;
	CRect rc(CPoint(l, t), CSize(w, h));
	r = rc.right; b = rc.bottom;
	CMyEdit1* pEdit = (CMyEdit1*)GetDlgItem(IDC_edt_Input);
	pEdit->MoveWindow(&rc, FALSE);

	//��ʾ��ť
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
		//�༭��
		str.LoadString(IDS_InputEditTip);
		m_tip.AddTool(pEdit, str);
		//������ʾ
		str.LoadString(IDS_InputSample);
		m_tip.AddTool(pBtn, str);
		m_tip.SetMaxTipWidth(300);
		//��ʽ������ʾ
		str.LoadString(IDS_FmtSymbolSample);
		m_tip.AddTool(GetDlgItem(IDC_btn_FmtSample), str);	
	}
	

	return TRUE;
}


BOOL CInputDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	m_tip.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}

//�����ʾ��
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