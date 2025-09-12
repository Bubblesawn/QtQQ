#include "CCMainWindow.h"
#include <QtWidgets/QApplication>
#include "UserLogin.h"
#include <qDebug>
#include <QMessageBox>
#include "basicwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //CCMainWindow window;

    //window.show();

    UserLogin* userlogin = new UserLogin;

   
   // QMessageBox::information(nullptr, "提示", "程序启动了！");

    userlogin->show();

    return app.exec();

}
