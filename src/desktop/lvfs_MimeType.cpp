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

#include "lvfs_MimeType.h"

#include <cstring>
#include <cstdlib>


namespace LVFS {

MimeType::MimeType(const char *name, const char *description) :
    m_name(::strdup(name)),
    m_description(::strdup(description))
{}

MimeType::MimeType(const char *name, const char *description, const Interface::Holder &icon) :
    m_name(::strdup(name)),
    m_description(::strdup(description)),
    m_icon(icon)
{}

MimeType::~MimeType()
{
    ::free(m_name);
    ::free(m_description);
}

const char *MimeType::name() const
{
    return m_name;
}

Interface::Holder MimeType::icon() const
{
    return m_icon;
}

const char *MimeType::description() const
{
    return m_description;
}

}
