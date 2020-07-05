#ifndef VIEWDIR_H
#define VIEWDIR_H
#include <QString>


//========================================================
// maindir - путь к главной папке с файлами
// tempfile - путь к файлу с путями файлов в главной папке
//========================================================

class viewdir
{
    QString m_sMainDir, m_sTempFile;

private:
    void view(QString strPath, QString strTemp);

public:
    viewdir(QString maindir, QString tempfile);
    void vdir();

};

#endif // VIEWDIR_H
