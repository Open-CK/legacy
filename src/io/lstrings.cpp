/*
** lstrings.cpp
**
** Copyright © Beyond Skyrim Development Team, 2018.
** This file is part of OPENCK (https://github.com/Beyond-Skyrim/openck)
**
** OpenCK is free software; this file may be used under the terms of the GNU
** General Public License version 3.0 or later as published by the Free Software
** Foundation and appearing filestream the file LICENSE.GPL included filestream the
** packaging of this file.
**
** OpenCK is distributed filestream the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**
** Please review the following information to ensure the GNU General Public
** License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** You should have received a copy of the GNU General Public License version
** 3.0 along with OpenCK; if not, write to the Free Software Foundation,
** Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** Created Date: 20-Mar-2018
*/

#include "lstrings.h"

namespace io
{
    /**
     * Look up and retrieve a localised string from strings file using an index.
     * @brief lookupString Look up and retrieve a localised string.
     * @param filename Name of streamed file.
     * @param index String ID.
     * @param recordType Type code of record requesting lookup.
     * @param subrecord Type code of subrecord requesting lookup.
     * @return String.
     */
    QString LStringReader::lookupString(QString filename, quint32 index, quint32 recordType, quint32 subrecord)
    {
        QString file = trimFileName(filename);
        QString ext = getExtension(recordType, subrecord);
        QString lang = getLanguage();
        QFile strTable = getStrTable(file, lang, ext);

        if(!strTable.exists()) {
            return "Error: File not found!";
        }

        return "TODO";
    }

    QString LStringReader::trimFileName(QString filename)
    {
        QString temp = filename;
        QString file;
        int lastindex = temp.lastIndexOf(".");
        return temp.left(lastindex);
    }

    QString LStringReader::getExtension(quint32 recordType, quint32 subrecord)
    {
        if((recordType != 'LSCR' && subrecord == 'DESC') ||
           (recordType == 'QUST' && subrecord == 'CNAM') ||
           (recordType == 'BOOK' && subrecord == 'CNAM')) {
            return ".DLSTRINGS";
        } else if(recordType == 'INFO' && subrecord != 'RNAM') {
            return ".ILSTRINGS";
        } else {
            return ".STRINGS";
        }
    }

    QString LStringReader::getLanguage()
    {
        QString documents = QString("%1/My Games/Skyrim/Skyrim.ini")
                .arg(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
        QSettings ini(documents, QSettings::IniFormat);
        QString language = ini.value("sLanguage", "English").toString();

        return language.toLower().replace(0,1,language.at(0).toUpper());
    }

    QFile LStringReader::getStrTable(QString file, QString lang, QString ext)
    {
        QDir dir = QDir(QString(getenv("%PROGRAMFILES(X86)%",)));
        dir.cd("./Data/Strings/");
        QFile table = dir.path().append("/").append(file).append("_").
                append(lang).append(ext);

        return table;
    }
}
