// getcitynameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "getcityname.h"
#include "getcitynameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetcitynameDlg dialog

CGetcitynameDlg::CGetcitynameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetcitynameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetcitynameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetcitynameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetcitynameDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetcitynameDlg, CDialog)
	//{{AFX_MSG_MAP(CGetcitynameDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetcitynameDlg message handlers

BOOL CGetcitynameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGetcitynameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGetcitynameDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGetcitynameDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGetcitynameDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

typedef unsigned char       BOOLEAN;

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned long int   uint32;
typedef unsigned long int   uint64;
typedef unsigned int        uint;

typedef signed char         int8;
typedef signed short        int16;
typedef signed long int     int32;


typedef enum
{
    MMICOM_SEARCH_FIRST_EQUAL,//������ǰ���һ����ͬ���˳�
    MMICOM_SEARCH_LAST_EQUAL,//��������һ����ͬ���˳�
    MMICOM_SEARCH_ANY_EQUAL,//��������һ����ͬ���˳�
}MMI_BIN_SEARCH_TYPE_E;

typedef struct _MMI_BIN_SEARCH_INFO_T
{
    int32  start_pos;
	int32  end_pos;
	void    *compare_base_data;
	MMI_BIN_SEARCH_TYPE_E search_type;
}MMI_BIN_SEARCH_INFO_T;
typedef int (* BIN_COMPARE_FUNC)(uint32 base_index, void *compare_base_data, void *list);

int MMIAPICOM_BinSearch(MMI_BIN_SEARCH_INFO_T *search_info, //[IN]
                           BIN_COMPARE_FUNC func, //[IN]
                           uint32 *pos, //[OUT]
                           void *list//[IN]
                           )
{
	BOOLEAN         is_in_list  = FALSE;    // ��¼�Ƿ��б�������ȫһ��������
	uint32	        ret_pos         = 0;        // ��¼�ҵ��ĺ���λ��
    int32          low_pos	    = search_info->start_pos;        // ���ַ���ǰһ��λ��
    int32          mid_pos	    = 0;        // ���ַ����м�λ��
   	int32          high_pos	= search_info->end_pos;        // ���ַ��ĺ�һ��λ��
	int 	        cmp_result  = 0;  // �����ַ����ıȽϽ��

    if(NULL == search_info || (NULL == func) || (NULL == pos))
    {
        return FALSE;
    } 
	//func = func_t->func;
	// ���ַ�����
	//SCI_TRACE_LOW("MMIPB_BinSearch low_pos %d, high_pos %d",low_pos,high_pos);
	while (low_pos <= high_pos)	// ������ַ�������
	{
	    // ���mid_pos
	    mid_pos = ((low_pos + high_pos) >> 1); 
        // �������ַ������бȽ�//
        cmp_result = (*func)(mid_pos,search_info->compare_base_data, list);
        // ���ݱȽϵĽ���������ҵķ�Χ
        if (cmp_result < 0)
      	{
          	low_pos = (mid_pos + 1);
      	}
      	else if (cmp_result > 0)
      	{
			if(mid_pos == 0)
			{
				break;
 			}
          	high_pos = mid_pos -1;
        }
        else // begin (0 == cmp_result)
        {
            // ��ʾ�б�������ȫһ���ļ�¼��
            // ��¼Ŀǰ��λ�ã�������Ѿ��ҵ������ļ�¼��
        	is_in_list  = TRUE;
        	ret_pos     = mid_pos;
            
            // ���Ҳ���
            // ����ʱ����Ҫ������ǰ�ң����������ң��õ����ʵĲ��ҷ�Χ  
            if (MMICOM_SEARCH_LAST_EQUAL == search_info->search_type)
        	{
                low_pos = (mid_pos + 1);
            }
            else if(MMICOM_SEARCH_FIRST_EQUAL == search_info->search_type)
            {
            	// ���п��ܲ����б���������������ǰ��һ����¼����Ҫ����Ѱ��
                if(mid_pos == 0)
				{
					break;
				}
				high_pos = (mid_pos - 1);	
            }
            else
            {
                //�ҵ�����һ����ȵľ��˳�
                break;
            }

        } // end (0 == cmp_result)
    } // end of while

    if (!is_in_list)
    {
        if(cmp_result < 0)
        {
            ret_pos = low_pos;
        }
        else
        {
            ret_pos = mid_pos;
        }
    }
	else
	{
		cmp_result = 0;
	}
    *pos = ret_pos;
    
    return cmp_result;    
}

char cityname[1000][20];
uint32 city_order[1000];
char tmpname[100];
uint32  city_cnt = 0;

