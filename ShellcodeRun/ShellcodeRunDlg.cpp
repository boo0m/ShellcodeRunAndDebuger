
// ShellcodeRunDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ShellcodeRun.h"
#include "ShellcodeRunDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

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


// CShellcodeRunDlg 对话框



CShellcodeRunDlg::CShellcodeRunDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHELLCODERUN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShellcodeRunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PATH, m_editPath);
}

BEGIN_MESSAGE_MAP(CShellcodeRunDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_STATIC_PATH, &CShellcodeRunDlg::OnStnClickedStaticPath)
	ON_BN_CLICKED(IDC_BUTTON_PATH, &CShellcodeRunDlg::OnBnClickedButtonPath)
	ON_BN_CLICKED(IDC_BUTTON_DEBUG, &CShellcodeRunDlg::OnBnClickedButtonDebug)
	ON_BN_CLICKED(IDC_BUTTON_RUN, &CShellcodeRunDlg::OnBnClickedButtonRun)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CShellcodeRunDlg 消息处理程序

BOOL CShellcodeRunDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_SHOW);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CShellcodeRunDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShellcodeRunDlg::OnPaint()
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
HCURSOR CShellcodeRunDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShellcodeRunDlg::OnStnClickedStaticPath()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CShellcodeRunDlg::OnBnClickedButtonPath()
{
	// TODO: 在此添加控件通知处理程序代码

	CFileDialog dlg(TRUE, "*", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "(*.bin)|*.bin||");
	if (dlg.DoModal() == IDOK)
	{
		m_editPath.SetWindowText(dlg.GetPathName());
		UpdateData(FALSE);
	}


}


int ShellcodeRun(const char* Spath);
int ShellcodeDebuger(const char* Spath);

void CShellcodeRunDlg::OnBnClickedButtonDebug()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	CString shellcode_path;
	m_editPath.GetWindowText(shellcode_path);

	ShellcodeDebuger(shellcode_path);


}



void CShellcodeRunDlg::OnBnClickedButtonRun()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	CString shellcode_path;
	m_editPath.GetWindowText(shellcode_path);

	ShellcodeRun(shellcode_path);

}

int ShellcodeRun(const char* Spath) {

	HANDLE Sfile = INVALID_HANDLE_VALUE;
	//const char* Spath = (char*)path;
	Sfile = CreateFile(Spath, GENERIC_READ, FILE_SHARE_READ , NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (Sfile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, "File is not existing", "Warning!", NULL);
		CloseHandle(Sfile);
		return 0;
	}

	int Ssize = GetFileSize(Sfile, NULL);
	void* Shellcode = VirtualAlloc(NULL, Ssize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	DWORD readsize;

	if (Shellcode == NULL) {
		MessageBox(NULL, "Alloc memery failed!", "Warning!", NULL);
		CloseHandle(Sfile);
		return 0;
	}

	ReadFile(Sfile, Shellcode, Ssize, &readsize, NULL);

	try
	{
		__asm
		{
			mov eax, Shellcode
			call eax
		}
	}
	catch (...)
	{
		MessageBox(NULL, "Run shellcode failed!", "Warning!", NULL);
		CloseHandle(Sfile);
		return 0;
	}

	MessageBox(NULL, "Run shellcode successed!", "Warning!", NULL);
	VirtualFree(Shellcode, Ssize, MEM_DECOMMIT);
	CloseHandle(Sfile);
	return 1;

}

int ShellcodeDebuger(const char* Spath) {

	HANDLE Sfile = INVALID_HANDLE_VALUE;
	//const char* Spath = (char*)path;
	Sfile = CreateFile(Spath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (Sfile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, "File is not existing", "Warning!", NULL);
		CloseHandle(Sfile);
		return 0;
	}

	int Ssize = GetFileSize(Sfile, NULL);
	void* Shellcode = VirtualAlloc(NULL, Ssize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	DWORD readsize;

	if (Shellcode == NULL) {
		MessageBox(NULL, "Alloc memery failed!", "Warning!", NULL);
		CloseHandle(Sfile);
		return 0;
	}
	
	BYTE bPoint[4] = {0xCC, 0xCC, 0xCC, 0xCC};

	memcpy(Shellcode, bPoint, 4);
	ReadFile(Sfile, (char*)Shellcode + 4, Ssize, &readsize, NULL);
	
	try
	{
		__asm
		{
			mov eax, Shellcode
			call eax
		}
	}
	catch (...)
	{
		MessageBox(NULL, "Run shellcode failed!", "Warning!", NULL);
		CloseHandle(Sfile);
		return 0;
	}

	//然而并执行不到23333333333333
	MessageBox(NULL, "Run shellcode successed!", "Warning!", NULL);
	VirtualFree(Shellcode, Ssize, MEM_DECOMMIT);
	CloseHandle(Sfile);
	return 1;

}







void CShellcodeRunDlg::OnDropFiles(HDROP hDropInfo)
{

	// TODO: 在此添加消息处理程序代码和/或调用默认值  
	char TSpath[MAX_PATH];
	DragQueryFile(hDropInfo, 0, TSpath, MAX_PATH);//获得拖曳的第i个文件的文件名  
	m_editPath.SetWindowTextA(TSpath);
	UpdateData(FALSE);
	CDialog::OnDropFiles(hDropInfo);
}
