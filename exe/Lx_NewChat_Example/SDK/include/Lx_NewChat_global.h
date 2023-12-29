#ifndef LX_NEWCHAT_GLOBAL_H
#define LX_NEWCHAT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NewChat_LIBRARY)
#  define Lx_EXPORT Q_DECL_EXPORT
#else
#  define Lx_EXPORT
#endif

#endif // LX_NEWCHAT_GLOBAL_H
