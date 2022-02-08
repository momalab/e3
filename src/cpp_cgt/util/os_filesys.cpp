// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include <stdio.h>
#include <algorithm>
#include "os_filesys.h"


os::Dir os::readDirEx(fs::path d, bool dsort, bool fsort)
{
    if ( !dsort && !fsort ) return readDir(d);

    Dir r = readDir(d);

    if (dsort) std::sort( r.dirs.begin(), r.dirs.end() );
    if (fsort) std::sort( r.files.begin(), r.files.end() );

    return r;
}


os::Dir os::readDir(fs::path d)
{
    os::Dir r;

    auto dir = fs::directory_iterator(d);

    for( const auto & de : dir )
    {
        std::string nm = de.path().filename().string();

        if ( nm == "." || nm == ".." ) continue;

        string fnm = (d / nm).string();

        ///if ( -1 == stat(fnm.c_str(), &st) ) continue;
		bool isdir = de.is_directory();
		bool isfil = de.is_regular_file();


        if ( isdir )
            r.dirs.push_back(nm);
        else if ( isfil )
		{
	        gl::intint sz =  (gl::intint)de.file_size();
            r.files.push_back(std::pair<string, gl::intint>(nm, sz));
		}
    }

    return r;
}

string os::execOut(const string & acmd, bool iscurdir)
{
#ifdef _MSC_VER
#define popen _popen
#define pclose _pclose
#endif
    string cmd = ( iscurdir ? "./" : "" ) + acmd;

    FILE * pp = ::popen(cmd.c_str(), "r");

    char   psBuffer[4];
    string r;

    if ( pp == NULL )
        throw "Cannot popen [" + cmd + "]";

    while (fgets(psBuffer, 3, pp))
    {
        r += psBuffer;
    }

    if (!feof( pp))
    {
        printf( "Error: Failed to read the pipe to the end.\n");
        ::pclose( pp );
        throw "Error in pipe [" + cmd + "]";
    }
    ::pclose( pp );
    return r;
}
