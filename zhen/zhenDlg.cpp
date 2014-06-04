
// zhenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zhen.h"
#include "zhenDlg.h"
#include "afxdialogex.h"
#include "math.h" 
#include "locale.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static int isSort = TRUE;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CzhenDlg dialog




CzhenDlg::CzhenDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CzhenDlg::IDD, pParent)
	, select_ten_thousands(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CzhenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, customerName);
	DDX_Control(pDX, IDC_EDIT2, customerPrice);
	DDX_Control(pDX, IDC_LIST2, result_list);
	DDX_Control(pDX, IDC_EDIT3, weight);
	DDX_Control(pDX, IDC_EDIT4, k1_value);
	DDX_Control(pDX, IDC_EDIT5, k2_value);
	DDX_Control(pDX, IDC_EDIT6, base_price);
	DDX_Control(pDX, IDC_RADIO1, _radio_unit);
	DDX_Control(pDX, IDC_RADIO2, _radio_ten_thousands);
	DDX_Control(pDX, IDC_EDIT7, _edit_floating_percents);
	DDX_Control(pDX, IDC_CHECK2, _check_box_floating_percents);
	DDX_Control(pDX, IDC_CHECK1, _check_box_del_max_min);
	DDX_Control(pDX, IDC_BUTTON3, _button_export_data);
}

BEGIN_MESSAGE_MAP(CzhenDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CzhenDlg::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CzhenDlg::OnNMDblclkList1)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON2, &CzhenDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CzhenDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CzhenDlg::OnBnClickedButton4)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &CzhenDlg::OnNMRClickList2)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &CzhenDlg::OnLvnColumnclickList1)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CzhenDlg::OnHdnItemclickList2)
	ON_EN_CHANGE(IDC_EDIT7, &CzhenDlg::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_RADIO1, &CzhenDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CzhenDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK2, &CzhenDlg::OnBnClickedCheck2)
	ON_COMMAND(ID_32771, &CzhenDlg::On32771)
	ON_BN_CLICKED(IDC_BUTTON3, &CzhenDlg::OnBnClickedButton3)
	ON_COMMAND(ID_32772, &CzhenDlg::On32772)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CzhenDlg message handlers

BOOL CzhenDlg::OnInitDialog()
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

	_radio_unit.SetCheck(1);
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CRect rect;

	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("1"), LVCFMT_CENTER, 1, 0);
	m_list.InsertColumn(1, _T("投  标  人"), LVCFMT_CENTER, rect.Width()/2, 0);
	m_list.InsertColumn(2, _T("投标总报价"), LVCFMT_CENTER, rect.Width()/2, 1);
	m_list.DeleteColumn(0);

	result_list.GetClientRect(&rect);
	result_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	result_list.InsertColumn(0, _T("1"), LVCFMT_CENTER, 1, 0);
	result_list.InsertColumn(1, _T("投 标 人"), LVCFMT_CENTER, rect.Width()/2, 0);
	result_list.InsertColumn(2, _T("报价得分"), LVCFMT_CENTER, rect.Width()/2, 1);
	result_list.DeleteColumn(0);

	price_pDataNumber = 0;
	points_pDataNumber = 0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CzhenDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CzhenDlg::OnPaint()
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
HCURSOR CzhenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CzhenDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CzhenDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CzhenDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	if(::IsWindow(m_list.m_hWnd))
	{
		//m_list.MoveWindow(10,10,cx-20,cy-50);
	}
}



void CzhenDlg::OnBnClickedButton2()
{
	CString name;
	CString price;
	customerName.GetWindowText(name);
	customerPrice.GetWindowText(price);
	char buf[128] = {0};
	m_list.GetItemCount();

	if(name.Trim().IsEmpty () || price.Trim().IsEmpty())
	{
		MessageBoxW(_T("Empty"));
		return;
	}
	int num = m_list.GetItemCount();
	price_pData[price_pDataNumber] = new MY_ITEMDATA;
	m_list.InsertItem(num, name);
	m_list.SetItemText(num,1, price);
	price_pData[price_pDataNumber]->name = name;
	price_pData[price_pDataNumber]->points = 0.0;
	price_pData[price_pDataNumber]->isRet = FALSE;
	price_pData[price_pDataNumber]->price = _wtof(price);
	m_list.SetItemData(num, (LPARAM)price_pData[price_pDataNumber]);

	customerName.SetFocus();

	customerName.SetWindowTextW(_T(""));
	customerPrice.SetWindowTextW(_T(""));

	price_pDataNumber++;
	// TODO: Add your control notification handler code here
}


void CzhenDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	customerName.SetWindowTextW(_T(""));
	customerPrice.SetWindowTextW(_T(""));
}


void CzhenDlg::OnBnClickedButton4()
{
	CString _t_weight,_t_k1,_t_k2,_t_base;
	weight.GetWindowText(_t_weight);
	k1_value.GetWindowText(_t_k1);
	k2_value.GetWindowText(_t_k2);
	base_price.GetWindowText(_t_base);

	double F = _wtof(_t_weight);
	double K1 = _wtof(_t_k1);;
	double K2 = _wtof(_t_k2);
	CString basePrice;

	int customer_num = m_list.GetItemCount();
	double max_price = 0.0;
	double min_price = 10000000000000.0;
	double sum = 0;
	double base_double = 0;

	for(int i = 0;i<customer_num;i++)
	{
		double cur_price = _wtof(m_list.GetItemText(i,1));
		if(cur_price > max_price)
		{
			max_price = cur_price;
		}

		if(cur_price <= min_price)
		{
			min_price = cur_price;
		}

		sum += cur_price;
	}

	if(customer_num >= 5 && _check_box_del_max_min.GetCheck())
	{
		sum -= max_price;
		sum -= min_price;
		base_double = sum / (customer_num - 2);
	}
	else if(customer_num > 0)
	{
		base_double = sum / customer_num;
	}

	if(_check_box_floating_percents.GetCheck())
	{
		CString percent_str;
		_edit_floating_percents.GetWindowTextW(percent_str);
		base_double = base_double * (100.0 - _wtof(percent_str))/100;
	}
	base_double = (int)(base_double * 100 + 0.5)/100.0;
	basePrice.Format(_T("%0.2f(%s)"),base_double,_radio_unit.GetCheck()?_T("元"):_T("万元"));
	base_price.SetReadOnly(0);
	base_price.SetWindowTextW(basePrice);
	base_price.SetReadOnly(1);

	if(base_double > -0.0000001 && base_double < 0.0000001)
	{
		MessageBoxW(_T("基准价太小了"));
		return;
	}

	result_list.DeleteAllItems();
	for(int i = 0; i < customer_num;i++)
	{
		CString name = m_list.GetItemText(i,0); 
		double P1 = _wtof(m_list.GetItemText(i,1));
		double K = P1 >= base_double?K1:K2;
		double points = F-fabsl(P1-base_double)/base_double*100*K;

		int num = result_list.GetItemCount();

		points_pData[points_pDataNumber] = new MY_ITEMDATA;
		points_pData[points_pDataNumber]->isRet = TRUE;
		points_pData[points_pDataNumber]->name = name;
		points_pData[points_pDataNumber]->points = points > 0.00 ? points: 0.00;
		CString P;
		P.Format(_T("%0.2f"),points > 0.00 ? points: 0.00);
		result_list.InsertItem(num, name);
		result_list.SetItemText(num,1,P);
		result_list.SetItemData(num, (LPARAM)points_pData[points_pDataNumber]);

		points_pDataNumber++;

	}

	// TODO: Add your control notification handler code here
}


void CzhenDlg::OnNMRClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
#if 0
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if (pNMHDR->hwndFrom == m_list.GetHeaderCtrl()->m_hWnd)
	{
		MessageBoxW(_T("222222222"));
	}
	if (pNMHDR->hwndFrom == result_list.GetHeaderCtrl()->m_hWnd)
	{
		MessageBoxW(_T("212121"));
	}
#endif
	if(pNMListView->iItem != -1)
	{
		DWORD dwPos = GetMessagePos();
		CPoint point( LOWORD(dwPos), HIWORD(dwPos) );

		CMenu menu;
		VERIFY( menu.LoadMenu( IDR_MENU1 ) );
		CMenu* popup = menu.GetSubMenu(0);
		ASSERT( popup != NULL );
		popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
	} 
	*pResult = 0;
}

int CALLBACK SortFuncPoints(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	int nRetVal;
	PMYITEMDATA pData1 = (PMYITEMDATA)lParam1;
	PMYITEMDATA pData2 = (PMYITEMDATA)lParam2;
	if(isSort%2)
	{
		nRetVal = (pData1->points > pData2->points);
	}
	else
	{
		nRetVal = (pData1->points <= pData2->points);
	}

	return nRetVal;
}

void CzhenDlg::OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	*pResult = 0;
}

