#ifndef LX_CHATUSERDATA_H
#define LX_CHATUSERDATA_H

#include <QMovie>
#include <Lx_NewChat_global.h>

class Lx_ChatUserDataPrivate;
struct Lx_ChatTextData;
struct Lx_ChatFileData;
struct Lx_ChatTimeData;

struct Lx_EXPORT Lx_ChatUserData
{
    enum User_Type{
        User_Invalid,
        User_System,//系统
        User_Text,    //自己
        User_Time,  //时间
        User_File,

    };

    enum User_Alignment{
        User_Left=Qt::AlignLeft,
        User_Right=Qt::AlignRight,
        User_HCenter=Qt::AlignHCenter
    };

public:
    Lx_ChatUserData();

    void setChatAlignment(User_Alignment alignment);
    User_Type ChatType();
    User_Alignment ChatAlignment();
    void setIconIndex(const QString& IconIndex);
    QString IconIndex();

    bool isChatTextData();
    bool isChatFileData();
    bool isChatTimeData();

    Lx_ChatTextData toChatTextData();
    Lx_ChatFileData toChatFileData();
    Lx_ChatTimeData toChatTimeData();
    //支持数据库存储Stream返回值 存入数据库
    static QByteArray Stream(Lx_ChatUserData& data);
    //FromStream从数据库读取构造一个Lx_ChatUserData对象
    static Lx_ChatUserData FromStream(QByteArray data);

    friend QDataStream& operator<<(QDataStream& stream, const Lx_ChatUserData& obj);
    friend QDataStream& operator>>(QDataStream& stream, const Lx_ChatUserData& obj);



protected:
    Q_DECLARE_PRIVATE(Lx_ChatUserData);
    QSharedPointer<Lx_ChatUserDataPrivate> d_ptr;
};

struct Lx_EXPORT Lx_ChatTextData:public Lx_ChatUserData{

public:
    Lx_ChatTextData();

    void setText(const QString& Text);
    QString Text();
    void insertMovie(const QString& index,QMovie* movie);
    void insertPicture(const QString& index,const QImage& image);
    void insertMemoryPicture(const QString& index,const QImage& image);
    QHash<QString,QMovie*>Movie();
    QHash<QString,QImage> Picture();
    QHash<QString,QImage> MemoryPicture();

    //类型转换运算符 if(Lx_ChatTextData对象)
   // operator bool()
   // operator Lx_ChatUserData();
    //友元
   // friend Lx_ChatUserData;
};

struct Lx_EXPORT Lx_ChatFileData:public Lx_ChatUserData{
public:
    Lx_ChatFileData();

    void setFileName(const QString& name);
    void setFileSize(int size);
    void setFileIcon(const QImage& icon);
    void setDescr(const QString& descr);

    QString FileName();
    int FileSize();
    QImage FileIcon();
    QString Sizeformat();
    QString Descr();

};

struct Lx_EXPORT Lx_ChatTimeData:public Lx_ChatUserData{
public:
    Lx_ChatTimeData();
    void setTime(const QString& time);
    QString Time();

};


Q_DECLARE_METATYPE(Lx_ChatUserData)

#endif // LX_CHATUSERDATA_H
