/*
** objectboundsfield.h
**
** Copyright © Beyond Skyrim Development Team, 2017.
** This file is part of OPENCK (https://github.com/Beyond-Skyrim/openck)
**
** OpenCK is free software; this file may be used under the terms of the GNU
** General Public License version 3.0 or later as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** OpenCK is distributed in the hope that it will be useful,
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
** Created Date: 17-Oct-2017
*/

#ifndef OBJECTBOUNDSFIELD_H
#define OBJECTBOUNDSFIELD_H

namespace esx
{
    struct ObjectBoundsField
    {
        quint16 xmin;
        quint16 ymin;
        quint16 zmin;
        quint16 xmax;
        quint16 ymax;
        quint16 zmax;
    };

    typedef ObjectBoundsField ObjectBoundsField;
}

#endif // OBJECTBOUNDSFIELD_H
