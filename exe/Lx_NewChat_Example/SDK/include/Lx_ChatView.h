#ifndef LX_CHATVIEW_H
#define LX_CHATVIEW_H

#include <QListView>
#include <QBasicTimer>
#include <Lx_ChatUserData.h>

class Lx_ChatViewPrivate;
class Lx_EXPORT Lx_ChatView : public QListView
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Lx_ChatView);
    QSharedPointer<Lx_ChatViewPrivate> d_ptr;
signals:
    void photoClicked(int row,Lx_ChatUserData& data);
    void fileClicked(QString click_type,Lx_ChatUserData& data);
    void dblClickImage(QImage image) ;
    void linkClicked(QString link);
public:
    explicit Lx_ChatView(QWidget *parent = nullptr);
    //只做添加删除 不做插入
    bool appendRow(Lx_ChatUserData& data);
    bool insertRow(int row,Lx_ChatUserData& data);
    bool updataRow(int row,Lx_ChatUserData& data);
    bool removeRows(int row);
    int  itemCount();
    //设置图标索引 icon为空会移除索引 如果index已存在则替换成新的icon 不存在则添加
    void setIndenicon(QString index,QPixmap icon);
    //获取图标
    QPixmap Indenicon(QString index);
    Lx_ChatUserData item(int row);

    QBasicTimer& autoTimer()const;
    QBasicTimer& updateTimer()const;

protected:
   void contextMenuEvent(QContextMenuEvent *e);
   void mouseMoveEvent(QMouseEvent *e);
   void mouseReleaseEvent(QMouseEvent *e);
   void wheelEvent(QWheelEvent *e);
   void timerEvent(QTimerEvent *e) ;

   //  void scrollTo(const QModelIndex &index, QAbstractItemView::ScrollHint hint = EnsureVisible);
   //  void scrollContentsBy(int dx, int dy);

};


#endif // LX_CHATVIEW_H
