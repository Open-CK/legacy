/*
** lstrings.h
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

//!@file lstrings.h Functions to read localised strings.

#ifndef LSTRINGS_H
#define LSTRINGS_H

#include <QDataStream>
#include <QFile>

namespace io
{
    class LStringReader
    {
    public:
        QString lookupString(QString filename, quint32 index, quint32 recordType, quint32 subrecord);

    private:
        QString trimFileName(QString filename);
        QString getExtension(quint32 recordType, quint32 subrecord);
        QString getLanguage();
        QFile getStrTable(QString file, QString lang, QString ext);
    };
}

#endif //LSTRINGS_H
