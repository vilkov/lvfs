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

#ifndef LVFS_DEFAULT_DIRECTORY_H_
#define LVFS_DEFAULT_DIRECTORY_H_

#include "lvfs_default_DefaultFile.h"


namespace LVFS {

class PLATFORM_MAKE_PRIVATE Directory : public Implements<IEntry, IDirectory, IFsFile>
{
public:
    Directory(const char *fileName);
    Directory(const char *fileName, const struct stat &st);
    virtual ~Directory();

    /* IEntry */

    virtual const char *title() const;
    virtual const char *schema() const;
    virtual const char *location() const;
    virtual const IType *type() const;

    /* IDirectory */

    virtual const_iterator begin() const;
    virtual const_iterator end() const;
    virtual Interface::Holder entry(const char *name) const;

    virtual bool rename(const Interface::Holder &file, const char *name);
    virtual bool remove(const Interface::Holder &file);

    virtual const Error &lastError() const;

    /* IFsFile */

    virtual time_t cTime() const;
    virtual time_t mTime() const;
    virtual time_t aTime() const;

    virtual int permissions() const;
    virtual bool setPermissions(int value);

private:
    DefaultFile m_file;
};

}

#endif /* LVFS_DEFAULT_DIRECTORY_H_ */
