/**
 * This file is part of lvfs.
 *
 * Copyright (C) 2011-2014 Dmitriy Vilkov, <dav.daemon@gmail.com>
 *
 * lvfs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * lvfs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with lvfs. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LVFS_DESKTOP_H_
#define LVFS_DESKTOP_H_

#include <platform/utils.h>
#include <lvfs/Interface>
#include <lvfs/Error>


namespace LVFS {

class IType;
class IFile;


class PLATFORM_MAKE_PUBLIC Desktop
{
public:
    enum IconType
    {
        OnlyAppIcon,
        OnlyTypeIcon,
        AppIconIfNoTypeIcon
    };

    enum IconSize
    {
        SmallIcon = 16
    };

    class Locale
    {
    public:
        Locale();

        const char *lang() const { return m_lang; }
        const char *country() const { return m_country; }
        const char *encoding() const { return m_encoding; }
        const char *modifier() const { return m_modifier; }

    private:
        enum { MaxLenghtOfLocale = 24 };

    private:
        const char *m_lang;
        const char *m_country;
        const char *m_encoding;
        const char *m_modifier;
        char m_buffer[MaxLenghtOfLocale];
    };

public:
    Desktop();
    ~Desktop();

    const Locale &locale() const { return m_locale; }
    Interface::Holder applications(const IType *type) const;
    Interface::Holder typeOfFile(IFile *file, const char *fileName, IconType iconType = AppIconIfNoTypeIcon) const;
    Interface::Holder typeOfDirectory() const;

    const Error &lastError() const { return m_lastError; }

private:
    Locale m_locale;
    Error m_lastError;
};

}

#endif /* LVFS_DESKTOP_H_ */
