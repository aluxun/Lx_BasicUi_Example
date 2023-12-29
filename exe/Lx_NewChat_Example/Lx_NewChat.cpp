#include "Lx_NewChat.h"
#include "ui_Lx_NewChat.h"



QString formatFileSize(qint64 size);
#include <QRandomGenerator>
#include <QDebug>
#include <QFileIconProvider>
#include <QDateTime>
#include <QMessageBox>
#include <QDesktopServices>
#include <QLabel>
#include <QMovie>

Lx_NewChat::Lx_NewChat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Lx_NewChat)
{
    ui->setupUi(this);

    ui->listView->setIndenicon("left",QPixmap(":/image/pic/left_photo.jpg"));
    ui->listView->setIndenicon("right",QPixmap(":/image/pic/right_photo.jpg"));

    //如果使用动态库方式的话
    //Lx_ChatView类的信号连接方式修改成qt4语法的方式或者Lx_ChatView头文件(.h)加入当前工程
    //https://forum.qt.io/topic/102783/qobject-connect-signal-not-found-in-dll-with-pointer-to-member-function?_=1703834577398&lang=zh-CN
    //connect(ui->listView,SIGNAL(fileClicked(QString ,Lx_ChatUserData&)),this,SLOT(File_onclicked(QString ,Lx_ChatUserData&)));
    connect(ui->listView,&Lx_ChatView::fileClicked,this,&Lx_NewChat::File_onclicked);
    connect(ui->listView,&Lx_ChatView::dblClickImage,this,&Lx_NewChat::onDblClickImage);
    connect(ui->listView,&Lx_ChatView::linkClicked,[&](QString link){
         QDesktopServices::openUrl(QUrl(link));
    });
    connect(ui->listView,&Lx_ChatView::photoClicked,[&](int row,Lx_ChatUserData& data){
        QMessageBox box;
        box.setText(QString("点击第%1行 item的头像部分").arg(row));
        box.exec();
    });
}

Lx_NewChat::~Lx_NewChat()
{
    delete ui;
}

void Lx_NewChat::File_onclicked(QString click_type, Lx_ChatUserData &data)
{
    QMessageBox box;
    box.setText(click_type+":"+data.toChatFileData().FileName());
    box.exec();
}

void Lx_NewChat::onDblClickImage(QImage image)
{
    QLabel* label=new QLabel;
    label->setAttribute(Qt::WA_DeleteOnClose);
    QPixmap pix=QPixmap::fromImage(image);

    label->resize(pix.size());
    label->setPixmap(pix);

    label->setScaledContents(true);
    label->setWindowTitle("NewChat-查看原图");
    label->show();
}

void Lx_NewChat::on_btn_emo1_clicked()
{
    QString src=":/image/pic/ico_emoji1.png";
    ui->textEdit->addEmoticon(src);
}


void Lx_NewChat::on_btn_emo2_clicked()
{
    QString src=":/image/pic/ico_emoji2.png";
    ui->textEdit->addEmoticon(src);
}

void Lx_NewChat::on_btn_emo3_clicked()
{
    QString src=":/image/pic/ico_emoji3.png";
    ui->textEdit->addEmoticon(src);
}

void Lx_NewChat::on_btn_send_clicked()
{




    auto text = ui->textEdit->toHtml();
    if(text.isEmpty())
        return ;




    static bool init=true;
    static int sum=0;


    if(init){

        QString text=QString("引进智能设备降粮食田间损耗率加低粮食田间损耗率加强减损宣传这是一组引人深思的数据"
                              "据联合国粮农组织统计每年全球粮食从生");/*产到零售全环节损失约占世界粮食产最大程度消除"
                              "影响机收损失的主观因素推出小份菜鼓励光盘减少粮食浪费……这是一组引人深思的数据——据"
                              "—据联合国粮农组织统计每年全球粮食从生到零售全环节损失约占世界粮组织统计每年全球粮食从生产到"
                              "零售全环节损失约占世界食产量的14%这个损失降低1个百分点就相当于增产2700多万吨粮食够7000万人吃一年");*/
       int type=0;
       for (int i=0;i<500;i++) {



           int pos=QRandomGenerator::global()->bounded(0, text.length()/2);
           int len=QRandomGenerator::global()->bounded(pos, text.length()-pos);

           type=QRandomGenerator::global()->bounded(0,49);


           if(i==499){
               Lx_ChatTextData userdata;
               userdata.setChatAlignment(Lx_ChatUserData::User_Left);
               userdata.setText("https://www.baidu.com/");
               userdata.setIconIndex("left");
               ui->listView->appendRow(userdata);
               continue;
           }



           if(type%5==0){
              Lx_ChatTextData TextData;
              TextData.setChatAlignment(Lx_ChatUserData::User_Left);
              TextData.setIconIndex("left");
              TextData.setText(text.mid(pos,len));
              ui->listView->appendRow(TextData);
           }else if(type%5==1){
              Lx_ChatFileData FileData;
              FileData.setChatAlignment(Lx_ChatUserData::User_Left);
              FileData.setIconIndex("left");
              FileData.setFileIcon(QImage(":/image/pic/File.png"));
              FileData.setFileName("Lx_MainBasic.cpp");
              FileData.setFileSize(85245);
              FileData.setDescr("成功发送离线文件,文件助手缓存7天");
              ui->listView->appendRow(FileData);

           }else if(type%5==2){
              Lx_ChatTextData TextData;
              TextData.setChatAlignment(Lx_ChatUserData::User_Right);
              TextData.setIconIndex("right");
              TextData.setText(text.mid(pos,len));
              ui->listView->appendRow(TextData);
           }else if(type%5==3){

              Lx_ChatFileData FileData;
              FileData.setChatAlignment(Lx_ChatUserData::User_Right);
               FileData.setIconIndex("right");
              FileData.setFileIcon(QImage(":/image/pic/File.png"));
              FileData.setFileName("Lx_MainBasic.cpp");
              FileData.setFileSize(85245);
              FileData.setDescr("成功发送离线文件,文件助手缓存7天");
              ui->listView->appendRow(FileData);
           }else{
              Lx_ChatTimeData TimeData;
              QString time=QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
              TimeData.setTime(time);
              ui->listView->appendRow(TimeData);
           }




       }

       init=!init;
       sum=500;
    }else{
        sum++;
      QList<Lx_ChatUserData> list=ui->textEdit->getChatUserData();
      foreach (auto var, list) {
          if(var.ChatType()==Lx_ChatUserData::User_Text){

              var.setChatAlignment(sum%3==0? Lx_ChatUserData::User_Left:Lx_ChatUserData::User_Right);

//            Lx_ChatTextData data=  Lx_ChatUserData::FromStream(Lx_ChatUserData::Stream(var)).toChatTextData();
//            data.setText("++"+data.Text());
//            data.setIconIndex("right");
//            ui->listView->appendRow(data);

          }else{

             var.toChatFileData().setDescr("成功发送离线文件,文件助手缓存7天");
          }
          var.setIconIndex(var.ChatAlignment()==Lx_ChatUserData::User_Right?"right":"left");
          ui->listView->appendRow(var);
      }

    }



}

void Lx_NewChat::on_btn_emo4_clicked()
{

    ui->textEdit->addAnimation(":/image/pic/1.gif");
}

void Lx_NewChat::on_btn_emo5_clicked()
{

    ui->textEdit->addAnimation(":/image/pic/2.gif");
}

