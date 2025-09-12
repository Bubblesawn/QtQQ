/********************************************************************************
** Form generated from reading UI file 'userlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGIN_H
#define UI_USERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserLoginClass
{
public:
    QWidget *titleWidget;
    QWidget *bodyWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *editUserAccount;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *editPassword;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBox_2;
    QPushButton *forgetWordBtn;
    QPushButton *registBtn;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *UserLoginClass)
    {
        if (UserLoginClass->objectName().isEmpty())
            UserLoginClass->setObjectName("UserLoginClass");
        UserLoginClass->resize(434, 316);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserLoginClass->sizePolicy().hasHeightForWidth());
        UserLoginClass->setSizePolicy(sizePolicy);
        UserLoginClass->setMinimumSize(QSize(434, 316));
        UserLoginClass->setMaximumSize(QSize(434, 316));
        titleWidget = new QWidget(UserLoginClass);
        titleWidget->setObjectName("titleWidget");
        titleWidget->setGeometry(QRect(0, 0, 434, 104));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleWidget->sizePolicy().hasHeightForWidth());
        titleWidget->setSizePolicy(sizePolicy1);
        titleWidget->setMinimumSize(QSize(0, 104));
        titleWidget->setMaximumSize(QSize(16777215, 104));
        titleWidget->setProperty("titleskin", QVariant(false));
        bodyWidget = new QWidget(UserLoginClass);
        bodyWidget->setObjectName("bodyWidget");
        bodyWidget->setGeometry(QRect(0, 104, 428, 194));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bodyWidget->sizePolicy().hasHeightForWidth());
        bodyWidget->setSizePolicy(sizePolicy2);
        bodyWidget->setMinimumSize(QSize(200, 0));
        bodyWidget->setProperty("bottomskin", QVariant(false));
        verticalLayout = new QVBoxLayout(bodyWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 36, 0, 20);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        editUserAccount = new QLineEdit(bodyWidget);
        editUserAccount->setObjectName("editUserAccount");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(editUserAccount->sizePolicy().hasHeightForWidth());
        editUserAccount->setSizePolicy(sizePolicy3);
        editUserAccount->setMinimumSize(QSize(260, 26));
        editUserAccount->setMaximumSize(QSize(260, 26));
        editUserAccount->setMaxLength(33);

        horizontalLayout->addWidget(editUserAccount);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        editPassword = new QLineEdit(bodyWidget);
        editPassword->setObjectName("editPassword");
        editPassword->setMinimumSize(QSize(260, 26));
        editPassword->setMaximumSize(QSize(260, 26));
        editPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(editPassword);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(12);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_5 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        checkBox_2 = new QCheckBox(bodyWidget);
        checkBox_2->setObjectName("checkBox_2");
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);
        checkBox_2->setMinimumSize(QSize(164, 28));
        checkBox_2->setMaximumSize(QSize(164, 28));

        horizontalLayout_4->addWidget(checkBox_2);

        forgetWordBtn = new QPushButton(bodyWidget);
        forgetWordBtn->setObjectName("forgetWordBtn");
        sizePolicy.setHeightForWidth(forgetWordBtn->sizePolicy().hasHeightForWidth());
        forgetWordBtn->setSizePolicy(sizePolicy);
        forgetWordBtn->setMinimumSize(QSize(0, 28));
        forgetWordBtn->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_4->addWidget(forgetWordBtn);

        registBtn = new QPushButton(bodyWidget);
        registBtn->setObjectName("registBtn");
        sizePolicy.setHeightForWidth(registBtn->sizePolicy().hasHeightForWidth());
        registBtn->setSizePolicy(sizePolicy);
        registBtn->setMinimumSize(QSize(0, 28));
        registBtn->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_4->addWidget(registBtn);

        horizontalSpacer_6 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_7 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        loginBtn = new QPushButton(bodyWidget);
        loginBtn->setObjectName("loginBtn");
        sizePolicy.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy);
        loginBtn->setMinimumSize(QSize(260, 36));
        loginBtn->setMaximumSize(QSize(260, 36));

        horizontalLayout_3->addWidget(loginBtn);

        horizontalSpacer_8 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(UserLoginClass);

        QMetaObject::connectSlotsByName(UserLoginClass);
    } // setupUi

    void retranslateUi(QWidget *UserLoginClass)
    {
        UserLoginClass->setWindowTitle(QCoreApplication::translate("UserLoginClass", "UserLogin", nullptr));
        editUserAccount->setPlaceholderText(QCoreApplication::translate("UserLoginClass", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        editPassword->setPlaceholderText(QCoreApplication::translate("UserLoginClass", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        checkBox_2->setText(QCoreApplication::translate("UserLoginClass", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        forgetWordBtn->setText(QCoreApplication::translate("UserLoginClass", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        registBtn->setText(QCoreApplication::translate("UserLoginClass", "\346\263\250\345\206\214", nullptr));
        loginBtn->setText(QCoreApplication::translate("UserLoginClass", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserLoginClass: public Ui_UserLoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGIN_H
