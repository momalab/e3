// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_OS_FILESYS_H_
#define _E3_OS_FILESYS_H_

#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;
using std::string;

namespace gl
{

typedef unsigned long ulong;
typedef unsigned short ushort;
typedef signed long long intint;
}// gl

namespace os
{

struct Dir
{
    typedef std::vector<string> vs;
    typedef std::vector< std::pair<string, gl::intint> > vpsii;
    vs dirs;
    vpsii files;
};


Dir readDir(fs::path d);
Dir readDirEx(fs::path d, bool dsort, bool fsort);
string execOut(const string & cmd, bool iscurdir); // iscurdir adds "./" in unx

} // os


#endif // _E3_OS_FILESYS_H_
