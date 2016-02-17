#ifndef TORRENTSH_TORRENT_H_
#define TORRENTSH_TORRENT_H_

#include <libtorrent/entry.hpp>
#include <libtorrent/bencode.hpp>
#include <libtorrent/torrent_info.hpp>
#include <libtorrent/lazy_entry.hpp>
#include <libtorrent/magnet_uri.hpp>

#include <boost/bind.hpp>
#include <string>


class Torrent {

    libtorrent::torrent_info *torrent;

public:
    Torrent(std::string const& filename);
    ~Torrent();

    void print_info();
};

#endif