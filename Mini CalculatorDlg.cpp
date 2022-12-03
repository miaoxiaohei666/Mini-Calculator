
// Mini CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Mini Calculator.h"
#include "Mini CalculatorDlg.h"
#include "afxdialogex.h"
#include "calculator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

CFont cfont;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
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


// CMiniCalculatorDlg 对话框



CMiniCalculatorDlg::CMiniCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MINI_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMiniCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMiniCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMiniCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMiniCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMiniCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMiniCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMiniCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMiniCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON11, &CMiniCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON7, &CMiniCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMiniCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMiniCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON15, &CMiniCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON14, &CMiniCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON13, &CMiniCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON16, &CMiniCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMiniCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON19, &CMiniCalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CMiniCalculatorDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON18, &CMiniCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON10, &CMiniCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &CMiniCalculatorDlg::OnBnClickedButton12)
END_MESSAGE_MAP()


// CMiniCalculatorDlg 消息处理程序

BOOL CMiniCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	cfont.CreatePointFont(200, _T("黑体"), NULL);
	GetDlgItem(IDC_STATIC)->SetFont(&cfont);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMiniCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMiniCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMiniCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMiniCalculatorDlg::OnBnClickedButton1()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("7"));
}

void CMiniCalculatorDlg::OnBnClickedButton2()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("8"));
}

void CMiniCalculatorDlg::OnBnClickedButton3()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("9"));
}

void CMiniCalculatorDlg::OnBnClickedButton4()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("4"));
}

void CMiniCalculatorDlg::OnBnClickedButton5()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("5"));
}

void CMiniCalculatorDlg::OnBnClickedButton6()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("6"));
}

void CMiniCalculatorDlg::OnBnClickedButton7()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("1"));
}

void CMiniCalculatorDlg::OnBnClickedButton8()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("2"));
}

void CMiniCalculatorDlg::OnBnClickedButton9()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("3"));
}

void CMiniCalculatorDlg::OnBnClickedButton11()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("-"));
}

void CMiniCalculatorDlg::OnBnClickedButton15()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("0"));
}

void CMiniCalculatorDlg::OnBnClickedButton14()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("."));
}

void CMiniCalculatorDlg::OnBnClickedButton13()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("/"));
}

void CMiniCalculatorDlg::OnBnClickedButton19()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("("));
}

void CMiniCalculatorDlg::OnBnClickedButton20()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T(")"));
}

void CMiniCalculatorDlg::OnBnClickedButton10()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("+"));
}

void CMiniCalculatorDlg::OnBnClickedButton12()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	SetDlgItemText(IDC_STATIC, input + _T("*"));
}

void CMiniCalculatorDlg::OnBnClickedButton18()
{
	CString cs;
	double b;
	int a, SIGN = 1;
	GetDlgItemText(IDC_STATIC, cs);
	std::string s = CStringA(cs);
	a = cs.GetLength();
	b = result(s, a, SIGN);
	if (SIGN == 1) {
		int c = b;
		double d;
		d = b - c;
		if (d == 0.0) cs.Format(_T("%d"), c);
		else cs.Format(_T("%0.3f"), b);
		SetDlgItemText(IDC_STATIC, cs);
	}
	if (SIGN == 0)
		SetDlgItemText(IDC_STATIC, _T("Error!."));
}

void CMiniCalculatorDlg::OnBnClickedButton16()
{
	CString input;
	GetDlgItemText(IDC_STATIC, input);
	input.Delete(input.GetLength() - 1);
	SetDlgItemText(IDC_STATIC, input);
}


void CMiniCalculatorDlg::OnBnClickedButton17()
{
	SetDlgItemText(IDC_STATIC, NULL);
}