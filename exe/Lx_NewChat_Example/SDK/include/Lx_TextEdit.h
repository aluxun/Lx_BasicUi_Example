#ifndef LX_TEXTEDIT_H
#define LX_TEXTEDIT_H

#include <QTextEdit>
#include <Lx_ChatUserData.h>


class Lx_TextEditPrivate;
class Lx_EXPORT Lx_TextEdit : public QTextEdit
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Lx_TextEdit);
    QSharedPointer<Lx_TextEditPrivate> d_ptr;
public:
    explicit Lx_TextEdit(QWidget *parent = nullptr);
    void addAnimation(QString path);
    void addEmoticon(QString path);
    QList<Lx_ChatUserData> getChatUserData();

public slots:
    void OnframeChanged(int frameNumber);
    void openSelectFlie(QString path);
protected:
    //resetlayout
    void relayout();
    QString toText();
    void stopAnimation();
    QString addImageResource(QString path);
protected:
    void keyPressEvent(QKeyEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *e) override;
    //处理gif复制粘贴问题  new新QMovie对象 非引用已有QMovie对象
    void insertFromMimeData(const QMimeData *source) override;

    void mouseMoveEvent(QMouseEvent *e) override;
    void dragEnterEvent(QDragEnterEvent *e) override;
    void dragMoveEvent(QDragMoveEvent *e) override;
    void dropEvent(QDropEvent *e) override;


};

#endif // LX_TEXTEDIT_H
