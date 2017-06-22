// OutputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "OutputDlg.h"
#include "afxdialogex.h"


// COutputDlg dialog

IMPLEMENT_DYNAMIC(COutputDlg, CDialogEx)

COutputDlg::COutputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Output, pParent)
{

}

COutputDlg::~COutputDlg()
{
}

void COutputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_cbo_Return, m_cboReturn);
	DDX_Control(pDX, IDC_sts_Ok, m_stsOK);
}


BEGIN_MESSAGE_MAP(COutputDlg, CDialogEx)

END_MESSAGE_MAP()


// COutputDlg message handlers


BOOL COutputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	//CRect rc;
	//rc.SetRectEmpty();
	//BOOL bRet = m_stsOK.Create(_T(" "), WS_CHILD | WS_VISIBLE | SS_OWNERDRAW, rc, this);

	//×´Ì¬ÎÄ±¾¿òÎ»ÖÃ
	CRect rc;
	GetDlgItem(IDC_btn_Generate)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	m_stsOK.SetWindowPos(0, rc.right + 50, rc.top, 32 + 100, 32, SWP_NOZORDER | SWP_NOACTIVATE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}



