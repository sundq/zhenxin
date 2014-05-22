
// zhenDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CzhenDlg dialog
class CzhenDlg : public CDialogEx
{
// Construction
public:
	CzhenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ZHEN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list;
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CEdit customerName;
	CEdit customerPrice;
	afx_msg void OnBnClickedButton2();
	CListCtrl result_list;
	afx_msg void OnBnClickedButton1();
	CEdit weight;
	CEdit k1_value;
	CEdit k2_value;
	CEdit base_price;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnNMRClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemclickList2(NMHDR *pNMHDR, LRESULT *pResult);
	int select_ten_thousands;
	afx_msg void OnEnChangeEdit7();
	CButton _radio_unit;
	CButton _radio_ten_thousands;
	CEdit _edit_floating_percents;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedCheck2();
	CButton _check_box_floating_percents;
	afx_msg void On32771();
	CButton _check_box_del_max_min;
};
