
// ShellcodeRunDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ShellcodeRun.h"
#include "ShellcodeRunDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CShellcodeRunDlg �Ի���



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


// CShellcodeRunDlg ��Ϣ�������

BOOL CShellcodeRunDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_SHOW);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CShellcodeRunDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CShellcodeRunDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShellcodeRunDlg::OnStnClickedStaticPath()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CShellcodeRunDlg::OnBnClickedButtonPath()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	CString shellcode_path;
	m_editPath.GetWindowText(shellcode_path);

	ShellcodeDebuger(shellcode_path);


}



void CShellcodeRunDlg::OnBnClickedButtonRun()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	//Ȼ����ִ�в���23333333333333
	MessageBox(NULL, "Run shellcode successed!", "Warning!", NULL);
	VirtualFree(Shellcode, Ssize, MEM_DECOMMIT);
	CloseHandle(Sfile);
	return 1;

}







void CShellcodeRunDlg::OnDropFiles(HDROP hDropInfo)
{

	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ  
	char TSpath[MAX_PATH];
	DragQueryFile(hDropInfo, 0, TSpath, MAX_PATH);//�����ҷ�ĵ�i���ļ����ļ���  
	m_editPath.SetWindowTextA(TSpath);
	UpdateData(FALSE);
	CDialog::OnDropFiles(hDropInfo);
}
