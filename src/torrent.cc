#include "torrent.h"

Torrent::Torrent(std::string const& filename) {
    torrent = new libtorrent::torrent_info(filename);
}

Torrent::~Torrent() {
    delete torrent;
}

void Torrent::print_info() {
    // print info about torrent
    printf("\n\n----- torrent file info -----\n\n"
        "nodes:\n");

    typedef std::vector<std::pair<std::string, int> > node_vec;
    node_vec const& nodes = torrent->nodes();
    for (node_vec::const_iterator i = nodes.begin(), end(nodes.end());
        i != end; ++i)
    {
        printf("%s: %d\n", i->first.c_str(), i->second);
    }
    puts("trackers:\n");
    for (std::vector<libtorrent::announce_entry>::const_iterator i = torrent->trackers().begin();
        i != torrent->trackers().end(); ++i)
    {
        printf("%2d: %s\n", i->tier, i->url.c_str());
    }

    char ih[41];
    libtorrent::to_hex((char const*)&torrent->info_hash()[0], 20, ih);
    std::cout << "number of pieces: " << torrent->num_pieces() << std::endl
    << "piece length: " << torrent->piece_length() << std::endl
    << "info hash: " << ih << std::endl
    << "comment: " << torrent->comment().c_str() << std::endl
    << "created by: " << torrent->creator().c_str() << std::endl
    << "name: " << torrent->name().c_str() << std::endl
    << "number of files: " << torrent->num_files() << std::endl
    << "files: " << std::endl;
    libtorrent::file_storage const& st = torrent->files();
    for (int i = 0; i < st.num_files(); ++i)
    {
        int first = st.map_file(i, 0, 0).piece;
        int last = st.map_file(i, (std::max)(libtorrent::size_type(st.file_size(i))-1, libtorrent::size_type(0)), 0).piece;
        int flags = st.file_flags(i);
        printf(" %8" PRIx64 " %11" PRId64 " %c%c%c%c [ %5d, %5d ] %7u %s %s %s%s\n"
            , st.file_offset(i)
            , st.file_size(i)
            , ((flags & libtorrent::file_storage::flag_pad_file)?'p':'-')
            , ((flags & libtorrent::file_storage::flag_executable)?'x':'-')
            , ((flags & libtorrent::file_storage::flag_hidden)?'h':'-')
            , ((flags & libtorrent::file_storage::flag_symlink)?'l':'-')
            , first, last
            , boost::uint32_t(st.mtime(i))
            , st.hash(i) != libtorrent::sha1_hash(0) ? libtorrent::to_hex(st.hash(i).to_string()).c_str() : ""
            , st.file_path(i).c_str()
            , (flags & libtorrent::file_storage::flag_symlink) ? "-> " : ""
            , (flags & libtorrent::file_storage::flag_symlink) ? st.symlink(i).c_str() : "");
    }
}