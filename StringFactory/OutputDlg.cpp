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
	m_imgList.Create(32, 32, ILC_COLOR24, 3, 1);  //用这种方法指定颜色位数！
	CBitmap bmp;
	bmp.LoadBitmap(IDB_printState);
	m_imgList.Add(&bmp, RGB(0, 0, 0));

	//IMAGEINFO imginfo;
	//m_imgList.GetImageInfo(0, &imginfo);
	//m_bm = imginfo.hbmImage;
	//m_bmp.Attach(imginfo.hbmImage);
	//CBitmap bm;
	//m_bmp.LoadBitmap(IDB_right_arrow);

	m_stsOK.ModifyStyle(0, SS_BITMAP);
	m_stsOK.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_right_arrow)));
	//m_stsOK.SetWindowPos(0, 0, 0, 32, 32, SWP_NOMOVE | SWP_NOZORDER);
	//m_stsOK.Invalidate();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

