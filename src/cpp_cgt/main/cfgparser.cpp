// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <filesystem>

#include "cfgparser.h"
#include "cgt.h"
#include "os_filesys.h"
#include "cgtutil.h"

namespace fs = std::filesystem;
using namespace e3::cr;

using std::cout;

string format_file(string f);

ConfigParser::~ConfigParser()
{
    while (!sectypes.empty())
    {
        delete *sectypes.rbegin();
        sectypes.pop_back();
    }
}

ConfigParser::ConfigParser(string f) : file(f)
{
    string content = ol::file2str(file);
    try
    {
        content = format_file(content);

        std::map<string, string> globs;

        ol::istr is(content);
        for (string name; is >> name; )
        {
            string w;
            is >> w;
            if ( w == "=" )
            {
                w = e3::util::readVal(is);

                if (0) {}

                else if ( name == cfgNames::password ) password = w;

                else if ( name == cfgNames::maxinline ) maxconst = w;

                else if ( name == cfgNames::sourceDir )
                {
                    userdir = w;
                    ///if ( w.find(';') == string::npos && !os::isDir(userdir) )
                    if ( w.find(';') == string::npos && !fs::is_directory(userdir) )
                        throw "invalid directory '" + userdir
                        + "' in the configuration file '" + file + "'";
                }

                else if (name.size() > 1 && name[0] == '@') globs[name.substr(1)] = w;

                else throw "(l:57) Bad key in [" + file + "] : [" + name + "]";

            }
            else if ( w == ":" )
            {
                is >> w;
                SecType * typ = SecType::load(is, name, w, globs);
                sectypes.push_back(typ);
                if ( !maxconst.empty() ) typ->setMaxConst(std::stoi(maxconst));
            }
            else throw "Expecting ':' or '=' after [" + name
                + "], but got [" + w + "]";
        }

        std::set<string> postfixes;
        for ( auto st : sectypes )
        {
            st->checkPostfixes(postfixes);
        }

    }
    catch (...)
    {
        std::cout << "Error while parsing file: [" + file + "]\n";
        throw;
    }
}


string format_file(string f)
{
    ol::replaceAll(f, "\r", ""); // remove \r

    string r;

    // remove comments
    bool is_comm_line = false, is_comm_block = false;
    for ( size_t i = 0; i < f.size(); i++ )
    {
        auto c = f[i];
        if ( is_comm_line )
        {
            if ( c != '\n' ) continue;
            is_comm_line = false;
        }

        if ( is_comm_block )
        {
            if ( c != '#' || f[i - 1] != '!' ) continue;
            is_comm_block = false;
            continue;
        }

        if ( c == '#' )
        {
            if ( (i + 1) < f.size() && f[i + 1] == '!' ) is_comm_block = true;
            else is_comm_line = true;
            continue;
        }

        r += c;
    }

    // put spaces around {}=:
    f = "";
    for ( size_t i = 0; i < r.size(); i++ )
    {
        char c = r[i];

        if ( c == '{' || c == '}' || c == '=' || c == ':' )
            f += string(" ") + c + ' ';
        else f += c;
    }

    return f;
}

void ConfigParser::makeSecint(string cgtdir, std::string e3_lib) const
{
    std::string lib_h = e3_lib + ".h";
    std::string lib_inc = e3_lib + ".inc";
    std::string lib_cpp = e3_lib + ".cpp";

    std::ofstream ofh(lib_h, std::ios::binary);
    std::ofstream ofi(lib_inc, std::ios::binary);
    std::ofstream ofc(lib_cpp, std::ios::binary);

    auto tim = std::time(0);
    ol::ostr head;
    head << "// " << nm::logo << "\n// cgt build id: " << tim << "\n";

    ofi << head.str() << '\n';
    ofc << head.str() << '\n';
    ofh << head.str() << "// " << libsTFH() << "\n";
    ofh << "// Config: " << file << '\n';
    ofh << "// Classes:";
    for ( const auto & x : sectypes )
        ofh << " " << x->getTypName();
    ofh << "\n\n";

    if (!cgtdir.empty() && cgtdir[cgtdir.size() - 1] != '/' ) cgtdir += "/";
    ofh << ol::file2str(cgtdir + cfgNames::topH);
    ofi << ol::file2str(cgtdir + cfgNames::topInc);
    ofc << ol::file2str(cgtdir + cfgNames::topCpp);

    // output types, but first non-bridges
    for ( const auto & x : sectypes )
    {
        if ( x->getBridge() ) continue;
        x->writeH(cgtdir, ofh, userdir);
        x->writeInc(cgtdir, ofi);
        x->writeCpp(cgtdir, ofc);
    }

    for ( const auto & x : sectypes )
    {
        if ( !x->getBridge() ) continue;
        x->writeH(cgtdir, ofh, userdir);
        x->writeInc(cgtdir, ofi);
        x->writeCpp(cgtdir, ofc);
    }
}

void ConfigParser::makeDepend() const
{
    for ( const auto & x : sectypes )
    {
        x->copyDependencies();
    }
}

void ConfigParser::loadOrGenKeys(bool forceGen, bool forceLoad)
{
    for ( const auto & x : sectypes )
    {
        x->genKeys(forceGen, forceLoad, password, this);
        if (isCloPassword && x->isLoaded())
            cout << "WARNING: the key '" << x->getTypName() << "' already exists; ignoring option '" + nm::param_password + "' for this key\n";
    }
}

Bridge * ConfigParser::getBridge(string name) const
{
    for ( auto x : sectypes )
    {
        if ( !x->getBridge() ) continue;
        if ( x->getTypName() == name ) return x->getBridge();
    }
    return nullptr;
}

void ConfigParser::saveConsts() const
{
    for ( const auto & x : sectypes )
        x->saveConsts();
}

