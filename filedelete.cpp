#include "filedelete.h"
#include <QString>
#include <QDir>
#include <QFile>

// Функция удаления из maindir
void filedelete::fdel(QString strMainDir, QString strTempFile)
{
    QDir dirDel(strMainDir);
    QFile delFile(strTempFile);
     foreach (QString dirItem, dirDel.entryList())
         dirDel.remove(dirItem);
     delFile.remove(strTempFile);
}


filedelete::filedelete(QString maindir, QString tempfile)
{
    m_sMainDir = maindir;
    m_sTempFile = tempfile;
}


void filedelete::filedel()
{
    fdel(m_sMainDir, m_sTempFile);
}
