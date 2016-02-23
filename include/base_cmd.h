#ifndef TORRENTSH_BASE_CMD_H_
#define TORRENTSH_BASE_CMD_H_

#include <boost/core/noncopyable.hpp>
#include <boost/program_options.hpp>
#include <string>
#include <vector>

namespace po = boost::program_options;

class BaseCmd : private boost::noncopyable {
private:
    bool opts_combined;  // Whether or not options has been combined into `all_opt_desc`
    po::options_description all_opt_desc;
protected:
    const std::string man, usage;
    po::options_description opt_desc;
    po::options_description hid_opt_desc;
    po::positional_options_description pos_opt_desc;
    po::variables_map var_map;
    BaseCmd(const std::string &man, const std::string &usage);

public:
    void Man();
    virtual int Run(const std::vector<std::string>&);
};

#endif
