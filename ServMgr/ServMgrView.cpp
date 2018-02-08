
// ServMgrView.cpp : CServMgrView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ServMgr.h"
#endif

#include "ServMgrDoc.h"
#include "ServMgrView.h"

#include "ServConfig.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CServMgrView

IMPLEMENT_DYNCREATE(CServMgrView, CListView)

BEGIN_MESSAGE_MAP(CServMgrView, CListView)
END_MESSAGE_MAP()

// CServMgrView ����/����

CServMgrView::CServMgrView()
{
	// TODO:  �ڴ˴���ӹ������

}

CServMgrView::~CServMgrView()
{
}

BOOL CServMgrView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CListView::PreCreateWindow(cs);
}

void CServMgrView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	SetWindowLong(GetListCtrl().m_hWnd, GWL_STYLE, GetWindowLong(GetListCtrl().m_hWnd, GWL_STYLE) | LVS_REPORT);
	GetListCtrl().SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	GetListCtrl().InsertColumn(0, _T("��������"), LVCFMT_LEFT, 150);
	GetListCtrl().InsertColumn(1, _T("����״̬"), LVCFMT_LEFT, 90);
	GetListCtrl().InsertColumn(2, _T("��������"), LVCFMT_LEFT, 90);
	GetListCtrl().InsertColumn(3, _T("�ļ�·��"), LVCFMT_LEFT, 230);
	GetListCtrl().InsertColumn(4, _T("��������"), LVCFMT_LEFT, 400);

	CServConfig  m_ServCfg;
	CServItem *m_pHeader = m_ServCfg.EnumServList();
	if (!m_pHeader) {
		return;
	}
	for (int idx = 0; m_pHeader != NULL; idx++) {
		GetListCtrl().InsertItem(idx, _T(""));
		GetListCtrl().SetItemText(idx, 0, m_pHeader->m_strServDispName);
		GetListCtrl().SetItemText(idx, 1, m_ServCfg.GetStateString(m_pHeader->m_dwServState));
		GetListCtrl().SetItemText(idx, 2, m_ServCfg.GetStartTypeString(m_pHeader->m_dwStartType));
		GetListCtrl().SetItemText(idx, 3, m_pHeader->m_strBinPath);
		GetListCtrl().SetItemText(idx, 4, m_pHeader->m_strDescription);
		m_pHeader = m_pHeader->m_pNext;
	}
}


// CServMgrView ���

#ifdef _DEBUG
void CServMgrView::AssertValid() const
{
	CListView::AssertValid();
}

void CServMgrView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CServMgrDoc* CServMgrView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CServMgrDoc)));
	return (CServMgrDoc*)m_pDocument;
}
#endif //_DEBUG


// CServMgrView ��Ϣ�������
