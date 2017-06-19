
// StringFactoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "StringFactoryDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define IDC_tab		100

CSize g_whDlg;//主界面宽高
//CSize g_whTab;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStringFactoryDlg dialog



CStringFactoryDlg::CStringFactoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STRINGFACTORY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(/*IDR_MAINFRAME*/IDI_AppIcon);
}

void CStringFactoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStringFactoryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CStringFactoryDlg message handlers

BOOL CStringFactoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//主界面宽高
	CRect rc;
	GetClientRect(&rc);
	g_whDlg.cx = rc.Width(); g_whDlg.cy = rc.Height();
	
	//程序标题
	CString str;
	str.LoadString(IDS_AppTitle);
	SetWindowText(str);
	
	//创建outlook 风格的 tab ctrl
	//输入模板
	m_tab.Create(CRect(0, 0, g_whDlg.cx, g_whDlg.cy), this, IDC_tab);
	m_inputDlg.Create(IDD_Input, this);
	m_inputDlg.SetOwner(&m_tab);
	CString strFull;
	int nTab = 0;
	strFull.LoadString(IDS_TabTitle);
 	AfxExtractSubString(str, strFull, nTab++);
	m_tab.AddTab(&m_inputDlg, str);
	////格式控制  和输入模板合并
	//m_fmtControlDlg.Create(IDD_Fmt, this);
	//m_fmtControlDlg.SetOwner(&m_tab);
	//AfxExtractSubString(str, strFull, nTab++);
	//m_tab.AddTab(&m_fmtControlDlg, str);
	//输出控制
	m_outputDlg.Create(IDD_Output, this);
	m_outputDlg.SetOwner(&m_tab);
	AfxExtractSubString(str, strFull, nTab++);
	m_tab.AddTab(&m_outputDlg, str);
	//绑定信息
	m_bindInfoDlg.Create(IDD_BindInfo, this);
	m_bindInfoDlg.SetOwner(&m_tab);
	AfxExtractSubString(str, strFull, nTab++);
	m_tab.AddTab(&m_bindInfoDlg, str);

	//
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStringFactoryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStringFactoryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStringFactoryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

