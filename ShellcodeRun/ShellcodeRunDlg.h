
// ShellcodeRunDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CShellcodeRunDlg �Ի���
class CShellcodeRunDlg : public CDialogEx
{
// ����
public:
	CShellcodeRunDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHELLCODERUN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticPath();
	afx_msg void OnBnClickedButtonPath();
	CEdit m_editPath;
	afx_msg void OnBnClickedButtonDebug();
	afx_msg void OnBnClickedButtonRun();
	afx_msg void OnDropFiles(HDROP hDropInfo);
};
