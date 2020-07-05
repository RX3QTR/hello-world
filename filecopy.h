#ifndef FILECOPY_H
#define FILECOPY_H
#include <QString>


class filecopy
{
    QString m_readtempfile, m_getfiles, m_putfiles;

private:
    void copy(QString strReadTempFile, QString strGetFiles, QString strPutFiles);

public:
    filecopy(QString readtempfile, QString getfiles, QString putfiles);
    void fcopy();

};

#endif // FILECOPY_H
