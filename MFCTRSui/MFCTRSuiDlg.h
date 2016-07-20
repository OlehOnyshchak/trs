
// MFCTRSuiDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <vector>
#include "Resource.h"
extern CTreeCtrl m_Tree;
class SuiteRoot
{
public:
	SuiteRoot()
	{
		dRoot = nullptr;
	}
	SuiteRoot(TCHAR* path)
	{
		int size = wcslen(path);
		dRoot = new TCHAR[size + 1];
		wcscpy_s(dRoot, size + 1, path);
	}
	SuiteRoot(const SuiteRoot& var)
	{
		int size = wcslen(var.dRoot);
		dRoot = new TCHAR[size + 1];
		wcscpy_s(dRoot, size + 1, var.dRoot);
	}
	inline TCHAR* get_path()
	{
		return dRoot;
	}

	~SuiteRoot()
	{
		delete[] dRoot;
	}
private:
	TCHAR* dRoot;
};

extern CEdit console_output;

// CMFCTRSuiDlg dialog
class CMFCTRSuiDlg : public CDialogEx
{
	// Construction
public:
	CMFCTRSuiDlg(CWnd* pParent = NULL);	// standard constructor
	~CMFCTRSuiDlg();
// Dialog Data
	enum { IDD = IDD_MFCTRSUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_Tree;
	afx_msg void OnEnChangeEdit1();
	CEdit C_edit;
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnBnClickedButton1();


	afx_msg void OnEnChangeEdit2();
	CEdit report_edit;

	afx_msg void OnBnClickedButton2();
	CEdit console_output;


	afx_msg void OnBnClickedButton();
	afx_msg void RunButtonClicked();
protected:

public:
	afx_msg void OnBnClickedAddfolder();
protected:
	CListBox RootList;
	std::vector<SuiteRoot> dRoots;

	CButton RunButton;
	void Info(TCHAR* path);
public:
	afx_msg void OnLbnSelchangeListroot();
	afx_msg void OnBnClickedDeletebutton();
	afx_msg void OnBnClickedRunselected();
protected:
	CButton DeleteButton;
};
