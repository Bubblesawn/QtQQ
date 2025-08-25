#pragma once
#include <QDialog>
#include "titlebar.h"


class BasicWindow  : public QDialog
{
	Q_OBJECT

public:
	BasicWindow(QWidget *parent  = nullptr);
	virtual ~BasicWindow();

public:
	//������ʾ��
	void loadStyleSheet(const QString &sheetname);

	//��ȡԲͷ��
	QPixmap getRoundImage (const QPixmap& src, QPixmap& mask,QSize masksize = QSize(0,0));

private:
	void initBackGroundColor(); //��ʼ������

protected:
	void paintEvent(QPaintEvent*);                //�����¼�
	void mouseEvent(QMouseEvent* event);         //����¼�
	void mouseMoveEvent(QMouseEvent* event);      // ����ƶ��¼�
	void mouseRleaseEvent(QMouseEvent* event);    //����ɿ��¼�


protected:
	void initTitleBar(ButtonType  buttontype = MIN_BUTTON);
	void setTitleBarTitle(const QString& title, const QString& icon = "");

public slots:
	void onShowClose(bool);
	void onSHowMin(bool);
	void onShowHide(bool);
	void onShowNormal(bool);
	void onShowQuit(bool);
	void onSignalSKinChanged(const QColor& color);

	void onButtonMinClicked();
	void onButtonRestoreCliced();
	void onButtonMaxClicked();
	void onButtonCloseClicked(); 

protected:
	QPoint m_mouseePoint; //���λ��
	bool m_mousePressed ; //����Ƿ���
	QColor m_colorBackGround; //������ɫ
	QString m_styleName; //��ʽ������
	TitleBar* _titleBar;//������


};

