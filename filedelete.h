#ifndef FILEDELETE_H
#define FILEDELETE_H
#include <QString>


class filedelete
{
    QString m_sMainDir, m_sTempFile;

private:
    void fdel(QString strMainDir, QString strTempFile);

public:
    filedelete(QString maindir, QString tempfile);
    void filedel();

};

#endif // FILEDELETE_H
