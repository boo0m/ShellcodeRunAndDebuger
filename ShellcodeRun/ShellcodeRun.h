
// ShellcodeRun.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CShellcodeRunApp: 
// �йش����ʵ�֣������ ShellcodeRun.cpp
//

class CShellcodeRunApp : public CWinApp
{
public:
	CShellcodeRunApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CShellcodeRunApp theApp;