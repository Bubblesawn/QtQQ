#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>


enum ButtonType
{
	MIN_BUTTON = 0,//��С�����رհ�ť
	MIN_MAX_BUTTON,//��С������󻯼��رհ�ť
	ONLY_CLOSS_BUTTON,//ֻ�йرհ�ť

};

//�Զ��������

class TitleBar : public QWidget
{
	Q_OBJECT

public:
	TitleBar(QWidget* parent);
	~TitleBar();

	void setTitleIcon(QString& filePath);         //���ñ�����ͼ��
	void setTitleContent(QString& title);         //���ñ�������
	void setTitleWidth(int width);                //���ñ���������
	void setButtonType(ButtonType buttonType);    //���ñ�������ť����


	//���桢��ȡ�������ǰ���ڵ�λ�úʹ�С
	void saveResoreInfo(const QPoint &point,const QSize &size);
	void getResoreInfo(QPoint& point, QSize& size);

private:
		void paintEvent(QPaintEvent * event);             //��ͼ�¼�
		void mouseDoubleClickEvent(QMouseEvent* event);  //���˫���¼�
		void mousePressEvent(QMouseEvent* event);        //��갴���¼�
		void mouseMoveEvent(QMouseEvent* event);         //����ƶ��¼�
		void mouseReleaseEvent(QMouseEvent* event);      //����ɿ��¼�

		void initControl();                              //��ʼ���ؼ�
		void initConnections();                          //��ʼ���źźͲ۵�����
		void loadStyleSheet(const QString &sheetname);   //������ʽ��

signals:
	//��ť������ź�
	void signalButtonMinClicked();        //��С����ť�����
	void signalButtonRestoreClicked();    //��󻯻�ԭ��ť�����
	void signalButtonMaxClicked();        //��󻯰�ť�����
	void signalButtonCloseClicked();      //��󻯹رհ�ť�����

private slots:
	//��ť��Ӧ�Ĳۺ���
	void onButtonMinClicked();        //��С����ť�����
	void onButtonRestoreCliced();     //��󻯻�ԭ��ť�����
	void onButtonMaxClicked();        //��󻯰�ť�����
	void onButtonCloseClicked();      //�رհ�ť�����
	  
private:
	QLabel* m_pIcon;               //������ͼ��
    QLabel* m_pTitleContent;              //����������
    QPushButton* m_pButtonMin;     //��С����ť
	QPushButton* m_pButtonMax;     //��󻯰�ť
	QPushButton* m_pButtonRestore; //��󻯻�ԭ��ť
	QPushButton* m_pButtonClose;   //�رհ�ť

	//��󻯻�ԭ��ť���������ڱ��洰���λ�ü���С��
	QPoint m_restorePos;          //��󻯻�ԭǰ�Ĵ���λ��
	QSize m_restoreSize;        //��󻯻�ԭǰ�Ĵ����С

	//�ƶ����ڵı���
	bool m_isPressed;            //����Ƿ���;
	QPoint m_startMovePos;       //��갴��ʱ������

	QString m_titleContent;      //������������
	ButtonType m_buttonType;     //���������Ͻǰ�ť����

};

