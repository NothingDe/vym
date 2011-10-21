#ifndef VERSION_H 
#define VERSION_H

#include <QString>

#define __VYM_NAME "VYM"
#define __VYM_VERSION "2.0.2"
#define __VYM_CODENAME "Codename: Production release"
//#define __VYM_CODENAME "Codename: development version, not for production!"
#define __VYM_BUILD_DATE "2011-10-21"


bool checkVersion(const QString &);
bool checkVersion(const QString &, const QString &);

#endif
