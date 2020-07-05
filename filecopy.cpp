#include "filecopy.h"
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QDebug>

// Функция копирования (перемещения) из папки в папку
void filecopy::copy(QString strReadTempFile, QString strGetFiles, QString strPutFiles)
{
    QFile readTmpFile(strReadTempFile);
    QString strTmpFile;
     if ((readTmpFile.exists())&&(readTmpFile.open(QIODevice::ReadOnly)))
       {
         strTmpFile = readTmpFile.readAll(); // Смотрим temp.txt
         readTmpFile.close();
       }
     if (strTmpFile == "yes")
       {
         QDateTime dt = QDateTime::currentDateTime(); // Получаем тек. дату-время
         QString strFormat = "dddd_d_MMMM_yy_hh_mm_ss"; // Присваиваем формат
         QString strSetDateTime = dt.toString(strFormat);
         QString strOutDir = strPutFiles + "_" + strSetDateTime; // Создаем putdir_ с присвоенным форматом
         QDir dirCopy(strGetFiles);
         dirCopy.mkdir(strOutDir);
         QStringList files = dirCopy.entryList(QDir::Files);
          for(int i = 0; i < files.count(); i++)
             {
               QString strSource = strGetFiles + "\\" + files[i];
               QString strDestination = strOutDir + "\\" + files[i];
               QFile::copy(strSource, strDestination);
             }
       }
}


filecopy::filecopy(QString readtempfile, QString getfiles, QString putfiles)
{
    m_readtempfile = readtempfile;
    m_getfiles = getfiles;
    m_putfiles = putfiles;
}


void filecopy::fcopy()
{
    copy(m_readtempfile, m_getfiles, m_putfiles);
}
