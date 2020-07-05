#include <QCoreApplication>
#include <QDir>
#include <QString>
#include "viewdir.h"
#include "filecopy.h"
#include "filedelete.h"

const QString MAINDIR = "C:\\maindir"; // Папка maindir, в которую кладутся файлы
const QString PUTDIR = "C:\\putdir";   // Папка putdir, в которую перемещаются файлы
const QString TEMPFILE = "C:\\temp.txt"; // Файл temp.txt, в который записывается слово "yes", если 3 файла найдено

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir dirExists(MAINDIR);
     if (!dirExists.exists()) // Проверяем, существует ли уже такая папка.
       {
         dirExists.mkdir(MAINDIR); // Если не существует - создаем.
       }
    viewdir vDir(MAINDIR, TEMPFILE); // Смотрим maindir, определяем кол-во файлов
    vDir.vdir();
    filecopy fcopy (TEMPFILE, MAINDIR, PUTDIR); // Копируем из maindir в putdir
    fcopy.fcopy();
    filedelete fDel(MAINDIR, TEMPFILE); // Удаляем все из maidir
    fDel.filedel();

    return a.exec();
}
