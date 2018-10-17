#include "cfgparser.h"
#include "cgt.h"
#include "os_filesys.h"

string format_file(string f);

ConfigParser::~ConfigParser()
{
    while (!sectypes.empty())
    {
        delete *sectypes.rbegin();
        sectypes.pop_back();
    }
}

ConfigParser::ConfigParser(string file)
{
    string content = ol::file2str(file);
    content = format_file(content);

    ol::istr is(content);
    for (string name; is >> name; )
    {
        string w;
        is >> w;
        if ( w == "=" )
        {
            is >> w;
            if ( name == cfgNames::password ) password = w;
            else if ( name == cfgNames::sourceDir )
            {
                userdir = w;
                if ( w.find(';') == string::npos && !os::isDir(userdir) )
                    throw "invalid directory '" + userdir
                    + "' in the configuration file '" + file + "'";
            }
            else throw "Bad key in [" + file + "] : [" + name + "]";

        }
        else if ( w == ":" )
        {
            is >> w;
            SecType * typ = SecType::load(is, name, w);
            sectypes.push_back(typ);
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

void ConfigParser::makeSecint(std::string e3_lib) const
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

    ofh << head.str() << "// " << libsTFH() << "\n\n";
    ofi << head.str() << '\n';
    ofc << head.str() << '\n';

    ofh << ol::file2str(cfgNames::topH);
    ofi << ol::file2str(cfgNames::topInc);
    ofc << ol::file2str(cfgNames::topCpp);

    for ( const auto & x : sectypes )
    {
        x->writeH(ofh, userdir);
        x->writeInc(ofi);
        x->writeCpp(ofc);
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
        x->genKeys(forceGen, forceLoad, password);
        if (isCloPassword && x->isLoaded())
            cout << "WARNING: the key '" << x->getName() << "' already exists; ignoring option '" + nm::param_password + "' for this key\n";
    }
}

