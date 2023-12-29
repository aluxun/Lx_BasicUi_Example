#ifndef LX_NEWCHAT_H
#define LX_NEWCHAT_H

#include <QWidget>
#include<Lx_ChatView.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Lx_NewChat; }
QT_END_NAMESPACE

class Lx_NewChat : public QWidget
{
    Q_OBJECT

public:
    Lx_NewChat(QWidget *parent = nullptr);
    ~Lx_NewChat();

private slots:
    void File_onclicked(QString click_type,Lx_ChatUserData& data);

    void onDblClickImage(QImage image);

    void on_btn_emo1_clicked();

    void on_btn_emo2_clicked();

    void on_btn_emo3_clicked();

    void on_btn_send_clicked();

    void on_btn_emo4_clicked();

    void on_btn_emo5_clicked();




private:
    Ui::Lx_NewChat *ui;
    QMap<QString,QMovie*> total_map;


};
#endif // LX_NEWCHAT_H
