#pragma once
#include <QDialog>
#include "titlebar.h"

// 确保注释和字符串中没有非 UTF-8 字符
class BasicWindow : public QDialog
{
    Q_OBJECT

public:
    BasicWindow(QWidget *parent = nullptr);
    virtual ~BasicWindow();

    // 加载演示表
    void loadStyleSheet(const QString &sheetname);

    // 获取圆头像
    QPixmap getRoundImage(const QPixmap &src, QPixmap &mask, QSize masksize = QSize(0, 0));

private:
    void initBackGroundColor(); // 初始化背景

protected:
    void paintEvent(QPaintEvent *);               // 绘制事件
    void mouseEvent(QMouseEvent *event);          // 鼠标事件
    void mouseMoveEvent(QMouseEvent *event);      // 鼠标移动事件
    void mouseRleaseEvent(QMouseEvent *event);    // 鼠标松开事件

protected:
    void initTitleBar(ButtonType buttontype = MIN_BUTTON);
    void setTitleBarTitle(const QString &title, const QString &icon = "");

public slots:
    void onShowClose(bool);
    void onSHowMin(bool);
    void onShowHide(bool);
    void onShowNormal(bool);
    void onShowQuit(bool);
    void onSignalSkinChanged(const QColor &color);

    void onButtonMinClicked();
    void onButtonRestoreCliced();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

protected:
    QPoint m_mouseePoint;       // 鼠标位置
    bool m_mousePressed;        // 鼠标是否按下
    QColor m_colorBackGround;   // 背景颜色
    QString m_styleName;        // 样式表名称
    TitleBar *_titleBar;        // 标题栏
};

