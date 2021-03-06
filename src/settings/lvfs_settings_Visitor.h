/**
 * This file is part of lvfs.
 *
 * Copyright (C) 2011-2015 Dmitriy Vilkov, <dav.daemon@gmail.com>
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

#ifndef LVFS_SETTINGS_VISITOR_H_
#define LVFS_SETTINGS_VISITOR_H_

#include <platform/utils.h>


namespace LVFS {
namespace Settings {

class List;
class Scope;
class IntOption;
class StringOption;


class PLATFORM_MAKE_PUBLIC Visitor
{
public:
    virtual ~Visitor();

    virtual void visit(List &option);
    virtual void visit(Scope &option);
    virtual void visit(IntOption &option) = 0;
    virtual void visit(StringOption &option) = 0;
};

}}

#endif /* LVFS_SETTINGS_VISITOR_H_ */
