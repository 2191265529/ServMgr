
// ServMgrView.h : CServMgrView ��Ľӿ�
//

#pragma once


class CServMgrView : public CListView
{
protected: // �������л�����
	CServMgrView();
	DECLARE_DYNCREATE(CServMgrView)

// ����
public:
	CServMgrDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CServMgrView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ServMgrView.cpp �еĵ��԰汾
inline CServMgrDoc* CServMgrView::GetDocument() const
   { return reinterpret_cast<CServMgrDoc*>(m_pDocument); }
#endif
