#include "viewdir.h"
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QByteArray>
#include <QDebug>

//==================================================

// Функция наблюдает за папкой C:/maindir, в случае
// появления в ней 3х файлов, создается temp.txt
// с абсолютными путями к этим файлам.
void viewdir::view(QString strPath, QString strTemp)
{
    QDir dirView(strPath);
    QFile tempFile(strTemp);
    dirView.setFilter(QDir::Files | QDir::NoDotAndDotDot);
    int numfiles = dirView.count(); // Получаем к-во файлов в maindir
     if (numfiles == 3) // temp.txt со словом yes создается если в maindir только 3 файла.
       {
           if (tempFile.open(QIODevice::WriteOnly))
               {
                  tempFile.write("yes");
                  tempFile.close();
               }
       }
}


viewdir::viewdir(QString maindir, QString tempfile)
{
    m_sMainDir = maindir;   // Здесь путь к главной папке maindir с файлами
    m_sTempFile = tempfile; // Здесь путь к темпфайлу temp.txt, куда записываются пути к 3 файлам
}


// Функция вызывает void viewdir::view..
void viewdir::vdir()
{
     view(m_sMainDir, m_sTempFile);
}





