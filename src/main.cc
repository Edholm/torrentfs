#include "torrent.h"

int main(int argc, char const* argv[])
{
    Torrent t("archlinux.torrent");
    t.print_info();

    return 0;
}
