#include <iostream>
#include <string>

using namespace std;

extern "C" {
    #include "ffmpeg_mediametadataretriever.h"
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    State *state = NULL;
    string path("/Users/biezhihua/Downloads/fushanxing.rmvb");

    av_register_all();
    avformat_network_init();


    set_data_source_uri(&state, path.c_str(), NULL);

    AVPacket packet;
    av_init_packet(&packet);
    if (get_frame_at_time(&state, 100000 * 11111, 0, &packet)) {
        int size = packet.size;
        uint8_t *data = packet.data;

    }
    av_packet_unref(&packet);
    return 0;
}