int CompareCityname(uint32 base_index, void *compare_data, void *list)
{
	int i = 0;
	int result;
    uint16 *cur_item = (uint16*)compare_data;

    uint16 *base_item = (uint16*)cityname[city_order[base_index]];

	#if 1
	CString str1;
	CString str2;

	str1 = CString(LPCWSTR(cur_item));
	str2 = CString(LPCWSTR(base_item));
	
	return str2.Compare(str1);
	#endif

	while(cur_item[i] == base_item[i] && '\0' != cur_item[i]) 
	{
		i++;
	}

	if ('\0' == cur_item[i] && '\0' == base_item[i])
	{
		result = 0;
	}
	else if (cur_item[i] > base_item[i])
	{
		result = -1;
	}
	else 
	{
		result = 1;
	}
	
    return result;
}

int find_pos(uint32 *pos,char *cur_item)
{
    MMI_BIN_SEARCH_INFO_T search_info = {0};
    
    search_info.search_type = MMICOM_SEARCH_ANY_EQUAL;
    
    search_info.end_pos = city_cnt - 1;
    
    search_info.compare_base_data = (void *)cur_item;
    
    return MMIAPICOM_BinSearch(&search_info, (BIN_COMPARE_FUNC)CompareCityname, pos, (void *)1);
}

static uint32 file_line = 0;

BOOLEAN get_city_name(char *name, FILE *fp)
{
    int ch;
	int ch1;
    int cnt = 0;
    
    while ((ch = fgetc(fp)) != EOF && (ch1 = fgetc(fp)) != EOF)
    {
		
        if ((0xd == ch && 0 == ch1) || (0xa == ch && 0 == ch1))
        {
			if (0 != cnt)
			{
                file_line++;
				break;
			}
            else
            {
                continue;
            }
        }
        
        name[cnt] = ch;
        cnt++;
        
        name[cnt] = ch1;
        cnt++;
    }

    return cnt;
}

int wstr_len(char *str)
{
	int len = 0;
	uint16 *wstr = (uint16 *)str;

	while('\0' != wstr[len++]);

	return len - 1;
}

void save_city_by_order(void)
{
    FILE *fp=NULL;
	int i = 0;
	char line[] = {'\r', 0, '\n', 0};
	
    if (NULL == (fp=fopen("result.txt","wb")))
    {
        printf("open file error!");
        return ;
    }

    fputc(0xff,fp);            
	fputc(0xfe,fp);

	for (i=0;i<city_cnt;i++)
	{
		
		int tmplen = wstr_len(cityname[city_order[i]])*sizeof(uint16);
		
		fwrite(cityname[city_order[i]], tmplen, 1, fp);
		fwrite(line,4,1,fp);
	}

	fclose(fp);

}

int get_city(void)
{
    FILE *fp=NULL;
    FILE *fp2 = NULL;
    uint32 pos = 0;
    uint32 need_moved_num = 0;
    long int file_len = 0;

    if (NULL == (fp=fopen("city.txt","rb")))
    {
        printf("open file error!");
        return 1;
    }

    if (NULL == (fp2=fopen("city2.txt","wb")))
    {
        printf("open file2 error!");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
	file_len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
    fgetc(fp);fgetc(fp);

    get_city_name(tmpname,fp);
    memcpy(cityname+city_cnt,tmpname,strlen(tmpname));
	city_order[pos] = city_cnt;
    city_cnt++;

    memset(tmpname, 0, sizeof(tmpname));

    
    CStdioFile myFile;

    CFileException fileException;
	uint32 i = 1;
    if(myFile.Open("getcttt.txt",CFile::typeText|CFile::modeCreate|CFile::modeReadWrite),&fileException)
    {



    }
                fputc(0xff,fp2);            fputc(0xfe,fp2);
    while(get_city_name(tmpname,fp))
    {
        if (0 != find_pos(&pos, tmpname))
        {
        	int tmplen = wstr_len(tmpname)*sizeof(uint16);
            memcpy(cityname+city_cnt,tmpname,tmplen);
            
            if(pos != city_cnt)
            {
                need_moved_num = city_cnt - pos;
                memmove(city_order+pos+1, 
                        city_order+pos, 
                        need_moved_num * sizeof(city_order[0]));
            }
            
            city_order[pos] = city_cnt;
            city_cnt++;
            if (city_cnt == 246)
            {
                int kdsfsl;
                kdsfsl++;
            }

			#if 0
			fwrite(tmpname, tmplen, 1, fp2);
            //fputs(tmpname,fp2);
                        fputs("\r",fp2);
                        
                        fputc(0,fp2);
            fputs("\n",fp2);
            
            fputc(0,fp2);
			#endif
        }

        memset(tmpname, 0, sizeof(tmpname));
    }
	
	save_city_by_order();

	return 0;
}
void CGetcitynameDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
	get_city();
}