int CALLBACK SortFuncPrice(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	int nRetVal;
	PMYITEMDATA pData1 = (PMYITEMDATA)lParam1;
	PMYITEMDATA pData2 = (PMYITEMDATA)lParam2;
	if(isSort%2)
	{
		nRetVal = (pData1->price > pData2->price);
	}
	else
	{
		nRetVal = (pData1->price <= pData2->price);
	}
	return nRetVal;
}

void CzhenDlg::OnHdnItemclickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);

	isSort +=1;

	if (pNMHDR->hwndFrom == result_list.GetHeaderCtrl()->m_hWnd)
	{
		result_list.SortItems(SortFuncPoints,phdr->iItem);
	}

	if (pNMHDR->hwndFrom == m_list.GetHeaderCtrl()->m_hWnd)
	{
		m_list.SortItems(SortFuncPrice,phdr->iItem);
	}
	*pResult = 0;
}



void CzhenDlg::OnEnChangeEdit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CzhenDlg::OnBnClickedRadio1()
{
	if(!_radio_unit.GetCheck())
	{
		_radio_unit.SetCheck(1);
	}
	_radio_unit.GetCheck()?_radio_ten_thousands.SetCheck(0):_radio_ten_thousands.SetCheck(1);
	// TODO: Add your control notification handler code here
}


void CzhenDlg::OnBnClickedRadio2()
{
	if(!_radio_ten_thousands.GetCheck())
	{
		_radio_ten_thousands.SetCheck(1);
	}
	_radio_ten_thousands.GetCheck()?_radio_unit.SetCheck(0):_radio_unit.SetCheck(1);
	// TODO: Add your control notification handler code here
}


void CzhenDlg::OnBnClickedCheck2()
{
	if(_check_box_floating_percents.GetCheck())
	{
		_edit_floating_percents.SetReadOnly(0);
	}
	else
	{
		_edit_floating_percents.SetReadOnly(1);
		_edit_floating_percents.SetWindowTextW(_T(""));
	}
	// TODO: Add your control notification handler code here
}


void CzhenDlg::On32771()
{
	// TODO: Add your command handler code here
	CString str;
	for(int i=0; i<m_list.GetItemCount(); i++)
	{
		if( m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
		{
			m_list.DeleteItem(i);
		}
	}
}

CString GetFileFilename()
{
	CString str;
	CTime t(CTime::GetCurrentTime().GetTime());
	str=t.Format(L"%Y_%m_%d");
	return str+_T(".csv");
}

void CzhenDlg::OnBnClickedButton3()
{
	CString weight_str("报价分权重,");
	CString k1_str("K1(高于),");
	CString k2_str("K2(低于),");
	CString base_str("评标基准价,");
	CString header("投标人,投标得分\n");

	char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	CStdioFile _File;
	_File.Open(GetFileFilename(),CFile::modeCreate|CFile::modeReadWrite);
	CString tmp;
	weight.GetWindowTextW(tmp);
	_File.WriteString(weight_str+tmp+"\n");

	k1_value.GetWindowTextW(tmp);
	_File.WriteString(k1_str +tmp+"\n");

	k2_value.GetWindowTextW(tmp);
	_File.WriteString(k2_str +tmp+"\n");

	base_price.GetWindowTextW(tmp);
	_File.WriteString(base_str);
	setlocale( LC_CTYPE, "chs" );
	_File.WriteString(tmp);
	setlocale( LC_CTYPE, old_locale );
	_File.WriteString(_T("\n"));

	_File.WriteString(header);

	int num = result_list.GetItemCount();
	CString name;
	CString points;
	for(int i = 0;i < num;i++)
	{
		name = result_list.GetItemText(i,0);
		points = result_list.GetItemText(i,1);
		CString ret = name+","+points+"\n";
		setlocale( LC_CTYPE, "chs" );
		_File.WriteString(ret);
		setlocale( LC_CTYPE, old_locale );
	}
	_File.Flush();
	_File.Close();
	MessageBoxW(_T("导出成功：")+GetFileFilename());
	free( old_locale );//还原区域设定
}


void CzhenDlg::On32772()
{
	m_list.DeleteAllItems();
	// TODO: Add your command handler code here
}


void CzhenDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	for(int i = 0;i<price_pDataNumber;i++)
	{
		delete price_pData[i];
	}

	for(int i = 0;i<points_pDataNumber;i++)
	{
		delete points_pData[i];
	}
	CDialogEx::OnClose();
}
